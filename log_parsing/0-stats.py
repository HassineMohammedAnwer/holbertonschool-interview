#!/usr/bin/python3
"""
lkjml
"""
import sys


i = 0
FileSize = 0
STATUS = {'200': 0, '301': 0,
          '400': 0, '401': 0,
          '403': 0, '404': 0,
          '405': 0, '500': 0}
try:
    for line in sys.stdin:
        i += 1
        sp = line.split(' ')
        if len(sp) > 2:
            FileSize += int(sp[-1])
            if sp[-2] in STATUS:
                STATUS[sp[-2]] += 1
        if i % 10 == 0:
            print("File size: {}".format(FileSize))
            for key, value in sorted(STATUS.items()):
                if value != 0:
                    print("{}: {}".format(key, value))
finally:
    print("File size: {}".format(FileSize))
    for key, value in sorted(STATUS.items()):
            if value != 0:
                print("{}: {:d}".format(key, value))
