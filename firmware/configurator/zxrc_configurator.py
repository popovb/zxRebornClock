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

tz = input("TimeZone: ")
ser.write(tz.encode())
ser.write(b'\r')
s = ser.read(128)
print(s)

ap = input("AcessPoint: ")
ser.write(ap.encode())
ser.write(b'\r')
s = ser.read(128)
print(s)

pas = input("Password: ")
ser.write(pas.encode())
ser.write(b'\r')
s = ser.read(128)
print(s)

ser.close()
