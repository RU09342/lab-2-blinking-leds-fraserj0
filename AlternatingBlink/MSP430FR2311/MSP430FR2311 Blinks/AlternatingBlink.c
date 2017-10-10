#include <msp430.h>
int AlternatingBlink(void)
{
    volatile int i;
     // stop watchdog timer
     WDTCTL = WDTPW | WDTHOLD; //stop watchdog timer
     PM5CTL0 &= ~LOCKLPM5;

        P1DIR = 0x01;                    //sets the two LEDS as outputs
        P1OUT = 0x00;                    //Starts out with both LEDs off
        P2DIR = 0x01;                    //sets the two LEDS as outputs
        P2OUT = 0x00;

        //always
        while(1){
            if (P1OUT == 0x01){          //if the red LED is on
                P2OUT = 0x01;            //turn on the green LED and turn off the red one
                P1OUT = 0x00;
            }
            else if (P2OUT == 0x01){     //if the green LED is on
                P1OUT = 0x01;            //turn on the red LED and turn the green one off
                P2OUT = 0x00;
            }
            else{                        //if nothing is on, turn on the red LED
                P1OUT = 0x01;
            }
            for(i = 0; i <10000; i++);   //delay 10000 counts
        }
}


