/*
 * Simple Blink
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
Each program causes an LED to blink at a certain frequency.

Common Functionality Among All Processors:
All processors contain these elements in order to blink an LED:
 1. The watchdog timer is cleared
 2. The P1DIR register is set such that the P1.0 LED will be an output
 3. The P1OUT register is set such that P1 is cleared before running the rest of the program

Key Differences Between Processors:
 1. MSP430FR2311, MSP430FR6989, and MSP430FR5994 all have an extra line of code that disables the default high-impedance mode. The MSP430F5529 and
    MSP430G2553 processors do not need this line of code. 

 2. A while loop is used in the MSP430FR2311, MSP430FR5994, and MSP430FR6989 processors to control the speed of the blinking, whereas the MSP430F5529 
    and MSP430G2553 processors use a for loop to accomplish the same task.
