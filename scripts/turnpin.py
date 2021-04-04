


import RPi.GPIO as GPIO
import sys

pins = sys.argv




def powerPin(pin):
	for i in range(len(pins)-1):
		p = i+1
		GPIO.setmode(GPIO.BCM)
		GPIO.setup(pins[p],GPIO.OUT)
		GPIO.output(pin[p],GPIO.HIGH)

try:
	powerPin(pins)
except:
	GPIO.cleanup()
