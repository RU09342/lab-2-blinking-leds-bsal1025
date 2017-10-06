/*
 * Button Blink
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
Each program allows the user to push a specific button and upon holding the button down an LED will blink. 
When the button is released the LED will either remain on or shut off depending on the LED state when the button is released.

Common Code Functionality Among All Processors:
All processors contain these elements in order to blink an LED using a button:
 1. The watchdog timer is cleared
 2. The P1DIR is set such that an LED will be an output
 3. The resistor for one of the buttons on the board is enabled
 4. The PxOUT register is set to be one of the button pins, setting the resistor enable to the pull-up position
 5. An if statement controls whether or not the LED blinks depending on whether or not the button is pressed  

Key Differences Between Processors:
 1. MSP430FR2311, MSP430FR6989, and MSP430FR5994 all have an extra line of code that disables the default high-impedance mode. The MSP430F5529 and
    MSP430G2553 processors do not need this line of code. 

 2. Most processors (MSP430F5529, MSP430FR2311, and MSP430FR6989) have a button or switch on P1.1 and therefore this is the pin that is resistor   
    enabled with a pull-up resistor, but the MSP430FR5994 and MSP430G2553 boards do not have a switch at this location. Instead, for the MSP430FR5994
    processor, the pin is P5.6 and for the MSP430G2553 it is P1.3.

 3. The MSP430G2553 processor is set up to run the "color change" portion of the extra work for this lab. On start-up, the green LED blinks. When
    the button at P1.3 is held down, the red LED blinks instead.  