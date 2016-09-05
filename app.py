# -*- coding: utf-8 -*-

from flask import Flask, render_template
import serial

app = Flask(__name__)

ser_interface = serial.Serial('/dev/ttyACM0', 9600)


@app.route('/')
def main():
    return render_template("main.html")


@app.route('/move/<thinger>', methods=['GET'])
def move_hand(thinger):
    ser_interface.write(bytes(thinger))
    return render_template("main.html")

if __name__ == '__main__':
    app.run(debug=True, host="0.0.0.0", port=5000)
