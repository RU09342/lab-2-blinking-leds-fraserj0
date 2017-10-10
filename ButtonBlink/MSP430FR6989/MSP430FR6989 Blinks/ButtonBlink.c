#include <msp430.h>
int ButtonBlink(void)
{
    volatile int i;
     // stop watchdog timer
     WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer
     PM5CTL0 &= ~LOCKLPM5;

     // set up bit 6 and 0 of P1 as output
     P1DIR = 0x03;      // 0100 0001
     P1OUT = 0x00;      // intialize bit 0, and 6 of P1 to 1
     P9DIR = 0x80;
     P9OUT = 0x00;
     P1REN = 0x02;      // adds a pull up resistor on the switch (P1: 00001000)

     while(1){
     if (P1IN & 0x02){  // if P1IN and 0000 1000 are true
         P1OUT = 0x02;  // output 0000 1000, LEDs are ff
         P9OUT = 0x00;
         }
     else
     {
         P1OUT = 0x03;  //output the 2 LEDs and include the pull up resistor
         P9OUT = 0x80;
             }
         }
     }




