#include "./src/SMA420564.h"
#define INCREMENT_DELAY 25

/**
* Entry Point
*/
int main()
{
    init();    
    Serial.begin(9600);
    
    SMA420564 Display;

    uint16_t x = 0;
    uint32_t p_timer = 0;
    
    for (;;) 
    { 
        Display.write(x, DEC);
        Display.point(2);

        if (millis() > p_timer + INCREMENT_DELAY) 
        {
            x++;
            x = x % 9999;
            p_timer = millis();
        }
        
        if (serialEventRun) 
            serialEventRun();
    }
}
