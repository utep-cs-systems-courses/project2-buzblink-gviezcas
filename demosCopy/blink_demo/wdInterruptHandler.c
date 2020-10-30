#include <msp430.h>
#include "stateMachines.h"

char blink_dim = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  
  if (++blink_count == blink_dim) {
    state_advance();
    blink_count = 0;
  }
}
