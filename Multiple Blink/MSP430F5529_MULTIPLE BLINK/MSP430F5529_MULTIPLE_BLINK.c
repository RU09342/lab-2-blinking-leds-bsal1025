#include <msp430.h>
void main( void )
{
  unsigned int i;                //delay variable used in for loop below
  WDTCTL = WDTPW | WDTHOLD;     // Stop watchdog timer
  P1OUT  = 0x02;                // Set resistor to pull-up, P1.0 low (combined call makes value hex 2)
  P1DIR  = 0x01;                // Set P1.0 as output
  P4OUT  = 0x80;                // Set P4.7 high
  P4DIR  = 0x80;                // Set P4.7 as output

  while( 1 )
  {
      P1OUT ^= 0x01;            // Toggles LED on P1.0
      P4OUT ^= 0x80;            // Toggles LED on P4.7
      for( i=0; i<30000; i++ ); // delays LED blink

  }
}
