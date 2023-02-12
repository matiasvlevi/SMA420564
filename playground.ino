#include "./src/SMA420564.h"
#define DELAY 25

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

        if (millis() > DELAY+p_timer) 
        {
            x++;
            x = x % 9999;
            p_timer = millis();
        };
        
        if (serialEventRun) 
            serialEventRun();
    }
}
