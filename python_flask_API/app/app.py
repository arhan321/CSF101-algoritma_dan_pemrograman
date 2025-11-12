from flask import Flask, jsonify, request
import mysql.connector
from flasgger import Swagger, swag_from
from collections import OrderedDict
import os

app = Flask(__name__)

# ====== CONFIG ======
API_TOKEN = os.getenv("API_TOKEN", "SECRET123")
db_config = {
    "host": "db_python",
    "user": "root",
    "password": "123",
    "database": "mahasiswa",
}

# ====== SWAGGER TEMPLATE (Authorize button for Bearer Token) ======
swagger_template = {
    "swagger": "2.0",
    "info": {
        "title": "Mahasiswa API",
        "version": "0.0.1",
        "description": "CRUD Mahasiswa dengan Bearer Token Authorization",
    },
    "securityDefinitions": {
        "BearerAuth": {
            "type": "apiKey",
            "name": "Authorization",
            "in": "header",
            "description": "Masukkan token seperti ini: **Bearer SECRET123**",
        }
    },
    "tags": [{"name": "Mahasiswa", "description": "CRUD Data Mahasiswa"}],
    "security": [{"BearerAuth": []}],  # otomatis untuk semua endpoint
}

# ====== SWAGGER CONFIG ======
swagger_config = {
    "headers": [],
    "specs": [
        {
            "endpoint": "apispec_1",
            "route": "/apispec_1.json",
            "rule_filter": lambda rule: True,   # tampilkan semua endpoint
            "model_filter": lambda tag: True,   # semua tag
        }
    ],
    "static_url_path": "/flasgger_static",
    "swagger_ui": True,
    "specs_route": "/apidocs/",
    "uiversion": 3,
}



# ====== TOKEN MIDDLEWARE ======
def token_required(f):
    def decorator(*args, **kwargs):
        auth = request.headers.get("Authorization", "")
        if not auth.startswith("Bearer "):
            return jsonify({"error": "Authorization header missing or invalid"}), 401
        token = auth.split(" ", 1)[1].strip()
        if token != API_TOKEN:
            return jsonify({"error": "Invalid or expired token"}), 403
        return f(*args, **kwargs)
    decorator.__name__ = f.__name__
    return decorator

# ====== INIT DATABASE ======
def init_db():
    conn = mysql.connector.connect(**db_config)
    cur = conn.cursor()
    cur.execute(
        """
        CREATE TABLE IF NOT EXISTS users (
            id INT AUTO_INCREMENT PRIMARY KEY,
            name VARCHAR(100),
            email VARCHAR(100)
        )
        """
    )
    conn.commit()
    cur.close()
    conn.close()

# ========================= ROUTES =========================
@app.route("/")
def home():
    """Home Endpoint
    ---
    tags:
      - Mahasiswa
    responses:
      200:
        description: API status
    """
    return jsonify({"message": "Flask API is running!"})


@app.route("/users", methods=["GET"])
@token_required
@swag_from({
    "tags": ["Mahasiswa"],
    "description": "Ambil semua data mahasiswa",
    "responses": {
        200: {
            "description": "Daftar mahasiswa",
            "examples": {
                "application/json": [
                    {"id": 1, "name": "ARHAN", "email": "arhan@gmail.com"}
                ]
            },
        }
    },
})
def get_users():
    conn = mysql.connector.connect(**db_config)
    cur = conn.cursor(dictionary=True)
    cur.execute("SELECT id, name, email FROM users ORDER BY id ASC")
    rows = cur.fetchall()
    cur.close()
    conn.close()

    data = [OrderedDict([("id", r["id"]), ("name", r["name"]), ("email", r["email"])]) for r in rows]
    return jsonify(data)


