Project 2: Blinky-Buzzy Toy

=============================
# Files:

buzzer.c - Initializes the buzzer and method to set the buzzer tone.

led.c - Initializes the led's, sets bits to update LED's form red to green and
sets bits for red LED to turn on and off.

stateMachines.c - Holds all the state machines for the different functions of
the msp430.

switches.c - Initializes the switches, detecs when switches are up or down and
handles what happens when switches are interrupted.

wdInterruptHandler.c - Handles the interrupts with time for the different
states and switches.

# Instructions:
Typing "make load" compiles the msp430 files to use it.  After that the
switches are ready to be used.

Typing "make clean" removes unecessary files.

Switch 1 toggles from red LED to green LED when held down.

Switch 2 turns on a siren with flashing lights when pressed.

Switch 3 switches the brightness of the red LED between five different
brightness levels when held down.

Switch 4 turns off siren and sets the LEDs back to default brightness.
