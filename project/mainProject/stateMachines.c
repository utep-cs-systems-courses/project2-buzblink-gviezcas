#include <msp430.h>

#include "stateMachines.h"

#include "led.h"

#include "switches.h"

#include "buzzer.h"


char dim = 0, switch3_state_changed;

extern char blink_dim;

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


void state_advance()
{

  char changed = 0;

  changed = toggle();



  led_changed = changed;

  led_update();

}

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
