#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_12_Init(void)//�����ʼ��
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	PWM_Motor_Init();
}

 void Motor_1_STOP(void)              //���1ֹͣ
{
 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}

void Motor_1_PRun(void)           //���1��ת(left)
{
 GPIO_SetBits(GPIOB,GPIO_Pin_13);
 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void Motor_1_NRun(void)     //���1��ת
{
 GPIO_SetBits(GPIOB,GPIO_Pin_12);
 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}


void Motor_2_PRun(void)           //���2��ת(right)
{
 GPIO_SetBits(GPIOB,GPIO_Pin_14);
 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}

void Motor_2_NRun(void)     //���2��ת
{
 GPIO_SetBits(GPIOB,GPIO_Pin_15);
 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
}

void Motor_2_STOP(void)              //���ֹͣ
{
 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}

void control_motor(int16_t Lspeed,int16_t Rspeed)
{		
	Motor_1_NRun();//��ת
	Motor_2_NRun();//��ת
	TIM_SetCompare3(TIM3,Lspeed);//��
	TIM_SetCompare4(TIM3,Rspeed+90);//��
}
