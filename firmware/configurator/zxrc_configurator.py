#!/bin/env python3
#
# Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
#

import sys
from SerialPortFinder import find_serial_ports
from EasySerial import EasyPort

ports = find_serial_ports()
if len(ports) == 0:
    sys.exit('Serial ports not found!')

j = 0
for i in ports:
    print('{0} - {1}'.format(i, j))
    j = j + 1

sel = input('Select port number: ')
sel = int(sel)
if (sel < 0) or (sel >= len(ports)):
    sys.exit('Error of selecting port!')

print('{0}: {1}'.format('Selected', ports[sel]))
ep = EasyPort(ports[sel])
ep.open()

tz = input("TimeZone: ")
ep.write(tz.encode())
ep.write(b'\r')

ap = input("AccessPoint: ")
ep.write(ap.encode())
ep.write(b'\r')

pas = input("Password: ")
ep.write(pas.encode())
ep.write(b'\r')

s = ep.read()
print(s)

ep.close()
