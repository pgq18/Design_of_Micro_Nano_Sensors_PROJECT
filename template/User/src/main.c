#include "stm32f4xx.h"                  // Device header
#include "led.h"
#include "gpio.h"
#include "car_speed.h"
#include "wheel.h"
#include "uart.h"
#include "delay.h"

int stop;

void USART3_IRQHandler(void){

	uint8_t temp;
  
	if(USART_GetFlagStatus(USART3, USART_FLAG_RXNE) != RESET){
		temp = USART_ReceiveData(USART3);
		//USART3_Send_Byte(USART3, temp);
		//USART3_Send_Byte(USART3, 0x11);
	}
	
	USART_ClearITPendingBit(USART3, USART_IT_RXNE);
//	Speed_Stop();
	
	if(stop == 1) {
		if(temp != 0x3){
			Speed_Stop_to_Start();
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			GPIO_SetBits(GPIOD, GPIO_Pin_10);
			GPIO_SetBits(GPIOD, GPIO_Pin_8);
			stop = 0;
		}
		else {
			stop = 1;
		}
	}
	else {
		switch (temp){
			case 0x1:
				Speed_Up();
			  GPIO_SetBits(GPIOD, GPIO_Pin_12); // G
				break;
			case 0x2:
				Speed_Down();
				GPIO_SetBits(GPIOD, GPIO_Pin_10); // Y
				break;
			case 0x3:
				Speed_Stop();
				GPIO_SetBits(GPIOD, GPIO_Pin_8);// R
				stop = 1;
				break;
			case 0x4:
				Turn_Left();
				break;
			case 0x5:
				Turn_Right();
				break;
			default:
				break;
		}
	}
}

int main(void){
	//LED;
	GPIO_Config(RCC_AHB1Periph_GPIOA, GPIO_Pin_1);
	GPIO_Config(RCC_AHB1Periph_GPIOD, GPIO_Pin_8); // R
	GPIO_Config(RCC_AHB1Periph_GPIOD, GPIO_Pin_10); // Y
	GPIO_Config(RCC_AHB1Periph_GPIOD, GPIO_Pin_12); // G
	
	//GPIO_SetBits(GPIOD, GPIO_Pin_8);// R
	//GPIO_SetBits(GPIOD, GPIO_Pin_10);// Y
	//GPIO_SetBits(GPIOD, GPIO_Pin_12); // G
	
	//UART4
	USART3_NVIC_Config();
	USART3_Config();
	
	//buttom
  wheel wheel_leftforward;
	wheel wheel_rightforward;
	wheel wheel_leftback;
	wheel wheel_rightback;
	int distance_forward;
	int distance_left;
	int distance_right;


  initialize_wheel(&wheel_leftforward);
	initialize_wheel(&wheel_rightforward);
	initialize_wheel(&wheel_leftback);
	initialize_wheel(&wheel_rightback);




	  PWM_Config();
//	  Speed_Set1(wheel_leftforward.PWM);
//	  Speed_Set2(wheel_rightforward.PWM);
//	  Speed_Set3(wheel_leftback.PWM);
//	  Speed_Set4(wheel_rightback.PWM);
		
	delay_ms(500);
	delay_ms(500);
	delay_ms(500);
	delay_ms(500);
	delay_ms(500);
	delay_ms(500);
	Speed_Start();
	stop = 0;
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	Turn_Left();
//	Speed_Up();
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//  Speed_Down();
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	Turn_Right();
//	delay_ms(500);
//	delay_ms(500);
//	delay_ms(500);
//	Speed_Stop();
	
	while(1){
		delay_ms(500);
		delay_ms(500);
		LED_ON();
		delay_ms(500);
		delay_ms(500);
		LED_OFF();
	  GPIO_ResetBits(GPIOD, GPIO_Pin_8);// R
	  GPIO_ResetBits(GPIOD, GPIO_Pin_10);// Y
	  GPIO_ResetBits(GPIOD, GPIO_Pin_12); // G
	};
}
