#include "stm32f4xx.h"                  // Device header
#include "led.h"
#include "gpio.h"
#include "car_speed.h"
#include "../../wheel.h"



int main(void){
	//LED;
	GPIO_Config(RCC_AHB1Periph_GPIOA, GPIO_Pin_1);
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
	  Speed_Set1(wheel_leftforward.PWM);
	  Speed_Set2(wheel_rightforward.PWM);
	  Speed_Set3(wheel_leftback.PWM);
	  Speed_Set4(wheel_rightback.PWM);

	LED_ON();

	int lor;
	lor = -1;

	while(1){

		LED_ON();
	};
}
