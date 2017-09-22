#include <msp430.h>
void main( void )
{
  WDTCTL = WDTPW | WDTHOLD;     // Stop watchdog timer
  P1DIR  = 0x01;                // Set P1.0 as an output
  P2DIR  = 0x01;                // Set P2.0 as an output 
  P2OUT  = 0x01;                // Set P2.0 high

  PM5CTL0 &= ~LOCKLPM5;         // Disable the GPIO power-on default high-impedance mode
                                // Required for Code to Work Properly
  while( 1 )
  {
      P1OUT ^= 0x01;            // Blink LED 1.0
      P2OUT ^= 0x01;            // Blink LED 2.0
      __delay_cycles(100000);   // Delay to see blinking

  }
}



