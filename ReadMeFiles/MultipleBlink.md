### Jake Fraser

## Lab Exercise 2: Blinking LEDs
## Multiple Blink

## Function
This program will toggle two LEDs at different speeds on the MSP430 family of processors. 
This code utilizes two 16 bit registers as well as a volotile integer, timer, to perform its main function of blinking the LEDs at different speeds. 
Since these registers may vary from processr to processor, I will be referencing the specific registers used in the MSP430G2553.  

## How it works
As before, the code starts out by initializing the wathdg timer, and setting the two LEDs in port 1 as outputs. From there, the two LEDs are both initialized as on
Now, since we want to blink the two LEDs separately, a timer variable is used to decide when each LED will blink. This integer value is initialized at 0.
From there, the code goes into an infinite while loop that increments the timer variable with every run through. Now since we want to blink the two LEDs at different speeds,
there are two if statements with conditions telling each LED when to blink. One of these LEDs, in this case the green one, can be told to blink when the timer integer is equal to a certain value.
When the timer reaches 2250, the LED will blink, the timer will be set to 0, and this action will repeat. This condition can be seen below.


 if (timer == 2250)    // when timer hits 2250
         {
             P1OUT ^= 0x40;    // xor P1OUT with 0100 0000
             timer = 0;        // timer is reset to 0
         }


However, if the same method is used, then the red LED will effectively 
be blinking at the same speed. This is because if the timer is reset, then the same amount of time will pass in between each LED blinking, and they will just be blinking at different times.
To counteract this, the modulus operator is used. Whenever the timer is equal to a multiple of 500, the red LED will blink. This condition can be seen below.

if (timer % 500 == 0) //if timer is a multiple of 500
         {
             P1OUT ^= 0x01;    //xor P1OUT with 0000 0001
         }

The modulus operator now allows for the LEDs to blink at different speeds, as the green LED blinks every 2250 counts and the red one blinks every 500 counts.


## Usage
Within this project, there are a multitude of files that all blink the LEDs in a certain manner. In order to run this file, the main.c file needs to be ran.
The user can decide which file they want to run here, and comment out any function that they dont wish to run, leaving the only file to be called, the one they want to run.
Obviously, an error will be given if more than one file is attempted to be called at once. 
