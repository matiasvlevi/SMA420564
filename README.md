# SMA420564 ATmega2560 Driver

Writes directly to ports, defaults are `PORTA` and `PORTC` on the ATmega2560
These ports can be changed in the header file. 

Library is located in `src/SMA420564.h`

## Clone this example:
```
git clone https://github.com/matiasvlevi/SMA420560.git ./playground
```

### arduino-cli build

You can build with `make` which wraps the `arduino-cli` 

Build:
```
make
```

Upload:
```
make upload
```

<br/>

### arduino-ide build

Open the cloned directory with `arduino-ide`
Make sure the directory is named the same as the `.ino` file
