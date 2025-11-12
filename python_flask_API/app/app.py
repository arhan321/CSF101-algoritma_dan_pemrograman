from flask import Flask, jsonify, request
import mysql.connector
import pandas as pd
import os

app = Flask(__name__)

# Konfigurasi database (pakai koneksi dari docker-compose)
db_config = {
    "host": "db_python",
    "user": "root",
    "password": "123",
    "database": "mahasiswa"
}

# ====== KONFIGURASI TOKEN ======
API_TOKEN = "SECRET123"  

def token_required(f):
    """Middleware untuk validasi Bearer Token"""
    def decorator(*args, **kwargs):
        auth_header = request.headers.get('Authorization')
        if not auth_header or not auth_header.startswith("Bearer "):
            return jsonify({"error": "Authorization header missing or invalid"}), 401

        token = auth_header.split(" ")[1]
        if token != API_TOKEN:
            return jsonify({"error": "Invalid or expired token"}), 403

        return f(*args, **kwargs)
    decorator.__name__ = f.__name__
    return decorator


# ====== INIT DATABASE (CREATE TABLE kalau belum ada) ======
def init_db():
    conn = mysql.connector.connect(**db_config)
    cursor = conn.cursor()
    cursor.execute("""
        CREATE TABLE IF NOT EXISTS users (
            id INT AUTO_INCREMENT PRIMARY KEY,
            name VARCHAR(100),
            email VARCHAR(100)
        )
    """)
    conn.commit()
    cursor.close()
    conn.close()


# ====== ROUTES ======

@app.route('/')
def home():
    return jsonify({"message": "Flask API is running!"})

# ---------- CREATE ----------
@app.route('/users', methods=['POST'])
@token_required
def add_user():
    data = request.get_json()
    name = data.get("name")
    email = data.get("email")

    if not name or not email:
        return jsonify({"error": "Name and email are required"}), 400

    conn = mysql.connector.connect(**db_config)
    cursor = conn.cursor()
    cursor.execute("INSERT INTO users (name, email) VALUES (%s, %s)", (name, email))
    conn.commit()
    cursor.close()
    conn.close()

    return jsonify({"message": "User added successfully"}), 201


# ---------- READ ALL ----------
@app.route('/users', methods=['GET'])
@token_required
def get_users():
    conn = mysql.connector.connect(**db_config)
    df = pd.read_sql("SELECT * FROM users", conn)
    conn.close()

    if 'id' in df.columns:
        cols = ['id'] + [col for col in df.columns if col != 'id']
        df = df[cols]

    return jsonify(df.to_dict(orient='records'))


# ---------- READ ONE ----------
@app.route('/users/<int:user_id>', methods=['GET'])
@token_required
def get_user(user_id):
    conn = mysql.connector.connect(**db_config)
    cursor = conn.cursor(dictionary=True)
    cursor.execute("SELECT * FROM users WHERE id = %s", (user_id,))
    user = cursor.fetchone()
    cursor.close()
    conn.close()

    if user:
        return jsonify(user)
    else:
        return jsonify({"error": "User not found"}), 404


# ---------- UPDATE ----------
@app.route('/users/<int:user_id>', methods=['PUT'])
@token_required
def update_user(user_id):
    data = request.get_json()
    name = data.get("name")
    email = data.get("email")

    conn = mysql.connector.connect(**db_config)
    cursor = conn.cursor()
    cursor.execute("UPDATE users SET name=%s, email=%s WHERE id=%s", (name, email, user_id))
    conn.commit()
    updated_rows = cursor.rowcount
    cursor.close()
    conn.close()

    if updated_rows == 0:
        return jsonify({"error": "User not found"}), 404

    return jsonify({"message": "User updated successfully"})


# ---------- DELETE ----------
@app.route('/users/<int:user_id>', methods=['DELETE'])
@token_required
def delete_user(user_id):
    conn = mysql.connector.connect(**db_config)
    cursor = conn.cursor()
    cursor.execute("DELETE FROM users WHERE id=%s", (user_id,))
    conn.commit()
    deleted_rows = cursor.rowcount
    cursor.close()
    conn.close()

    if deleted_rows == 0:
        return jsonify({"error": "User not found"}), 404

    return jsonify({"message": "User deleted successfully"})


if __name__ == '__main__':
    init_db()  # pastikan tabel ada dulu
    app.run(host='0.0.0.0', port=5000)
