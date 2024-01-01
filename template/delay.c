#include "stm32f4xx.h"                  // Device header
#include "delay.h"

void delay_ms(u16 ms) {
	
	u32 temp;
	SysTick->LOAD = 21000*ms;
	SysTick->VAL = 0x00;
	SysTick->CTRL = 0x01;
	
	do {
		temp = SysTick->CTRL;
	} while((temp&0x01)&&(!(temp&(1<<16))));
	
	SysTick->CTRL = 0x00;
	SysTick->VAL = 0x00;
	
}