from flask import Flask, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

@app.route('/api/temperature', methods=['GET'])
def get_temperature():
    temperature = 22  # Room temperature in Celsius
    return jsonify({'temperature': temperature})

if __name__ == '__main__':
    app.run(debug=True)
