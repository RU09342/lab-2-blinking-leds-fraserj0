### Jake Fraser

## Lab Exercise 2: Blinking LEDs
## Button Blink Color Change 

## Function
This program will change which LED is on when the button is pressed on the MSP430 family of processors.  
To start, the code utilizes three 16 bit registers to perform its main function of toggling between the LEDs. Since these registers may vary from processr to processor, 
I will be referencing the specific registers used in the MSP430G2553.  

## How it works
This program starts out by initializing the values for P1DIR, P1OUT, and P1REN. Since the two LEDs are the only outputs, P1DIR will be initialized as P1DIR = 0x41.
The button will also need a pullup resistor, so P1REN is set to 0x08, since the button is located on pin 3 of port 1. In the 
P1OUT register, the green LED is initialized to be on first, and the resistor is set to pull up causing the register's value to become 0x48.

The next part of the code is the infinite loop containing conditionals that check the sttus of the LEDs. First the loop checks to
see if the button is pressed. If not, then a volotile integer "prevon" is set to 1. If prevon is 0, it signifies that the button had not previously been pressed.
If the button is being pressed, then another condition is checked. If the green LED is on and prevon is 1, then the red LED is turned on,
the green one is turned off, and prevon is set to 0. If the red LED is on and prevon is set to 1, meaning the program had already gone through the very first condition,
 then the green LED is turned on, the red one is turned off, and prevon is set to 0. These conditional statements can be seen below. 

if (P1IN & 0x08){           // if P1IN is 0000 0000 plus 0000 1000 (pull up resistor)
         prevon = 0x01;          // prev on is now 0000 0001
         }
     else                        //if button is pressed
     {
         if (P1OUT == 0x48 & prevon){   // If the green LED is on and prevon is 1
             P1OUT = 0x09;              // The red LED turns on
             prevon = 0x00;             // prevon is now set to 0
             }

         else if (P1OUT == 0x09 & prevon){  // If the red LED is on and prevon is 1
             P1OUT = 0x48;                  // The green LED turns on
             prevon = 0x00;                 // Prevon is set to 0
             }

At this point, prevon should be equal  to 0 no matter what LED was on. Therefore the program wil go back to the first condition to check if the button had been pressed. 



## Usage
Within this project, there are a multitude of files that all blink the LEDs in a certain manner. In order to run this file, the main.c file needs to be ran.
The user can decide which file they want to run here, and comment out any function that they dont wish to run, leaving the only file to be called, the one they want to run.
Obviously, an error will be given if more than one file is attempted to be called at once. 

