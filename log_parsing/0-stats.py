#!/usr/bin/python3
"""
lkjml
"""
import sys


def print_metrics(metrics, file_size):
    """dlijrfzdcij"""
    codes = [200, 301, 400, 401, 403, 404, 405, 500]
    print("File size: {}" .format(file_size))
    for code in range(len(codes)):
        if status_codes[codes[code]] > 0:
            print("{}: {}".format(codes[code], status_codes[codes[code]]))

# zedze
file_size = 0
line_count = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

# zdczdùm
try:
    for line in sys.stdin:
        try:
            line_count += 1
            arguments = line.split
            file_size = int(arguments[-1])
            http_code = int(arguments[-2])
            status_codes[http_code] += 1
            if line_count == 10:
                print_metrics(status_codes, file_size)
                line_count = 0
        except Exception:
            continue
except Exception:
    pass
finally:
    print_metrics(status_codes, file_size)
