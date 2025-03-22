#!/usr/bin/python3
"""
azedal;ae
"""
import sys


def main():
    count = 0
    s = 0
    STATUS = {'200': 0, '301': 0,
              '400': 0, '401': 0,
              '403': 0, '404': 0,
              '405': 0, '500': 0}
    try:
        for line in sys.stdin:
            count += 1
            tmp = line.split(' ')
            if len(tmp) > 2:
                s += int(tmp[-1])
                if tmp[-2] in STATUS:
                    STATUS[tmp[-2]] += 1
            if count % 10 == 0:
                print("File size: {}".format(s))
                for key, value in sorted(STATUS.items()):
                    if value != 0:
                        print("{}: {}".format(key, value))
    finally:
        print("File size: {}".format(s))
        for key, value in sorted(STATUS.items()):
                if value != 0:
                    print("{}: {:d}".format(key, value))

if __name__ == "__main__":
    main()
