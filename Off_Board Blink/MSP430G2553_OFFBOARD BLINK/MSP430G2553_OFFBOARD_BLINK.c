#include <msp430.h>
void main( void )
{
  WDTCTL = WDTPW | WDTHOLD;     // Stop watchdog timer
  P1DIR  = 0x41;                // Set P1.0 as output and P1.6 as input
  P1OUT  = 0x40;                // Set P1.6 high

  while( 1 )
  {
      P1OUT ^= 0x01;            // Blink LED on P1.0
      P1OUT ^= 0x40;            // Blink LED on P1.6
      __delay_cycles(100000);   // Delay to see blinking LEDs

  }
}
