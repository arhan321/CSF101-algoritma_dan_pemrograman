from flask import Flask, jsonify, request
import mysql.connector
from flasgger import Swagger, swag_from
from collections import OrderedDict
import os

app = Flask(__name__)

# --- Swagger Configuration ---
app.config['SWAGGER'] = {
    'title': 'Mahasiswa API',
    'uiversion': 3
}
swagger = Swagger(app)

# --- Database Config ---
db_config = {
    "host": "db_python",
    "user": "root",
    "password": "123",
    "database": "mahasiswa"
}

API_TOKEN = "SECRET123"


# --- Token Auth Middleware ---
def token_required(f):
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


# --- Inisialisasi Database ---
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


# ========================= ROUTES =========================

@app.route('/')
def home():
    """Home Endpoint
    ---
    responses:
      200:
        description: Flask API is running
    """
    return jsonify({"message": "Flask API is running!"})


@app.route('/users', methods=['GET'])
@token_required
@swag_from({
    'tags': ['Users'],
    'description': 'Get all users from database',
    'responses': {
        200: {
            'description': 'List of all users',
            'examples': {
                'application/json': [
                    {"id": 1, "name": "ARHAN", "email": "arhan@gmail.com"}
                ]
            }
        }
    }
})
def get_users():
    conn = mysql.connector.connect(**db_config)
    cursor = conn.cursor(dictionary=True)
    cursor.execute("SELECT id, name, email FROM users ORDER BY id ASC")
    users = cursor.fetchall()
    cursor.close()
    conn.close()

    ordered_users = [
        OrderedDict([
            ("id", u["id"]),
            ("name", u["name"]),
            ("email", u["email"])
        ])
        for u in users
    ]
    return jsonify(ordered_users)


@app.route('/users', methods=['POST'])
@token_required
@swag_from({
    'tags': ['Users'],
    'description': 'Add a new user',
    'parameters': [
        {
            'name': 'body',
            'in': 'body',
            'required': True,
            'schema': {
                'type': 'object',
                'properties': {
                    'name': {'type': 'string'},
                    'email': {'type': 'string'}
                },
                'example': {'name': 'ARHAN', 'email': 'arhan@example.com'}
            }
        }
    ],
    'responses': {
        201: {'description': 'User added successfully'},
        400: {'description': 'Invalid input'}
    }
})
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


@app.route('/users/<int:user_id>', methods=['GET'])
@token_required
@swag_from({
    'tags': ['Users'],
    'description': 'Get a specific user by ID',
    'parameters': [
        {'name': 'user_id', 'in': 'path', 'type': 'integer', 'required': True}
    ],
    'responses': {
        200: {'description': 'User found'},
        404: {'description': 'User not found'}
    }
})
def get_user(user_id):
    conn = mysql.connector.connect(**db_config)
    cursor = conn.cursor(dictionary=True)
    cursor.execute("SELECT id, name, email FROM users WHERE id = %s", (user_id,))
    user = cursor.fetchone()
    cursor.close()
    conn.close()

    if user:
        return jsonify(user)
    else:
        return jsonify({"error": "User not found"}), 404


@app.route('/users/<int:user_id>', methods=['PUT'])
@token_required
@swag_from({
    'tags': ['Users'],
    'description': 'Update an existing user',
    'parameters': [
        {'name': 'user_id', 'in': 'path', 'type': 'integer', 'required': True},
        {
            'name': 'body',
            'in': 'body',
            'required': True,
            'schema': {
                'type': 'object',
                'properties': {
                    'name': {'type': 'string'},
                    'email': {'type': 'string'}
                },
                'example': {'name': 'New Name', 'email': 'new@email.com'}
            }
        }
    ]
})
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


@app.route('/users/<int:user_id>', methods=['DELETE'])
@token_required
@swag_from({
    'tags': ['Users'],
    'description': 'Delete a user by ID',
    'parameters': [{'name': 'user_id', 'in': 'path', 'type': 'integer', 'required': True}],
    'responses': {
        200: {'description': 'User deleted successfully'},
        404: {'description': 'User not found'}
    }
})
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
    init_db()
    app.run(host='0.0.0.0', port=5000)
