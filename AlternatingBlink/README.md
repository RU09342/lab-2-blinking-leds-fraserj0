### Jake Fraser

## Lab Exercise 2: Blinking LEDs
## Alternating Blink

## Function
This program will alternate toggle two LEDs on the MSP430 family of processors at a speed predetermined in the program's code. The code starts out by initializing the watchdog timer.
The watchdog timer is a system timer used to generate a system reset if the main program neglects to periodically service it. 
From there, the code utilizes two 16 bit registers to perform its main function of alternately blinking the LEDs. Since these registers may vary from processr to processor, 
I will be referencing the specific registers used in the MSP430G2553.  

## How it works
In order to specify what bits of the register are to be used as outputs, the P1DIR register is used. Since the only two bits that we want to use are the ones attached to
LED1 and LED2, those bits are turned high. This line of code can be seen here:

-P1DIR = 0x41

Once the two LEDs are selected as outputs, their initial states are decided upon. Since both LEDs are initialized as off, the next line of code is 

-P1OUT = 0x00

From there, the program goes into its infinite loop. In the loop, there is a series of if statements that will change the value P1OUT register depending on its current state, effectively
changing the state of the LEDs. If the green LED is on (P1OUT = 0x40), then turn off the green LED and turn on the red LED (P1OUT = 0x01). The next statement reads if the 
red LED is on, then turn it off and turn on the green LED. Since the LEDs are both initialized as off, there is an else statement that the code will run into first which 
sets the value of P1OUT to be 0x01 (green LED on). After the series of conditional statements, there is a for loop that delays the program for 1000 counts. Changing this 
number will effectively change the speed at which the LEDs alternate at. 

## Usage
Within this project, there are a multitude of files that all blink the LEDs in a certain manner. In order to run this file, the main.c file needs to be ran.
The user can decide which file they want to run here, and comment out any function that they dont wish to run, leaving the only file to be called, the one they want to run.
Obviously, an error will be given if more than one file is attempted to be called at once. 

