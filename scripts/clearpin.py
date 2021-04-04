import RPi.GPIO as g
import sys

pin = 17
if len(sys.argv) > 1:
	pin = sys.argv[1]
g.setmode(g.BCM)
g.setup(pin,g.OUT)
g.cleanup(pin)
