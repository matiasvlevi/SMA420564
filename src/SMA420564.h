#ifndef SMA420564_DISPLAY_H
#define SMA420564_DISPLAY_H

/**
*   
*   PORT_DIGIT_SELECT - Determines Digit position on Display       
*
*   Used bits: (0x0F, 4bits, bit 0 to 3)
**/
#define DDR_PINS          DDRC
#define PORT_DIGIT_PINS   PORTC

/**
*
*   PORT_DIGIT_PINS - Determines Segments to turn on
*   
*   Used bits: (0xFF, 8bits, bit 0 to 7)
*
*   MSB 0 0 0 0  0 0 0 0 LSB
*       a b c d  e f g P
*
* Digit :
*
*     a
*   f   b
*     g
*   e   c
*     d   P 
*/
#define DDR_SELECT        DDRA
#define PORT_DIGIT_SELECT PORTA

/**
 * Number of digits on the display
 */ 
#define DIGIT_COUNT 4

/**
 * Number of known symbols in the 7seg display
 */ 
#define STATE_COUNT 16

/**
* Symbols Lookup table
*
* 0 to F symbols for 7segment i/o data.
*/ 
static uint8_t digits[STATE_COUNT] = {
    0xFC, 0x60, 0xDA, 0xF2, 
    0x66, 0xB6, 0xBE, 0xE0,
    0xFE, 0xE6, 0xEE, 0x3E,
    0x9C, 0x7A, 0x9E, 0x8E
};


class SMA420564 {
public: SMA420564();
private:
    uint8_t dp   = 0b0000; // Display point indecies

    uint8_t tick = 0; // Use built in timers instead
                      //
    /**
     * Display Mode
     *
     *  0 - NUMERIC - Display a numeric value as uint32_t on all displays (default)
     *  1 - RAW     - Send raw data to PORT_DIGIT_PINS as uint32_t for all displays
     */ 
    enum Mode {
        NUMERIC,
        RAW
    };

    /**
    *   Select the location of a digit on the screen
    *
    *   @param index - The index of the position ranges from 0 to DIGIT_COUNT 
    *
    */
    void set_digit_position(uint8_t index) 
    {
        PORT_DIGIT_SELECT =
            ~(0x01 << index);
    }

    /**
    *   Set a raw byte value to display 
    *
    *   @param index - The value of the digit segments
    *
    */
    void set_digit_value_raw(uint8_t value) 
    {
        PORT_DIGIT_PINS = value;
    }

    /**
    * Set the display point value
    */
    void set_display_point(bool state)
    {
        PORT_DIGIT_PINS |= state;
    }

    /**
     * Set value on a single displat digit
     *
     *  @param value    - The value to display, 0 to STATE_COUNT
     *  @param position - The position of the digit display (0 to 3)
     *
     */ 
    void set_digit(uint8_t value, uint8_t position)
    {
        set_digit_value_raw(value);
        set_digit_position(position);
    }

    /**
     * Convert uint16_t numeric value ranging from 0000 to state^n - 1,
     * into uint32_t pin values.
     *
     */ 
    static uint32_t from_numeric(
            uint16_t value,
            uint8_t states = STATE_COUNT);

    /**
     * Gets the symbol at a position in a uint16_t value
     *
     *  @param value - A value ranging from 0000 to 9999
     *  @param index - The position of the symbol were interested in
     *
     */ 
    static uint8_t get_symbol_from_uint16(
            uint16_t value,
            uint8_t index,
            uint8_t state = 10);
    
    
    /**
     * Print something to the display
     */ 
    void set_all_digits(uint32_t value);

public:
    /**
     * Set a point at an index
     */ 
    void point(uint8_t index)
    {
        this->dp |= 0x01 << index;
    }

    /**
     * Reset all points
     */ 
    void set_points(uint8_t mask)
    {
        this->dp = mask;
    }

    /**
     * Display something on the SMA420564
     *
     *  @param value  - The value to print to the screen
     *  @param states - The number of states a single digit has
     *  @param mode   - The mode with which to print the given data, default: NUMERIC
     */ 
    void write(
            uint32_t value,
            uint8_t states = 10,
            Mode mode = 0);

};

#endif
