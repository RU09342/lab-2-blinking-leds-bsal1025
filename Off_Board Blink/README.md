/*
 * Off-Board Blink
 *
 *  Created on: Oct 5, 2017
 *  Last Updated on: Oct 5, 2017
 *  Author: Brandon Salamone
 */

Circuit Design:
The circuit shown in the file "Circuit_Working_Image" is powered using wires connected to the Vcc and ground terminals of the development board.
Resistors are connected from pins P1.0 and P1.6 (each pin controls an LED) on the processor to the positive terminal of the each LED. The resistors
are both rated at 10K. These resistors limit the current supplied to the LEDs. The last element required to make the circuit work is a connection between the 
reset pin (RST) on the processor and Vcc. This connection ensures that the reset is never active while power is being supplied to the circuit. Without this 
critical connection, the processor continuously resets itself, and no LEDs will blink. 

Code Used:
The code used to program the board in this case is the same code used in the Multiple Blink folder for the MSP430G2553 development board. No changes
were necessary to make the program work. The processor was pre-programmed before being placed on the breadboard.  
