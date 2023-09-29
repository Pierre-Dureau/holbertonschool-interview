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
	print_stats()


def print_stats():
	"""Print the stats obtained from the file"""
	print("File size: {}".format(size))
	for k, v in sorted(status_code.items()):
		if (v != 0):
			print("{:s}: {:d}".format(k, v))


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
print_stats()
