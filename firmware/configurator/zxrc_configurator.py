#!/bin/env python3

import serial

ser = serial.Serial()

ser.baudrate = 115200
ser.port = '/dev/ttyUSB0'
ser.bytesize = 8
ser.parity = 'N'
ser.stopbits = 1
ser.timeout = 1
ser.xonxoff = 0
ser.rtscts = 0

ser.open()
ser.write(b'hello\r\n')
s = ser.read(6)
ser.close()
print(s)
