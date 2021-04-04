import RPi.GPIO as g
import sys
import time

pin = []

pinConfigFile = open("pinConfig.txt")

def parse(arr):
	conf = []
	for i in range(len(arr)):
		conf.append(arr[i].strip())
	
	return conf

def getPin(str):
	strarr = str.split(":")
	if strarr[0] != 'Null':
		gpio = int(strarr[0])
	else:
		gpio = strarr[0]

	disp = int(strarr[1])
	return gpio

def getGND(place):
	p = 0

	if place == 1:
		p = 0
	elif place == 2:
		p = 3
	elif place == 3:
		p = 4
	elif place == 4:
		p = 11
	else:
		return None

	return p

def setpins(conf):
	pinarr = []
	for i in range(12):
		pinarr.append(getPin(conf[i]))

	return pinarr

def pin_(num):
	g.setup(pin[num],g.OUT)
	g.output(pin[num],g.HIGH)
	

pinConfig = parse(pinConfigFile.readlines())
pin = setpins(pinConfig)
print(pin)

def setup():
	for i in range(len(pin)):
		if pin[i] != 'Null':
			#print(pin[i])
			g.setup(pin[i],g.OUT)
			#g.cleanup(pin[i])
		else:
			print("null")



def display(digit,place):
	gnd = pin[getGND(place)]
	g.setmode(g.BCM)
	g.setup(gnd,g.OUT)
	g.output(gnd,g.LOW)
	if (digit == 0 or digit == 2 or digit == 3 or digit == 5 or digit == 6 or digit == 7 or digit == 8 or digit == 9):
		pin_(1)
	
	#time.sleep(t)
	if (digit == 0 or digit == 4 or digit == 5 or digit == 6 or digit == 8 or digit == 9):
		pin_(2)

	#time.sleep(t)
	if (digit == 0 or digit == 1 or digit == 2 or digit == 3 or digit == 4 or digit == 7 or digit == 8 or digit == 9):
		pin_(5)

	#time.sleep(t)
	if (digit == 0 or digit == 2 or digit == 6 or digit == 8):
		pin_(6)

	#time.sleep(t)
	if (digit == 0 or digit == 2 or digit == 3 or digit == 5 or digit == 6 or digit == 8):
		pin_(7)

	#time.sleep(t)
	if (digit == 0 or digit == 1 or digit == 3 or digit == 4 or digit == 5 or digit == 6 or digit == 7 or digit == 8 or digit == 9):
		pin_(9)

	#time.sleep(t)
	if (digit == 2 or digit == 3 or digit == 4 or digit == 5 or digit == 6 or digit == 8 or digit == 9):
		pin_(10)
	
	#time.sleep(t)
	#g.cleanup()

def write(value):
	str_ = str(value)
	arr = [char for char in str_]
	t = 0.001
	display(int(arr[0]),1)
	time.sleep(t)
	g.cleanup()
	display(int(arr[1]),2)
	time.sleep(t)
	g.cleanup()
	display(int(arr[2]),3)
	time.sleep(t)
	g.cleanup()
	display(int(arr[3]),4)	
	time.sleep(t)
	g.cleanup()




value = 8888

if len(sys.argv) > 1:
	value = sys.argv[1]
else:
	pass;

t = 10
if len(sys.argv) > 2:
	t = float(sys.argv[2])/0.004
else:
	pass

x = 0
while (x < t):
	write(value)
	x+=1
else:
	pass

