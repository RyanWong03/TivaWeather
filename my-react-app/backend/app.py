from flask import Flask, jsonify
from flask_cors import CORS
import serial, time

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes

previous_temperature = None

@app.route('/api/temperature', methods=['GET'])
def get_temperature():
    tiva = serial.Serial('COM15', 115200, timeout=1)
    time.sleep(2)
    temperature = tiva.readline()
    temperature = temperature.decode('utf-8').strip()
    tiva.close()

    if previous_temperature is not None:
        if temperature == ' ':
            return jsonify({'temperature': previous_temperature})

    return jsonify({'temperature': temperature})

@app.route('/api/turnOnFan', methods=['POST'])
def turn_on_fan():
    tiva = serial.Serial('COM15', 115200, timeout=1)
    time.sleep(2)   # Give time for the connection to be established
    message = '1'   # Command to turn on the fan
    tiva.write(message.encode())
    tiva.close()  # Close the serial connection

    return jsonify({'message': 'Fan turned on successfully'}), 200

if __name__ == '__main__':
    
    app.run(debug=True)
