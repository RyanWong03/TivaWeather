from flask import Flask, jsonify
from flask_cors import CORS
import serial, time

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

@app.route('/api/temperature', methods=['GET'])
def get_temperature():
    temperature = 22  # Room temperature in Celsius
    return jsonify({'temperature': temperature})

@app.route('/api/turnOnFan', methods=['POST'])
def turn_on_fan():
    tiva = serial.Serial('COM3', 115200, timeout=1)
    time.sleep(2)   # Give time for the connection to be established
    message = '1'   # Command to turn on the fan
    tiva.write(message.encode())
    tiva.close()  # Close the serial connection

    return jsonify({'message': 'Fan turned on successfully'}), 200

if __name__ == '__main__':
    app.run(debug=True)
