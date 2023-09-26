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
    """
        Handle Ctrl + C
    """
    print_stats()


def print_stats():
    """
        Print the stats each 10 lines
    """
    print(f"File size: {size}")
    for k,v in status_code.items():
        if (v != 0):
            print(f"{k}: {v}")


def parse_log():
    """
        Parse log
    """
    signal.signal(signal.SIGINT, signal_handler)
    for line in sys.stdin:
        line_split = line.split()
        if (len(line_split) != 9):
            continue
        count += 1
        size += int(line_split[8])
        status_code[line_split[7]] += 1

        if (count % 10 == 0):
            print_stats()


if __name__ == "__main__":
    parse_log()
