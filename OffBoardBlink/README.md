### Jake Fraser

## Lab Exercise 2: Blinking LEDs
## Off Board Blink

## Function
In this excersize, the MSP430G2553 was programmed with the SimpleBlink software and was placed on a breadboard. Once the proper 
protection circuitry was installed, and the processor was powered, an LED is connected to the outpin pin. Once done correctly, the
LED blinks exactly how it did when the processor was on the development board. 

![alt text](https://github.com/RU09342/lab-2-blinking-leds-fraserj0/blob/master/OffBoardBlink/OffBoardBlinkVideo.gif)

## How it works
Once the processor is placed on the breadboard, a protection circuit must be built in order to keep the processor from recieving
too much power causing it to fail. To do this, a bulk capacitor is added in order to act as a temporary power supply if the power
surges or drops. Bypass capacitors are also added into the circuit for the same reason. 

Once this power protection circuit is built, the load circuit can be added to the output of the processor. A PMOS is used to amplify power to the LED, while the 4.7k resistor is used to 
limit the current through the LED. The schematic for this excersize can be seen in the OffBoardBlinkSchematic.JPG file enclosed in this repository. The power protection circuit is seen on the left while the 
load circuit can be seen on the right.

## Usage
Any blinking software can be programmed to the processor and placed on the breadboard, As long as the proper hardware is installed into the circuit. 
For example, if the software calls for a button, a button will obviously need to be installed to the correct output pin. If the program calls for two LEDs, LEDs can be installed to thse
two pins. However, more than LED may be installed on each output pin.