#!/usr/bin/python3
import sys
"""ijmlj"""


def print_stats(total_size, status_codes):
    """dlijrfij"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))

total_size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

try:
    for line in sys.stdin:
        try:
            split_line = line.split()
            file_size = int(split_line[-1])
            status_code = int(split_line[-2])
            if status_code in status_codes:
                status_codes[status_code] += 1
                total_size += file_size
                line_count += 1
        except:
            pass

        if line_count == 10:
            print_stats(total_size, status_codes)
            line_count = 0

    print_stats(total_size, status_codes)
except KeyboardInterrupt:
    print_stats(total_size, status_codes)
