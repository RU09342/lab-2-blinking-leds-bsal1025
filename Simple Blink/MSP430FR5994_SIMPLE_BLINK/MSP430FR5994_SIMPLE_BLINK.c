#include <msp430.h>
/*
Code Taken Directly from TI via
Resource Explorer in Code Composer Studio
*/

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
                                            // Not Necessary for Code to Work

    P1DIR |= BIT0;                          // Set P1.0 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode,
                                            // to activate previously configured port settings
                                            // Code Will Not Run Without This Line

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        __delay_cycles(100000);
    }
}
