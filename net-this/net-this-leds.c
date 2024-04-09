#include "lpc1768/gpio.h"

#define LED_GR_L_DIR FIO1DIR(31) //P1.31 ==> p20 output
#define LED_GR_L_SET FIO1SET(31)
#define LED_GR_L_CLR FIO1CLR(31)

#define LED_YE_R_DIR FIO1DIR(30) //P1.30 ==> p19 output
#define LED_YE_R_SET FIO1SET(30)
#define LED_YE_R_CLR FIO1CLR(30)

void NetThisLinkLed(char on)
{
    LED_GR_L_DIR = 1; //Set the direction to 1 == output
	if (on) LED_GR_L_SET;
	else    LED_GR_L_CLR;
}
void NetThisSpeedLed(char on)
{
    LED_YE_R_DIR = 1; //Set the direction to 1 == output
	if (on) LED_YE_R_SET;
	else    LED_YE_R_CLR;
}
