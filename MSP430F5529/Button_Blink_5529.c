#include <msp430.h>

int main(void)
{
  volatile unsigned int i;                  // Delay Variable to Control For Loop

  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P1DIR |= BIT0;                            // Set P1 Direction so that P1 is an Output
  P1REN |= 0x02;                            // Enables Resistor on P1.1 so that S1 can be used
  while(1)                                  // Loop that runs forever so that the program never terminates
  {
   if( !(P1IN & 0x02) ) // If push button S1 is pressed
    {
      P1OUT ^= BIT0;                          // XOR P1.0
      for(i=50000;i>0;i--);                   // Decrements by 1 from 50k to create a delay on the LED
    }
  }
}





