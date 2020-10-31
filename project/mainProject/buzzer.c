#include <msp430.h>

#include "switches.h"

#include "libTimer.h"

#include "buzzer.h"

#include "stateMachines.h"

char song = 0, switch2_state_changed;

void buzzer_init()

{

  /* 

       Direct timer A output "TA0.1" to P2.6.  

        According to table 21 from data sheet:

          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero

          P2SEL.6 must be 1

        Also: P2.6 direction must be output

  */
    
  timerAUpmode();/* used to drive speaker */

  P2SEL2 &= ~(BIT6 | BIT7);

  P2SEL &= ~BIT7;

  P2SEL |= BIT6;

  P2DIR = BIT6;

}



void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */

{
    
    CCR0 = cycles;

    CCR1 = cycles >> 1;/* one half cycle */
  
}

void buzzer_update()/*Waits for switch 2 to change states to start the siren.*/
{

  if(switch2_state_changed)
  {

    state_siren();

  }

}
