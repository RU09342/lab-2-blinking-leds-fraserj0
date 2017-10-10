### Jake Fraser

## Lab Exercise 2: Blinking LEDs
## Simple Blink

## Function
This program will toggle two LEDs on the MSP430 family of processors at a speed predetermined in the program's code. The code starts out by initializing the watchdog timer.
The watchdog timer is a system timer used to generate a system reset if the main program neglects to periodically service it. 
From there, the code utilizes two 16 bit registers to perform its main function of blinking the LEDs. Since these registers may vary from processr to processor, 
I will be referencing the specific registers used in the MSP430G2553.  

## How it works
In order to specify what bits of the register are to be used as outputs, the P1DIR register is used. Since the only two bits that we want to use are the ones attached to
LED1 and LED2, those bits are turned high. This line of code can be seen here:

-P1DIR = 0x41

The syntax in this program uses hexadecimal numbers to specify values in registers, simplyifying a sixteen bit register to two values. Here, since the LEDs are located at 
bits 0 and 6 of register 1, the number 0100 0001 is seen as 0x41. This same line of code can also be written in a number of other ways, such as:

-P1DIR = BIT0 + BIT6

This same idea is then used in the next line of code where the output of register P1 is initialized. Since both LEDs are initialized to on, the line of code below is set

-P1OUT = 0x41

Next, a while loop is set in order to toggle the LEDs forever. To do this, the while loops condition is set to 1, because this will be true forever. 
Inside the while loop, the LEDs are toggled with the line of code

-P1OUT ^= 0x41

XORing the value of P1OUT with the bits that we want to turn on and off will toggle the LEDs each time that the code ges through the while loop. A for loop is then added 
in at the the end of the while loop that delays the next time the program goes through the loop for 1000 counts. This allows the speed at which the LEDs are toggled to be set in the program.

In concluson, the while loop is as follows:
	-Toggle LEDs
	-Wait for a certain amount of time
	-Repeat


## Usage
Within this project, there are a multitude of files that all blink the LEDs in a certain manner. In order to run this file, the main.c file needs to be ran.
The user can decide which file they want to run here, and comment out any function that they dont wish to run, leaving the only file to be called, the one they want to run.
Obviously, an error will be given if more than one file is attempted to be called at once. 

