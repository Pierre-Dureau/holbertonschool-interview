#!/usr/bin/python3
"""
Module that reads stdin line by line and computes metrics
"""
import sys
import signal


status_code = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
count = 0
size = 0


def signal_handler(sig, frame):
    """Handle when CTRL + C is pressed"""
    print_infos()


def print_infos():
    """Prints the stats obtained from the file"""
    print("File size: {}".format(size))
    for key, value in sorted(status_code.items()):
        if value != 0:
            print("{:s}: {:d}".format(key, value))


signal.signal(signal.SIGINT, signal_handler)
for line in sys.stdin:
    count += 1
    line_parsed = line.split()
    length_line = len(line_parsed)
    if length_line < 2:
        continue
    size += int(line_parsed[length_line - 1])
    if line_parsed[length_line - 2] not in status_code.keys():
        continue
    status_code[line_parsed[length_line - 2]] += 1
    if count % 10 == 0:
        print_infos()
print_infos()
