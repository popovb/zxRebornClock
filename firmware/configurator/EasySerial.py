#
# Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
#

import serial

class EasyPort:
    def __init__(self, name):
        self.serial = serial.Serial()
        self.serial.baudrate = 115200
        self.serial.port = name
        self.serial.bytesize = 8
        self.serial.parity = 'N'
        self.serial.stopbits = 1
        self.serial.timeout = 1
        self.serial.xonxoff = 0
        self.serial.rtscts = 0

    def open(self):
        self.serial.open()

    def close(self):
        self.serial.close()

    def write(self, str):
        self.serial.write(str)

    def read(self):
        return self.serial.read(256)
