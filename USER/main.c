#include <stdio.h>

#include "stm32f4xx.h"
#include "delay.h" // ��ʱ�������ڵ�ͷ�ļ�
#include "led.h"
#include "key.h"
#include "exti.h"
#include "12864.h"

int led_delay = 500;

int main(void)
{
	unsigned char a[20];
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LED_Init(); // ��ʼ��LED�˿�
	pcb_Init(); // ��ʼ��LCD��Ļ
	delay_ms(20);
  lcd_clear(); // ���LCD��Ļ
  delay_ms(10);

	KEY_SW0_init();
	EXTI_SW0_Init();
	KEY_SW1_init();
	EXTI_SW1_Init();
	
	lcd_wstr(1,1,"  Jonbgua");
	lcd_wstr(3,0,"Delay time:");
	sprintf(a, "%d ms", led_delay);
	lcd_wstr(4,2, a);

	while (1) {
		LED0=1;delay_ms(led_delay);LED0=0;delay_ms(led_delay);
		LED1=1;delay_ms(led_delay);LED1=0;delay_ms(led_delay);
		LED2=1;delay_ms(led_delay);LED2=0;delay_ms(led_delay);
		LED3=1;delay_ms(led_delay);LED3=0;delay_ms(led_delay);
		LED4=1;delay_ms(led_delay);LED4=0;delay_ms(led_delay);
		LED5=1;delay_ms(led_delay);LED5=0;delay_ms(led_delay);
		LED6=1;delay_ms(led_delay);LED6=0;delay_ms(led_delay);
		LED7=1;delay_ms(led_delay);LED7=0;delay_ms(led_delay);
	};
}

void EXTI0_IRQHandler(void)
{
	unsigned char a[20];
	if (EXTI_GetITStatus(EXTI_Line0) != RESET) //�ж�ĳ�����ϵ��ж��Ƿ���
	{
		delay_ms(20);
		
		led_delay += 200;
		lcd_clear();
		delay_ms(20);
		lcd_wstr(1,1,"Freq Lower");
		lcd_wstr(3,0,"Delay time:");
		sprintf(a, "%d ms", led_delay);
		lcd_wstr(4,2, a);
		
		EXTI_ClearITPendingBit(EXTI_Line0); //���LINE�ϵ��жϱ�־λ
	}
}

void EXTI1_IRQHandler(void)
{
	unsigned char a[20];
	if (EXTI_GetITStatus(EXTI_Line1) != RESET) // �ж�ĳ�����ϵ��ж��Ƿ���
	{
		delay_ms(20);
		
		led_delay -= 200;
		if (led_delay < 0) led_delay = 0;
		lcd_clear();
		delay_ms(20);
		
		lcd_wstr(1,1,"Freq Higher");
		lcd_wstr(3,0,"Delay time:");
		sprintf(a, "%d ms", led_delay);
		lcd_wstr(4,2, a);
		
		EXTI_ClearITPendingBit(EXTI_Line0); //���LINE�ϵ��жϱ�־λ
		
		EXTI_ClearITPendingBit(EXTI_Line1); // ���LINE�ϵ��жϱ�־λ
	}
}

