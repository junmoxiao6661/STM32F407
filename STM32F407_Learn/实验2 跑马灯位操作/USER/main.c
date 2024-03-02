#include "stm32f4xx.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
int main(void)
{
	delay_init(168);
	LED_Init();
	while(1)
	{
		PFout(9)=1;
		PFout(10)=1;
		delay_ms(1000);
		PFout(9)=0;
		PFout(10)=0;
		delay_ms(1000);
	}
}
