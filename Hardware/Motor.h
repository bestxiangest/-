#ifndef __MOTOR_H
#define __MOTOR_H

void Motor_12_Init(void);
	
void Motor_1_STOP(void);            //���1ֹͣ
void Motor_1_PRun(void);            //���1��ת
void Motor_1_NRun(void);     	    //���1��ת
void Motor_2_PRun(void);            //���2��ת
void Motor_2_NRun(void);    		//���2��ת
void Motor_2_STOP(void);            //���ֹͣ

void control_motor(uint16_t Lspeed,uint16_t Rspeed);

#endif
