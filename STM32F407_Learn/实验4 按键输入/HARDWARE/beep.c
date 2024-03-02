#include "stm32f4xx.h"
#include "beep.h"

void BEEP_Init(void)
{
    GPIO_InitTypeDef GPIO_Struct;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    GPIO_Struct.GPIO_Pin = GPIO_Pin_8;
    GPIO_Struct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Struct.GPIO_OType = GPIO_OType_PP;
    GPIO_Struct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Struct.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOF, &GPIO_Struct);
    GPIO_ResetBits(GPIOF,GPIO_Pin_8);
}
