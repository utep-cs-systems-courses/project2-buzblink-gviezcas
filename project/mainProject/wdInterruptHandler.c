#include <msp430.h>

#include "stateMachines.h"

#include "switches.h"

char blink_dim = 125;



void

__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */

  static char blink_count = 0;
  static char buzzer_count = 0;

  if (++blink_count == blink_dim){
    
    state_advance();

    state_dim();

    blink_count = 0;

  }

  if(++buzzer_count == 50)
  {
    
    buzzer_update();

    buzzer_count = 0;

  }

}


void

__interrupt_vec(PORT2_VECTOR) Port_2(){

  if (P2IFG & SWITCHES) {      /* did a button cause this interrupt? */

    P2IFG &= ~SWITCHES;      /* clear pending sw interrupts */

    switch_interrupt_handler();/* single handler for all switches */

  }
}
