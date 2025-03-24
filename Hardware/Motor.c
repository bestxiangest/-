#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_12_Init(void)//电机初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	PWM_Motor_Init();
}

 void Motor_1_STOP(void)              //电机1停止
{
 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}

void Motor_1_PRun(void)           //电机1反转(left)
{
 GPIO_SetBits(GPIOB,GPIO_Pin_13);
 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void Motor_1_NRun(void)     //电机1正转
{
 GPIO_SetBits(GPIOB,GPIO_Pin_12);
 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}


void Motor_2_PRun(void)           //电机2反转(right)
{
 GPIO_SetBits(GPIOB,GPIO_Pin_14);
 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}

void Motor_2_NRun(void)     //电机2正转
{
 GPIO_SetBits(GPIOB,GPIO_Pin_15);
 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
}

void Motor_2_STOP(void)              //电机停止
{
 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}

void control_motor(int16_t Lspeed,int16_t Rspeed)
{		
	Motor_1_NRun();//正转
	Motor_2_NRun();//正转
	TIM_SetCompare3(TIM3,Lspeed);//左
	TIM_SetCompare4(TIM3,Rspeed+90);//右
}
