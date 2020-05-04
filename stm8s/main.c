/**
  ******************************************************************************
  * @file    Project/main.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   Main program body
   ******************************************************************************
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "adc.h"
#include "led.h"
#include "delay.h"

BitStatus add ;
BitStatus sub ;
BitStatus confirm;

u8 delay = 2;
u8 onoff;
u8 amp = 7;
u16 cnt = 0;
u16 max = 0;
u16 adc;
u16 vol;
float real = 0;

void key_init(){
  GPIO_Init(GPIOA,GPIO_PIN_2,GPIO_MODE_IN_PU_IT );
  GPIO_Init(GPIOA,GPIO_PIN_1,GPIO_MODE_IN_PU_IT );
  GPIO_Init(GPIOB,GPIO_PIN_4,GPIO_MODE_IN_PU_IT );
}


void main(void)
{
   led_conf();
   Init_ADC();
   key_init();

   LED_delay_on;
   delay_us(400);
   LED_delay_off;
   delay_us(400);
   LED_amp_on;
   delay_us(400);
   LED_amp_off;
   delay_us(400);
   LED_amp_off;
   LED_delay_on;
   delay_us(400);
   LED_delay_off;
   delay_us(400);
   LED_amp_on;
   delay_us(400);
   LED_amp_off;
   delay_us(400);
   LED_amp_off;

   confirm = GPIO_ReadInputPin(GPIOA,GPIO_PIN_2);

   while(confirm != RESET)                              //设定延时时间  1-8秒；
   {
     delay_us(1000);
     LED_delay_on;
     add = GPIO_ReadInputPin(GPIOA,GPIO_PIN_1);
     confirm = GPIO_ReadInputPin(GPIOA,GPIO_PIN_2);
     sub = GPIO_ReadInputPin(GPIOB,GPIO_PIN_4);
     led_num(delay);
     if(add ==RESET)
     {
       if(delay!=8)
       delay++;
       else
         { delay = 1;
           led_all_off();
           led_num(delay);
         }
      }
   }

   led_all_off();
   delay_us(3000);
   confirm = GPIO_ReadInputPin(GPIOA,GPIO_PIN_2);

  while(confirm != RESET)                              //设定延时时间  1-8秒；
   {
     delay_us(1000);
     LED_delay_off;
     LED_amp_on;
     add = GPIO_ReadInputPin(GPIOA,GPIO_PIN_1);
     confirm = GPIO_ReadInputPin(GPIOA,GPIO_PIN_2);
     led_num(amp);
     if(add ==RESET)
     {
       if(amp!=8)
       amp++;
       else
       { amp = 1;
       led_all_off();
       led_num(amp);
       }
     }
   }
 
while(1)
{
      led_all_off();
      LED_delay_on;
      LED_amp_on;
      delay_s(1);
      LED_delay_off;
      LED_amp_off;
      ADC1_StartConversion();
      delay_s(1);
     while(ADC1_GetFlagStatus(ADC1_FLAG_EOC)!=RESET)
      {
        adc = ADC1_GetConversionValue();
        if(adc>8)
        {
                 cnt = 0;
                 max = 0;
                 onoff=1;
                 while(cnt<200)
                {
                   delay_us(5);
                   if(adc>max)
                   {
                    max = adc;
                    real =max/((128*amp-1)/8);
                    led_control(real);
                    cnt=0;
                    }
                    else cnt++;
                    adc =ADC1_GetConversionValue();
                  }

               while(cnt<delay*1000)
               {
                   delay_us(5);
                   cnt ++;
                   if(cnt%150==0)
                   {
                     onoff = !onoff;
                     if(onoff)
                       led_all_off();
                     else
                       led_control(real);
                   }
               }
          led_all_off();
        }
      }
  }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {

  }

}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
