#include <msp430.h>

#include "stateMachines.h"

#include "switches.h"

#include "buzzer.h"

#include "led.h"

char blink_dim = 0;



void

__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */

  static char blink_count = 0;
  static char buzzer_count = 0;
  static char dim_count = 0;

  if (++blink_count == 125){
    
    state_advance();

    blink_count = 0;

  }

  if(++buzzer_count == 50)
  {
    
    buzzer_update();

    buzzer_count = 0;

  }

  if(++dim_count == blink_dim)
  {
    if(switch3_state_down)
    { 
      led_changed = toggle_red();
      led_dim();
      
      state_dim();
      
    }
    
    dim_count = 0;
    

  }

}


void

__interrupt_vec(PORT2_VECTOR) Port_2(){

  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */

    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }
}
