#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int main(void)
{
	uint8_t kval=0;
	delay_init(168);
	LED_Init();
	BEEP_Init();
	KEY_Init();
	while (1)
	{
		kval=KEY_Scan(0);
		if(kval)
		{
			switch(kval)
			{
				case KEY0_PRES:
					LED0=!LED0;
					break;
				case KEY1_PRES:
					LED1=!LED1;
					break;
				case KEY2_PRES:
					BEEP=!BEEP;
					break;
				case WKUP_PRES:
					LED0=1;
					LED1=1;
					break;
			}
		}
	}
}
