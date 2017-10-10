#include <msp430.h>
int SimpleBlink(void)
{
    volatile int i;
     WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer

     // set up bit 0 and 6 of P1 as output
     // These bits are connected to LEDs
     P1DIR = 0x01;                   // 0100 0001
     P1OUT = 0x01;                   //set this value to be in the P1OUT register
     P4DIR = 0x80;                   // 0100 0001
     P4OUT = 0x80;

     // loop forever
     while(1) {
       P1OUT ^= 0x01;                // toggle bit 6 and 0 of P1
       P4OUT ^= 0x80;
       for (i = 0; i < 10000; i++);  // toggle bit 6 and 0 of P1
     }
}


