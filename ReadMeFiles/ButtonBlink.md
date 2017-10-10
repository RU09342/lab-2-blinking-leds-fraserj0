### Jake Fraser

## Lab Exercise 2: Blinking LEDs
## Button Blink

## Function
This program will turn on both of the on board LEDs on the MSP430 family of processors when the specified button is pressed. 
This code utilizes three 16 bit registers to perform its main function of blinking the LEDs when the button is pressed. 
Since these registers may vary from processr to processor, I will be referencing the specific registers used in the MSP430G2553.  

## How it works
As before, the code starts out by initializing the watchdog timer, and setting the two LEDs in port 1 as outputs. In order to use the button on the MSP430, a pull up resistor 
must be placed on the bit where the button exists. This is because With a pull-up resistor, the input pin will read a high state when the button is not pressed. In other words, 
a small amount of current is flowing between VCC and the input pin (not to ground), thus the input pin reads close to VCC. When the button is pressed,
it connects the input pin directly to ground. In order to set this pull up resistor, the register P1REN must be set. This register tells what pins a resistor should be placed on.
 In this case, the pull up resistor will be placed on pin 3 (the button). This can be seen below.

-P1REN = 0x08

From there, the code initializes the output of port 1. The LEDs should start out as off however the resistor is now set up as a pull up instead of a pull down in this line.
The P1OUT register's initialization can be seen below

-P1OUT = 0x08


Now, the processor goes into an infinite while loop. Inside the loop, there are conditionals that check to see what inputs that port 1 is getting.
If P1IN & 0x08 is true, then the button is not pressed. In this case, the output for P1 is set to only output the pull up resistor.
In any other case (the button is pressed), the two LEDs will be turned on, and the resistor will be set to pull up. Since the processor
 is constantly checking for these conditions, the LEDs will only be on if the button is pressed. The conditional statement can be seen below.

if (P1IN & 0x08)  // if P1IN and 0000 1000 are true
     { 
	P1OUT = 0x08;  // output 0000 1000, LEDs are ff
     }
else
     {
        P1OUT = 0x49;  //output the 2 LEDs and include the pull up resistor
     }

## Usage
Within this project, there are a multitude of files that all blink the LEDs in a certain manner. In order to run this file, the main.c file needs to be ran.
The user can decide which file they want to run here, and comment out any function that they dont wish to run, leaving the only file to be called, the one they want to run.
Obviously, an error will be given if more than one file is attempted to be called at once. 
