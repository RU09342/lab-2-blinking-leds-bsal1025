#include <msp430.h>
void main( void )
{
  WDTCTL = ( WDTPW | WDTHOLD ); // Stop watchdog timer
  P1DIR  = 0x41;                // Set P1.0 and P1.6 to output
  P1REN  = 0x08;                // Enable resistor on P1.3
  P1OUT  = 0x08;                // Resistor on P1.3 set to pull-up

  while( 1 )
  {
    if( !(P1IN & 0x08) )        // Button on P1.3 (S2) pressed
    {
      P1OUT ^= 0x01;            // Toggle LED on P1.0
    }
    else                        // Button released
    {
      P1OUT ^= 0x40;            // Toggle LED on P1.6
    }

    __delay_cycles( 250000 );   // Delay to see blinking
  }
}

