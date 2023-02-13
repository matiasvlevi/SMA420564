# SMA420564 ATmega2560 Library

Display Hex, Decimal and Binary values on a 7 segment 4 digit display, using 12 pins.


## I/O Config

Writes directly to ports, defaults are `PORTA` and `PORTC` on the ATmega2560
These ports can be changed in the header file. 


<table align="center">
<tr>
<td align="center"> I/O Config </td> <td align="center"> SMA420564 </td>
</tr>
<tr>
<td>

<table>
    <tr>
        <td>ATmega2560</td>
        <td>Arduino Mega</td>
        <td>SMA42060</td>
        <td>Label</td>
    </tr>
    <tr>
        <td>PC0</td>
        <td>37</td>
        <td>2</td>
        <td>dp</td>
    </tr>
    <tr>
        <td>PC1</td>
        <td>36</td>
        <td>4</td>
        <td>g</td>
    </tr>
    <tr>
        <td>PC2</td>
        <td>35</td>
        <td>9</td>
        <td>f</td>
    </tr>
    <tr>
        <td>PC3</td>
        <td>34</td>
        <td>0</td>
        <td>e</td>
    </tr>
    <tr>
        <td>PC4</td>
        <td>33</td>
        <td>1</td>
        <td>d</td>
    </tr>
    <tr>
        <td>PC5</td>
        <td>32</td>
        <td>3</td>
        <td>c</td>
    </tr>
    <tr>
        <td>PC6</td>
        <td>31</td>
        <td>6</td>
        <td>b</td>
    </tr>
    <tr>
        <td>PC7</td>
        <td>30</td>
        <td>10</td>
        <td>a</td>
    </tr>
    <tr>
        <td>PA0</td>
        <td>22</td>
        <td>5</td>
        <td>S4</td>
    </tr>
    <tr>
        <td>PA1</td>
        <td>23</td>
        <td>7</td>
        <td>S3</td>
    </tr>
    <tr>
        <td>PA2</td>
        <td>24</td>
        <td>8</td>
        <td>S2</td>
    </tr>
    <tr>
        <td>PA3</td>
        <td>25</td>
        <td>11</td>
        <td>S1</td>
    </tr>
</table>

</td>
<td>

<img src="https://i.ibb.co/K5pptYQ/SMA420564.png" width="480"></img>

</td>
</tr>

</table>

<br/>

### Library Usage



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
    
    // Decimal values:
    //      Display.write(  9999, DEC);
    
    // Binary:
    //      Display.write(0b1010, BIN);
    
    // Hexadecimal values:
    //      Display.write(0xBEEF, HEX);
    //      Display.write(0xCAFE, HEX);

    // Enable display point, index ranges from 0 to 3
    //      Display.point(2);

    // Set display points in parrallel
    //      Display.set_points(0b0101);


    // Write raw data to ports:
    // you can refer to the static array `digits` which holds the raw bytes for the 16 symbols
    //      Display.write(0xFFFFFFFF, DEC, RAW); 
}


```

<br/>

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
