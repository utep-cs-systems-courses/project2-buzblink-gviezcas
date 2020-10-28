#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static int count = 0;
  
  if ((++count % 25) == 0) {
    buzzer_advance();
    blink_count = 0;
  }
  if(count == 250){
    main_state_advance();
    count = 0;
  }
}
