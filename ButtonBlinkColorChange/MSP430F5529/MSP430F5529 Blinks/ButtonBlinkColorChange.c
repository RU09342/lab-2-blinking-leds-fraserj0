#include <msp430.h>
int ButtonBlinkColorChange(void)
{
    volatile int i;
     // stop watchdog timer
     WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer

     // set up bit 6 and 0 of P1 as output
     P1DIR = 0x01;      // 0100 0001
     P1OUT = 0x00;      // intialize bit 0, and 6 of P1 to 1
     P4DIR = 0x80;
     P4OUT = 0x00;
     P2DIR = 0x02;
     P2OUT = 0x00;
     P2REN = 0x02;      // adds a pull up resistor on the switch (P1: 00001000)

     volatile int prevon;        // creates an integer 'prevon'

     //always
     while(1){
     if (P2IN & 0x02){           // if P1IN is 0000 0000 plus 0000 1000 (pull up resistor)
         prevon = 0x01;          // prev on is now 0000 0001
         }
     else                        //if button is pressed
     {
         if (P1OUT == 0x01 & P4OUT == 80 & P2OUT == 0x02 & prevon){   // If the green LED is on and prevon is 1
             P1OUT = 0x01;              // The red LED turns on
             P2OUT = 0x02;
             prevon = 0x00;             // prevon is now set to 0
             }

         else if (P1OUT == 0x01 & prevon){  // If the red LED is on and prevon is 1
             P4OUT = 0x80;                  // The green LED turns on
             P2OUT = 0x02;
             prevon = 0x00;                 // Prevon is set to 0
             }

     }
   }
}


