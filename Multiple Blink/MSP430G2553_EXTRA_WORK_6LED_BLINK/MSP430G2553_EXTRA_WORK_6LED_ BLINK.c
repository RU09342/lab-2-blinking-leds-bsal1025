#include <msp430.h>
void main( void )
{
  WDTCTL = WDTPW | WDTHOLD;                // Stop watchdog timer
  P1DIR  = BIT0+BIT3+BIT4+BIT5+BIT6+BIT7;  // Set P1.0 as output and P1.6 as input
  P1OUT  = 0xA8;                           // Set P1.3,P1.5, and P1.7 high

  while( 1 )
  {
      P1OUT ^= BIT0;            // Blink LED on P1.0
      P1OUT ^= BIT3;            // Blink LED on P1.3
      P1OUT ^= BIT4;            // Blink LED on P1.4
      P1OUT ^= BIT5;            // Blink LED on P1.5
      P1OUT ^= BIT6;            // Blink LED on P1.6
      P1OUT ^= BIT7;            // Blink LED on P1.7
      __delay_cycles(150000);   // Delay to see blinking LEDs

  }
}
