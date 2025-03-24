#ifndef __MOTOR_H
#define __MOTOR_H

void Motor_12_Init(void);
	
void Motor_1_STOP(void);            //电机1停止
void Motor_1_PRun(void);            //电机1正转
void Motor_1_NRun(void);     	    //电机1反转
void Motor_2_PRun(void);            //电机2正转
void Motor_2_NRun(void);    		//电机2反转
void Motor_2_STOP(void);            //电机停止

void control_motor(uint16_t Lspeed,uint16_t Rspeed);

#endif
