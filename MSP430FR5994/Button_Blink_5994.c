#include <msp430.h>
void main( void )
{
  WDTCTL = ( WDTPW | WDTHOLD ); // Stop watchdog timer

  P1DIR  = 0x01;                // Set P1.0 as an output
  P5REN  = 0x40;                // Enable resistor on P5.6 to activate button

  PM5CTL0 &= ~LOCKLPM5;         // Disable the GPIO power-on default high-impedance mode
                                // Code Will Not Work Without this Line

  while( 1 )
  {
    if( !(P5IN & 0x40) )        // Button on P5.6 (S1) pressed
    {
      P1OUT ^= 0x01;            // Blink LED on P1.0
    }
    __delay_cycles(100000);   // Delay to see blinking
  }
}








