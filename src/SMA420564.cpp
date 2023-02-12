#include <Arduino.h>
#include "SMA420564.h"

SMA420564::SMA420564() 
{
    // Digit Selectors
    DDR_SELECT        = 0x0F;
    PORT_DIGIT_SELECT = 0xFF;

    // Digit segments & Single DP pin
    DDR_PINS          = 0xFF;
    PORT_DIGIT_PINS   = 0x00;
} 
 
uint32_t SMA420564::from_numeric(
    uint16_t value,
    uint8_t states = STATE_COUNT)
{
    uint32_t ans = 0;

    for (int i = 0; i < DIGIT_COUNT; i++) 
    { 
        ans |= (uint32_t)
            (digits[get_symbol_from_uint16(value, i, states)]) << (8*i);     
    }

    return ans;
}

uint8_t SMA420564::get_symbol_from_uint16(
        uint16_t value,
        uint8_t index,
        uint8_t state = STATE_COUNT)
{
    return value / (uint16_t)ceil(pow(state, index)) % state;
}
    
void SMA420564::set_all_digits(uint32_t value) 
{
    set_digit_value_raw(
        (value >> (8 * this->tick)) & 0xFF
    );
    set_digit_position(this->tick);

    this->tick = (this->tick + 1) % DIGIT_COUNT;
}

void SMA420564::write(
        uint32_t value,
        uint8_t states = STATE_COUNT,
        Mode mode = 0) 
{
    switch(mode) 
    { 
        case RAW:
            set_all_digits(value);
            break;
        case NUMERIC:
        default:
            set_all_digits(
                SMA420564::from_numeric(value, states)
            );
            break;
    }
}
