#include <msp430.h>

#include "led.h"

#include "switches.h"



unsigned char red_on = 0, green_on = 0;

unsigned char led_changed = 0;



static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};





void led_init()

{

  P1DIR |= LEDS;// bits attached to leds are output

  switch1_state_changed = 1;

  led_update();

}


/*Updates the LED from red to green.*/
void led_update()

{ 
  
    char ledFlags = 0;

    ledFlags |= switch1_state_down ? LED_GREEN : 0;// When switch 1 is down turn on green.

    ledFlags |= switch1_state_down ? 0 : LED_RED;// When switch 1 is up turn on red.
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bit for off leds

    P1OUT |= ledFlags;     // set bit for on leds
    
}

/*Sets bits for red LED to be on and off*/
void led_dim()
{
  
  if (led_changed) {

    char ledFlags = redVal[red_on];



    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds

    P1OUT |= ledFlags;     // set bit for on leds

    led_changed = 0;

  }
  
}
