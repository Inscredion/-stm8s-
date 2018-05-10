#include "led.h"

void led_conf()
{
   GPIO_DeInit(GPIOD);
   GPIO_DeInit(GPIOC);
   GPIO_DeInit(GPIOA);

   GPIO_Init(GPIOC,GPIO_PIN_3,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOC,GPIO_PIN_4,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOC,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOC,GPIO_PIN_6,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOC,GPIO_PIN_7,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOD,GPIO_PIN_4,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOD,GPIO_PIN_2,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOD,GPIO_PIN_3,GPIO_MODE_OUT_PP_LOW_FAST);

   GPIO_Init(GPIOA,GPIO_PIN_3,GPIO_MODE_OUT_PP_LOW_FAST);
   GPIO_Init(GPIOD,GPIO_PIN_6,GPIO_MODE_OUT_PP_LOW_FAST);
}

void led_all_on(){
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_6);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_5);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_3);
};
 void led_all_off(){
      GPIO_WriteLow(GPIOD,GPIO_PIN_3);
      GPIO_WriteLow(GPIOD,GPIO_PIN_2);
      GPIO_WriteLow(GPIOD,GPIO_PIN_4);
      GPIO_WriteLow(GPIOC,GPIO_PIN_7);
      GPIO_WriteLow(GPIOC,GPIO_PIN_6);
      GPIO_WriteLow(GPIOC,GPIO_PIN_5);
      GPIO_WriteLow(GPIOC,GPIO_PIN_4);
      GPIO_WriteLow(GPIOC,GPIO_PIN_3);
}

void led_control(u8 t)
{
  switch(t){
  case 0:
    led_all_off(); break;
  case 1:
    LED0_on;       break;
  case 2:
    LED0_on;     LED1_on;      break;
  case 3:
    LED0_on;     LED1_on;  LED2_on;    break;
  case 4:
    LED0_on;     LED1_on;  LED2_on;  LED3_on;    break;
  case 5:
    LED0_on;     LED1_on;  LED2_on;  LED3_on;   LED4_on;   break;
  case 6:
    LED0_on;     LED1_on;  LED2_on;  LED3_on;   LED4_on;    LED5_on;     break;
  case 7:
    LED0_on;     LED1_on;  LED2_on;  LED3_on;   LED4_on;    LED5_on;  LED6_on;    break;
  case 8:
    led_all_on();       break;
  default:
    led_all_on();break;
  }
}

void led_select(u8 t)
{
   switch(t){
  case 0:
     led_control(1);    break;
  case 1:
     led_control(2);    break;
  case 2:
     led_control(3);    break;
  case 3:
     led_control(4);    break;
  case 4:
     LED4_on;    break;
  case 5:
     LED5_on;    break;
  case 6:
     LED6_on;    break;
  case 7:
     LED7_on;    break;
   }}

 void led_num(u8 t){
    switch(t){
    case 0:
      led_all_off();
      break;
  case 1:
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      break;
  case 2:
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      break;
  case 3:
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
      break;
  case 4:
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
      break;
  case 5:
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_6);
      break;
  case 6:
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_6);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_5);
      break;
  case 7:
      GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_7);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_6);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_5);
      GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
      break;
  case 8:
      led_all_on();    break;
   }
 }