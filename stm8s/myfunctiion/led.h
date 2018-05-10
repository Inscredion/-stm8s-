
#ifndef __LED_H__
#define __LED_H__
#include "stm8s_gpio.h"
//以上是为了防止头文件被多次包含，可以省略，最好有，名字任意，保证唯一即可

#define LED0_on GPIO_WriteHigh(GPIOD,GPIO_PIN_3)
#define LED0_off GPIO_WriteLow(GPIOD,GPIO_PIN_3)

#define LED1_on GPIO_WriteHigh(GPIOD,GPIO_PIN_2)
#define LED1_off GPIO_WriteLow(GPIOD,GPIO_PIN_2)

#define LED2_on GPIO_WriteHigh(GPIOD,GPIO_PIN_4)
#define LED2_off GPIO_WriteLow(GPIOD,GPIO_PIN_4)

#define LED3_on GPIO_WriteHigh(GPIOC,GPIO_PIN_7)
#define LED3_off GPIO_WriteLow(GPIOC,GPIO_PIN_7)

#define LED4_on GPIO_WriteHigh(GPIOC,GPIO_PIN_6)
#define LED4_off GPIO_WriteLow(GPIOC,GPIO_PIN_6)

#define LED5_on GPIO_WriteHigh(GPIOC,GPIO_PIN_5)
#define LED5_off GPIO_WriteLow(GPIOC,GPIO_PIN_5)

#define LED6_on GPIO_WriteHigh(GPIOC,GPIO_PIN_4)
#define LED6_off GPIO_WriteLow(GPIOC,GPIO_PIN_4)

#define LED7_on GPIO_WriteHigh(GPIOC,GPIO_PIN_3)
#define LED7_off GPIO_WriteLow(GPIOC,GPIO_PIN_3)

#define LED_delay_on GPIO_WriteHigh(GPIOD,GPIO_PIN_6)
#define LED_delay_off GPIO_WriteLow(GPIOD,GPIO_PIN_6)

#define LED_amp_on GPIO_WriteHigh(GPIOA,GPIO_PIN_3)
#define LED_amp_off GPIO_WriteLow(GPIOA,GPIO_PIN_3)


void led_conf();
void led_all_on();
void led_all_off();
void led_control(u8 t);
void led_select(u8 t);
void led_num(u8 t);

#endif