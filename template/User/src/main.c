#include "stm32f4xx.h"                  // Device header
#include "led.h"
#include "gpio.h"
#include "car_speed.h"
#include "wheel.h"
#include "uart.h"

void USART3_IRQHandler(void){

	uint8_t temp;

	if(USART_GetFlagStatus(USART3, USART_FLAG_RXNE) != RESET){
		temp = USART_ReceiveData(USART3);
		USART3_Send_Byte(USART3, temp);
		//USART3_Send_Byte(USART3, 0x11);
	}
	
	USART_ClearITPendingBit(USART3, USART_IT_RXNE);

}

int main(void){
	//LED;
	GPIO_Config(RCC_AHB1Periph_GPIOA, GPIO_Pin_1);
	
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
		
		Speed_Set1(0);
	  Speed_Set2(0);
	  Speed_Set3(0);
	  Speed_Set4(0);

	LED_ON();

	int lor;
	lor = -1;
	// USART_SendData(UART4, 0x00e1);
	// USART3->DR = (0x00ff & (uint16_t)0x01FF);

	while(1){
		// UART4_Send_Byte(UART4, 0xcf); 
		// USART_SendData(UART4, 0x0101);
		LED_ON();
	};
}
