# SMA420564 ATmega2560 Driver

Writes directly to ports, defaults are `PORTA` and `PORTC` on the ATmega2560
These ports can be changed in the header file. 

Library is located in `src/SMA420564.h`

### Usage

```cpp
#include "SMA420564.h"

SMA420564 Display;

void setup(void) 
{
    /* ... code ... */
}

void loop(void)
{
    Display.write(1234);
    
    // Display.write(  9999, DEC);
    // Display.write(0b1010, BIN);
    // Display.write(0xBEEF, HEX);
    // Display.write(0xCAFE, HEX);

    // Enable display point, index ranges from 0 to 3
    //  Display.point(2);

    // Set display points in parrallel
    //  Display.set_points(0b0101);


    // Write raw data to ports:
    // you can refer to the static array `digits` which holds the raw bytes for the 16 symbols
    //  Display.write(0xFFFFFFFF, DEC, RAW); 
}


```




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
