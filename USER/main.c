#include "stm32f4xx.h"
#include "delay.h" // ��ʱ�������ڵ�ͷ�ļ�
#include "led.h"
#include "key.h"
#include "exti.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LED_Init(); // ��ʼ��LED�˿�
	LED0 = 0;

	KEY_SW_init();
	EXTI_SW_Init();
	KEY_DIP_init();
	EXTI_DIP_Init();

	while (1);
}

void EXTI0_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line0) != RESET) //�ж�ĳ�����ϵ��ж��Ƿ���
	{
		delay_ms(20);
		LED0 = !LED0;
		EXTI_ClearITPendingBit(EXTI_Line0); //���LINE�ϵ��жϱ�־λ
	}
}

void EXTI4_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line4) != RESET) // �ж�ĳ�����ϵ��ж��Ƿ���
	{
		delay_ms(5);
		LED1 = !LED1;
		EXTI_ClearITPendingBit(EXTI_Line4); // ���LINE�ϵ��жϱ�־λ
	}
}

