#include <msp430.h>
void main( void )
{
  WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
  P1DIR  = 0x03;                // Set P1.0 as output and P1.1 as input (hex number is P1 and P1.1 added together)
  P1OUT  = 0x02;                // Set P1.1 high

  PM5CTL0 &= ~LOCKLPM5;         // Disable the GPIO power-on default high-impedance mode
                                // Code Will Not Run Without This Line
  while( 1 )
  {
      P1OUT ^= 0x01;            // Blink P1.0
      P1OUT ^= 0x02;            // Blink P1.1
      __delay_cycles(100000);   // Delay to see blinking

  }
}
