#include <msp430.h>
int ButtonBlink(void)
{
     // stop watchdog timer
     WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer

     // set up bit 6 and 0 of P1 as output
     P1DIR = 0x41;      // 0100 0001
     P1OUT = 0x08;      // intialize bit 0, and 6 of P1 to 1
     P1REN = 0x08;      // adds a pull up resistor on the switch (P1: 00001000)

     while(1){
     if (P1IN & 0x08){  // if P1IN and 0000 1000 are true
         P1OUT = 0x08;  // output 0000 1000, LEDs are ff
         }
     else
     {
         P1OUT = 0x49;  //output the 2 LEDs and include the pull up resistor
             }
         }
     }


