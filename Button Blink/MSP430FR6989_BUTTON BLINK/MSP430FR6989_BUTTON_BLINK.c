#include <msp430.h>
void main( void )
{
  WDTCTL = ( WDTPW | WDTHOLD ); // Stop watchdog timer
  P1DIR  = 0x01;                // Set P1.0 as an output
  P1REN  = 0x02;                // Enable resistor on P1.1
  P1OUT  = 0x02;                // Resistor on P1.1 set to Pull-up

  PM5CTL0 &= ~LOCKLPM5;         // Disable the GPIO power-on default high-impedance mode

  while( 1 )
  {
    if( !(P1IN & 0x02) )        // Button on P1.1 (S1) pressed
    {
      P1OUT ^= 0x01;            // Toggle LED on P1.0
    }

    __delay_cycles(100000);     // Delay to see blinking
  }
}
