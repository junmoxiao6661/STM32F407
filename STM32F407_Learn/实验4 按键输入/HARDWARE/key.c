#include "stm32f4xx.h"
#include "key.h"
#include "delay.h"
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_Struct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE, ENABLE);
	GPIO_Struct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIO_Struct.GPIO_Mode = GPIO_Mode_IN; // 按键是外设，所以输入
	// GPIO_Struct.GPIO_OType 推挽与开漏为输出
	GPIO_Struct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Struct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOE, &GPIO_Struct);
	GPIO_Struct.GPIO_Pin = GPIO_Pin_0;
	GPIO_Struct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Struct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Struct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOA, &GPIO_Struct);
}

uint8_t KEY_Scan(uint8_t mode)
{
	static uint8_t key_up = 1; // 松开标志
	if(mode) key_up = 1; // 连按
	if(key_up&&(KEY0 == 0 || KEY1 == 0 || KEY2 == 0 || WK_UP == 1))
	{
		delay_ms(10);
		key_up = 0;
		if(KEY0==0) return 1;
		else if(KEY1==0) return 2;
		else if(KEY2==0) return 3;
		else if(WK_UP==1) return 4;
	}else if(KEY0 == 1 && KEY1 == 1 && KEY2 == 1 && WK_UP == 0) key_up=1;
	return 0;
}
