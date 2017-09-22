#include <msp430.h>
/*
Code Modified Based on Source Code Provided
by TI as Example Software for MSP430FR5994
*/

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // Set P1.0 as an output
    P1OUT |= BIT0;                          // Set P1.0 high

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
                                            // Required for Code to Work Properly

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED on P1.0
        __delay_cycles(100000);             // Delays Clock by 0.1s on LED
    }
}

