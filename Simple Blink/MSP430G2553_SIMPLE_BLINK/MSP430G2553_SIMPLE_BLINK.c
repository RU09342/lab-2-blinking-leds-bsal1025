#include <msp430.h>
/*
Code Taken Directly from TI via
Resource Explorer in Code Composer Studio
*/

int main(void) {
   volatile int i;


   WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
   P1DIR = 0x01; // set up bit 0 of P1 as output
   P1OUT = 0x00;  // intialize bit 0 of P1 to 0
   // loop forever
   for (;;) {
       P1OUT ^= 0x01;  // toggle bit 0 of P1
   for (i = 0; i < 0x6000; i++); // delay for a while
   }
 }
