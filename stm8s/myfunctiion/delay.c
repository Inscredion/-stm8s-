#include "delay.h"
void delay_us(u16 i)
{
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_16,16);
  while (i--)
  {
    TIM2_Cmd(ENABLE);
    while (TIM2_GetFlagStatus(TIM2_FLAG_UPDATE )!=1);
    TIM2_ClearFlag(TIM2_FLAG_UPDATE);
    TIM2_Cmd(DISABLE);
 }
}

void delay_s(u16 i)
{
  while(i--)
    delay_us(5000);
}

