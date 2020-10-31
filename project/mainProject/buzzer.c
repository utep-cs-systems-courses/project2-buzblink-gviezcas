#include <msp430.h>

#include "switches.h"

#include "libTimer.h"

#include "buzzer.h"

char switch2_state_changed, switch4_state_changed;
char song = 0;

extern char blink_dim;



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

void buzzer_update()
{

  if(switch2_state_changed)
  {

    buzzer_siren();

  }

}

void buzzer_siren()
{
     
     switch(song)
     {
     case 0:
       buzzer_set_period(1000);
       switch1_state_down = 0;
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

void buzzer_off(){

  if(switch4_state_down)
    {
      
      buzzer_set_period(0);
      switch2_state_changed = 0;
      blink_dim = 125;

    }
  
  switch4_state_changed = 0;
}