@app.route("/users", methods=["POST"])
@token_required
@swag_from({
    "tags": ["Mahasiswa"],
    "description": "Tambah data mahasiswa baru",
    "parameters": [{
        "name": "body",
        "in": "body",
        "required": True,
        "schema": {
            "type": "object",
            "required": ["name", "email"],
            "properties": {
                "name": {"type": "string"},
                "email": {"type": "string"},
            },
            "example": {"name": "ARHAN", "email": "arhan@example.com"},
        },
    }],
    "responses": {
        201: {"description": "Berhasil menambah mahasiswa"},
        400: {"description": "Input tidak valid"},
    },
})
def add_user():
    data = request.get_json(silent=True) or {}
    name, email = data.get("name"), data.get("email")

    if not name or not email:
        return jsonify({"error": "Name and email are required"}), 400

    conn = mysql.connector.connect(**db_config)
    cur = conn.cursor()
    cur.execute("INSERT INTO users (name, email) VALUES (%s, %s)", (name, email))
    conn.commit()
    cur.close()
    conn.close()

    return jsonify({"message": "User added successfully"}), 201


@app.route("/users/<int:user_id>", methods=["GET"])
@token_required
@swag_from({
    "tags": ["Mahasiswa"],
    "description": "Ambil data mahasiswa berdasarkan ID",
    "parameters": [
        {"name": "user_id", "in": "path", "type": "integer", "required": True},
    ],
    "responses": {
        200: {"description": "Data ditemukan"},
        404: {"description": "Tidak ditemukan"},
    },
})
def get_user(user_id: int):
    conn = mysql.connector.connect(**db_config)
    cur = conn.cursor(dictionary=True)
    cur.execute("SELECT id, name, email FROM users WHERE id=%s", (user_id,))
    row = cur.fetchone()
    cur.close()
    conn.close()

    if not row:
        return jsonify({"error": "User not found"}), 404

    return jsonify(OrderedDict([("id", row["id"]), ("name", row["name"]), ("email", row["email"])]))


@app.route("/users/<int:user_id>", methods=["PUT"])
@token_required
@swag_from({
    "tags": ["Mahasiswa"],
    "description": "Update data mahasiswa",
    "parameters": [
        {"name": "user_id", "in": "path", "type": "integer", "required": True},
        {
            "name": "body",
            "in": "body",
            "required": True,
            "schema": {
                "type": "object",
                "properties": {
                    "name": {"type": "string"},
                    "email": {"type": "string"},
                },
                "example": {"name": "Nama Baru", "email": "baru@email.com"},
            },
        },
    ],
    "responses": {
        200: {"description": "Data berhasil diupdate"},
        404: {"description": "Mahasiswa tidak ditemukan"},
    },
})
def update_user(user_id: int):
    data = request.get_json(silent=True) or {}
    name, email = data.get("name"), data.get("email")

    conn = mysql.connector.connect(**db_config)
    cur = conn.cursor()
    cur.execute("UPDATE users SET name=%s, email=%s WHERE id=%s", (name, email, user_id))
    conn.commit()
    updated = cur.rowcount
    cur.close()
    conn.close()

    if updated == 0:
        return jsonify({"error": "User not found"}), 404

    return jsonify({"message": "User updated successfully"})


@app.route("/users/<int:user_id>", methods=["DELETE"])
@token_required
@swag_from({
    "tags": ["Mahasiswa"],
    "description": "Hapus data mahasiswa",
    "parameters": [
        {"name": "user_id", "in": "path", "type": "integer", "required": True},
    ],
    "responses": {
        200: {"description": "Data berhasil dihapus"},
        404: {"description": "Mahasiswa tidak ditemukan"},
    },
})
def delete_user(user_id: int):
    conn = mysql.connector.connect(**db_config)
    cur = conn.cursor()
    cur.execute("DELETE FROM users WHERE id=%s", (user_id,))
    conn.commit()
    deleted = cur.rowcount
    cur.close()
    conn.close()

    if deleted == 0:
        return jsonify({"error": "User not found"}), 404

    return jsonify({"message": "User deleted successfully"})

swagger = Swagger(app, template=swagger_template, config=swagger_config)
if __name__ == "__main__":
    init_db()
    app.run(host="0.0.0.0", port=5000)
