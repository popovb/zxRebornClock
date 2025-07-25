#
# Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
#

import os
import platform

def find_serial_linux():
    ports = []
    files = os.listdir('{0}dev'.format(os.path.sep))
    for i in files:
        if 'ttyUSB' in i:
            ports.append(i)

        if 'ttyACM' in i:
            ports.append(i)

        if 'arduino' in i:
            ports.append(i)

    ports = [
        '{0}dev{0}{1}'.format(os.path.sep, i) for i in ports
    ]
    return ports

def find_serial_mac():
    ports = []
    files = os.listdir('{0}dev'.format(os.path.sep))
    for i in files:
        if 'tty.' in i:
            ports.append(i)

        if 'cu.' in i:
            ports.append(i)

    ports = [
        '{0}dev{0}{1}'.format(os.path.sep, i) for i in ports
    ]
    return ports

def find_serial_win():
    ports = []

    try:
        import winreg
    except ImportError:
        import _winreg as winreg
    import itertools

    path = 'HARDWARE\\DEVICEMAP\\SERIALCOMM'
    try:
        key = winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, path)
    except WindowsError:
        key = None

    if key is not None:
        for i in itertools.count():
            try:
                val = winreg.EnumValue(key, i)
                # Only return USBSER devices
                if 'USBSER' in val[0]:
                    ports.append(str(val[1]))
            except EnvironmentError:
                break
    return ports

def find_serial_ports():
    '''
    Returns a list of all available serial ports
    '''
    serial_ports = []

    os_type = platform.system()
    if os_type == 'Linux':
        serial_ports = find_serial_linux()

    elif os_type == 'Windows':
        serial_ports = find_serial_win()

    elif os_type == 'Darwin':
        serial_ports = find_serial_mac()

    serial_ports.sort()
    return serial_ports
