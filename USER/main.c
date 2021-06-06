#include "stm32f4xx.h"
#include "delay.h" // 延时函数所在的头文件
#include "led.h"
#include "key.h"
#include "exti.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LED_Init(); // 初始化LED端口
	LED0 = 0;

	KEY_SW_init();
	EXTI_SW_Init();
	KEY_DIP_init();
	EXTI_DIP_Init();

	while (1);
}

void EXTI0_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line0) != RESET) //判断某个线上的中断是否发生
	{
		delay_ms(20);
		LED0 = !LED0;
		EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE上的中断标志位
	}
}

void EXTI4_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line4) != RESET) // 判断某个线上的中断是否发生
	{
		delay_ms(5);
		LED1 = !LED1;
		EXTI_ClearITPendingBit(EXTI_Line4); // 清除LINE上的中断标志位
	}
}

