/*
 * File:   main.c
 * Author: Jake Rieger
 *
 * Created on June 4, 2017, 6:22 PM
 */

#include <xc.h>
#include <stdlib.h>
#include <stdbool.h>

#define _XTAL_FREQ 4000000

// Red - RD2
// Green - RD1
// Blue - RD0
#define RED LATDbits.LATD2
#define GREEN LATDbits.LATD1
#define BLUE LATDbits.LATD0

// Initialize PORTS
void init(void)
{
    // PORTB Configuration
    ADCON1 = 0;
    ANSELB = 0;
    TRISB = 1;
    
    // PORTD Configuration
    TRISD = 0;
 
    // Initialize OUTPUTS as 0
    RED = 0;
    GREEN = 0;
    BLUE = 0;
    
    return;
}

void blink_led()
{
    // Alternate colors every second
    RED = 1;
    __delay_ms(5000);
    RED = 0;
    GREEN = 1;
    __delay_ms(5000);
    GREEN = 0;
    BLUE = 1;
    __delay_ms(5000);
    BLUE = 0;
}

void main(void)
{   
    // Execute initialization
    init();
    
    // Application Loop
    for(;;)
    {
        if (RB4 == 1) {
            blink_led();
        } else {
            
        }
    }
    
    return;
}
