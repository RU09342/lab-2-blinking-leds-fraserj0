#include <msp430.h>
int SimpleBlink(void)
{
    volatile int i;
     WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer

     // set up bit 0 and 6 of P1 as output
     // These bits are connected to LEDs
     P1DIR = 0x41;                   // 0100 0001
     P1OUT = 0x41;                   //Initializes both LEDs to be on

     // loop forever
     while(1) {
       P1OUT ^= 0x41;                // toggle bit 6 and 0 of P1
       for (i = 0; i < 10000; i++);  // delay 10000 counts
     }
}
