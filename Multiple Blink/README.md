/*
 * Multiple Blink
 *
 *  Created on: Oct 4, 2017
 *  Last Updated on: Oct 4, 2017
 *  Author: Brandon Salamone
 */

Libraries Used:
 msp430.h is the only library needed to run the programs.

Dependencies:
The msp430.h library does not have any dependencies.

User Interface:
Each program causes two LEDs to blink simulataneously at different rates.

Common Functionality Among All Processors:
All processors contain these elements in order to blink multiple LEDs at different rates:
 1. The watchdog timer is cleared
 2. The P1DIR and PxDIR are set such that two LEDs will be an output
 3. The PxOUT registers are set such that the pull-up resistors are enabled in each LED
 4. A while loop which runs forever controls the rate at which the LEDs blink  

Key Differences Between Processors:
 1. MSP430FR2311, MSP430FR6989, and MSP430FR5994 all have an extra line of code that disables the default high-impedance mode. The MSP430F5529 and
    MSP430G2553 processors do not need this line of code. 

 2. Different Processors have different LED pin assignments. Below the LED pin assignments will be shown for each processor.
    msp430F5529: P1.0 and P4.7
    msp430FR2311: P1.0 and P2.0
    msp430FR5994: P1.0 and P1.1 *
    msp430FR5989: P1.0 and P9.7
    msp430G2553: P1.0 and P1.6 *
    
    * For these processors, the hexadecimal values pertaining to each pin can be combined into one number, since they have P1 in common.
      For example in the msp430FR5994 processor it would be: P1DIR = BIT0 | BIT1 = 0x03 

   