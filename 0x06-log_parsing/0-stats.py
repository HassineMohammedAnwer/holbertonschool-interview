#!/usr/bin/python3
import sys

# Define a dictionary to store the number of lines by status code
status_codes = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}

# Define a variable to store the total file size
total_size = 0

# Define a variable to count the number of lines processed
line_count = 0

# Loop through each line of the input
try:
    for line in sys.stdin:
        line_count += 1
        parts = line.split()
        # Skip lines that do not match the expected format
        if len(parts) != 9:
            continue
        # Extract the status code and file size from the line
        status = int(parts[7])
        size = int(parts[8])
        # Increment the number of lines for the current status code
        if status in status_codes:
            status_codes[status] += 1
        # Add the file size to the total
        total_size += size
        # Print the metrics every 10 lines or on keyboard interrupt
        if line_count % 10 == 0:
            print("File size: {}".format(total_size))
            for status_code in sorted(status_codes.keys()):
                if status_codes[status_code] > 0:
                    print("{}: {}".format(
                                   status_code, status_codes[status_code]))
except KeyboardInterrupt:
    print("File size: {}".format(total_size))
    for status_code in sorted(status_codes.keys()):
        if status_codes[status_code] > 0:
            print("{}: {}".format(status_code, status_codes[status_code]))
