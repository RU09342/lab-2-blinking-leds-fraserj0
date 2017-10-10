#include <msp430.h>

int MultipleBlink(void)
{
    volatile int timer;
    PM5CTL0 &= ~LOCKLPM5;
     WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer

     // set up bit 6 and 0 of P1 as output
     P1DIR = 0x01;             // 0100 0001
     P2DIR = 0x01;
     P1OUT = 0x01;
     P2OUT = 0x01;
     timer = 0;                //sets arbitrary variable 'timer' equal to 0

     // loop forever
     while(1) {
         timer ++;             //every loop will increment timer
         if (timer % 500 == 0) //if timer is a multiple of 500
         {
             P1OUT ^= 0x01;    //xor P1OUT with 0000 0001
         }

         if (timer == 2250)    // when timer hits 2250
         {
             P2OUT ^= 0x01;    // xor P1OUT with 0100 0000
             timer = 0;        // timer is reset to 0
         }
     }
}
