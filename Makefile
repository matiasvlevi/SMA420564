SERIAL_PORT=/dev/ttyACM0
BOARD=arduino:avr:mega
SDK=arduino-cli

build:
	$(SDK) compile -b $(BOARD)

upload:
	$(SDK) upload -p $(SERIAL_PORT) -b $(BOARD) ./


