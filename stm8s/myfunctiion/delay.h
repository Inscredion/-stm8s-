#ifndef __DELAY_H__
#define __DELAY_H__
#include "stm8s.h"
//以上是为了防止头文件被多次包含，可以省略，最好有，名字任意，保证唯一即可
void delay_us(u16 i);

void delay_s(u16 i);



#endif