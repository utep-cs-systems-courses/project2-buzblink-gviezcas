#ifndef switches_included

#define switches_included



#define SW1 BIT0/* switch1 is p2.0 */

#define SW2 BIT1/*switch2 is p2.1*/

#define SW3 BIT2/*switch3 is p2.2*/

#define SW4 BIT3/*switch4 is p2.3*/

#define SWITCHES (BIT0 | BIT1 | BIT2 | BIT3)



void switch_init();

void switch_interrupt_handler();



extern char switch1_state_down, switch1_state_changed, switch2_state_down, switch2_state_change, switch3_state_down, switch3_state_change, switch4_state_down, switch4_state_change; /* effectively boolean */



#endif // included
