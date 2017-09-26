#include <msp430.h>
void main( void )
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
  P1OUT  = 0x02;                // Set resistor P1.0 to pull-up, P1.0 low
  P1DIR  = 0x01;                // Set P1.0 as an output
  P9OUT  = 0x80;                // Set P9.7 high
  P9DIR  = 0x80;                // Set P9.7 as an output

  PM5CTL0 &= ~LOCKLPM5;         // Disable the GPIO power-on default high-impedance mode
                                // Required for Code to Work Correctly
  while( 1 )
  {
      P1OUT ^= 0x01;            // Blink LED at P1.0
      P9OUT ^= 0x80;            // Blink LED at P9.7
      __delay_cycles(100000);   // Delay to see blinking

  }
}
