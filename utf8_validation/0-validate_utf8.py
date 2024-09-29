#!/usr/bin/python3
"""
Main f
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data (List[int]): A list of integers representing bytes of data.

    Returns:
        True if data is a valid UTF-8 encoding, else False.
    """
    num_bytes = 0

    for num in data:
        if num_bytes == 0:
            if (num >> 5) == 0b110:
                num_bytes = 2
            elif (num >> 4) == 0b1110:
                num_bytes = 3
            elif (num >> 3) == 0b11110:
                num_bytes = 4

            elif (num >> 7) != 0:
                return False

        else:
            if (num >> 6) != 0b10:
                return False
            num_bytes -= 1

    if num_bytes != 0:
        return False

    return True
