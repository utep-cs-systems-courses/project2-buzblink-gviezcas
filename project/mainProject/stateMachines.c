#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "switches.h"

#include "buzzer.h"


char dim = 0, switch2_state_changed, switch4_state_changed, song;

extern char blink_dim;

/*Toggles between the Red and Green LEDs*/
char toggle()

{

  static char state = 0;


  switch(state) {
  case 0:

    red_on ^= 1;

    green_on ^= 0;

    state = 1;
    
    break;
    
  case 1:

    red_on ^= 0;

    green_on ^= 1;

    state = 0;

    break;

  }

  return state;/* always changes an led */

}

/*Toggles the red LED on and off.*/
char toggle_red()/* always toggle! */

{

  static char state = 0;



  switch (state) {

  case 0:

    red_on = 1;

    state = 1;

    break;

  case 1:

    red_on = 0;

    state = 0;

    break;

  }

  return 1;/* always changes an led */

}

/*Advances the state to toggle the LEDs from red to green.*/
void state_advance()
{

  char changed = 0;

  changed = toggle();



  led_changed = changed;

  led_update();

}

/*Changes the blink count in the Interrupt Handler to change the brightness of the red LED.*/
void state_dim()
{
       
  switch(dim)
  {

   case 0:
	
     blink_dim = 1;

     dim++;
	
     break;
	
  case 1:
	
    blink_dim = 2;

    dim++;
	
    break;
	
  case 2:
    
    blink_dim = 3;

    dim++;
    
    break;
    
  case 3:
    
    blink_dim = 4;
      
    dim++;
      
    break;
    
  case 4:
    
    blink_dim = 5;
    
    dim = 0;
    
    break;
    
  default:
    
    buzzer_set_period(1000);
    
  }
  
}

/*Toggles between different buzzer pitches and both LEDs to create a siren.*/
void state_siren()
{

  switch(song)
  {

  case 0:
    
    buzzer_set_period(1000);

    switch1_state_down = 0;//LEDs rely on switch1, so need to change the state without pressing.

    state_advance();

    song++;

    break;

  case 1:
    
    buzzer_set_period(700);

    switch1_state_down = 1;

    state_advance();

    song = 0;

    break;
    

  }

}

/*Turns off the buzzer, siren and sets the brightness of the red LED back to default.*/
void state_off()
{

  if(switch4_state_down)
  {

    buzzer_set_period(0);
    switch2_state_changed = 0;
    blink_dim = 125;

  }

  switch4_state_changed = 0;

}
