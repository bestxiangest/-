#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Motor.h"
#include "Sensor.h"
#include "Servo.h"
#include "PWM.h"
#include "Serial.h"

#define smallTurn 18
#define middleTurn 45
#define bigTurn 85

#define MAX_SPEED 1100
#define MIN_SPEED 600

int getSensorState(uint8_t *SensorState);
short canTurn(void);
uint8_t getSensorNum(uint8_t *SensorState);
void Init(void);

int time = 0;

//�Ƕ�
uint8_t Flag = 0;
uint16_t Angle = 90; //��ʼ�Ƕ�
uint16_t LastAngle = 90;
//�ٶ�
int leftSpeed = MAX_SPEED;
int rightSpeed = MAX_SPEED;
//������״̬
uint8_t SensorState[5];  // �Ҷȴ�����״̬

int weight[5] = {10000, 1000, 100, 10, 1};  // ���������������� pow()
int getSensorState(uint8_t *SensorState) {
    // ��ȡ���������ݵĴ���
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        if (SensorState[i] == 1) {
            sum += weight[i];
        }
    }
    return sum;
}


int i = 0;
short canTurn(void){
    i++;
    if(i >= 13){
        i = 0;
        return 1;
    }
    return 0;
}


uint8_t getSensorNum(uint8_t *SensorState){
	uint8_t sum = 0;
	for(int i = 0;i<5;i++){
		if(SensorState[i]){
			sum++;
		}
	}
	return sum;
}



void Init(void){
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Sensor_Init();
	PWM_Motor_Init();
	PWM_Servo_Init();
    Motor_12_Init();
}

int main(void)
{	
	int Angle = 90;
	Init();
	leftSpeed = MAX_SPEED;
	rightSpeed = MAX_SPEED;
	
	Delay_ms(2000);
	
    while(1)
    {   
		SensorState[0] = Sensor0_Get_State();
		SensorState[1] = Sensor1_Get_State();
		SensorState[2] = Sensor2_Get_State();
		SensorState[3] = Sensor3_Get_State();
		SensorState[4] = Sensor4_Get_State();
		
		
		int sensor_state = getSensorState(SensorState);
		switch(sensor_state)
		{
			case 100:  // �м䴫����S3��⵽����
				leftSpeed = MAX_SPEED;//ֱ��
				rightSpeed = MAX_SPEED;
				Angle = 90;  // �����������
				Flag = 0;//0Ϊֱ��
				break;

			case 1000:                           // S2��⵽���ߣ���΢����ƫ
				if(Flag == 0){                      //��ֱ�߹���������С����ƫ
					leftSpeed = MAX_SPEED - 600;     // ��������
					rightSpeed = MAX_SPEED;  
					Angle = 90 + smallTurn;         // �����תС�Ƕ�
					Flag = 1;                       //1ΪС����ת��
				}
				else if(Flag == 3){                //�Ӵ����ת������������з���ƫ
					leftSpeed = MAX_SPEED - 600;    // ��������
					rightSpeed = MAX_SPEED; 
					Angle = 90 + smallTurn;        // �����ת�нǶ�
					Flag = 1;                       //2Ϊ�з���ת��
				}
				else if(Flag == 2){                //���з���ת�����������С����ƫ
					leftSpeed = MAX_SPEED - 600;    // ��������
					rightSpeed = MAX_SPEED;
					Angle = 90 + smallTurn;        // �����תС�Ƕ�
					Flag = 1;//2Ϊ�з���ת��
				}
				else if(Flag == 1){                         //��С����ת�����������С����ƫ
					leftSpeed = MAX_SPEED - 600;     // ��������
					rightSpeed = MAX_SPEED;
					Angle = 90 + smallTurn;         // �����תС�Ƕ�
					Flag = 1;                       //1ΪС����ת��
				}
				break;

			case 10000:  // S1��⵽���ߣ��������ƫ
				if(Flag == 1){//��С����ת���������������ƫ
					leftSpeed = MAX_SPEED - 900;
					rightSpeed = MAX_SPEED -300;
					Angle = 90 + bigTurn;  // ��������ת
					Flag = 3;//3Ϊ�����ת��
				}
				else if(Flag == 3){//�Ӵ����ת������������з���ƫ
					if(canTurn()){
						leftSpeed = MAX_SPEED - 900;
						rightSpeed = MAX_SPEED -300;
						Angle = 90 + middleTurn;  // �����ת
						Flag = 2;//2Ϊ�з���ת��
					}else{
						leftSpeed = MAX_SPEED - 900;
						rightSpeed = MAX_SPEED -300;
						Angle = 90 + bigTurn;  // ��������ת
					}
				}else if(Flag == 2){//���з���ת������������з���ƫ
					leftSpeed = MAX_SPEED - 900;    // ��������
					rightSpeed = MAX_SPEED -300;
					Angle = 90 + middleTurn;  // �����ת
					Flag = 2;//2Ϊ�з���ת��
				}
				break;

			case 10:  // S4��⵽���ߣ�С������ƫ
				if(Flag == 0){                      //��ֱ�߹���������С����ƫ
					leftSpeed = MAX_SPEED;     // �ҵ������
					rightSpeed = MAX_SPEED - 600;  
					Angle = 90 - smallTurn;         // �����תС�Ƕ�
					Flag = 1;                       //1ΪС����ת��
				}
				else if(Flag == 3){                //�Ӵ����ת������������з���ƫ
					leftSpeed = MAX_SPEED;    // �ҵ������
					rightSpeed = MAX_SPEED - 600; 
					Angle = 90 - smallTurn;        // �����ת�нǶ�
					Flag = 1;                       //2Ϊ�з���ת��
				}
				else if(Flag == 2){                //���з���ת�����������С����ƫ
					leftSpeed = MAX_SPEED;    // �ҵ������
					rightSpeed = MAX_SPEED - 600;
					Angle = 90 - smallTurn;        // �����תС�Ƕ�
					Flag = 1;//2Ϊ�з���ת��
				}
				else if(Flag == 1){                         //��С����ת�����������С����ƫ
					leftSpeed = MAX_SPEED;     // �ҵ������
					rightSpeed = MAX_SPEED - 600;
					Angle = 90 - smallTurn;         // �����תС�Ƕ�
					Flag = 1;                       //1ΪС����ת��
				}
				break;

			case 1:  // ��S5��⵽���ߣ�������ƫ
				if(Flag == 1){//��С����ת����������Ҵ����ƫ
					leftSpeed = MAX_SPEED -300;
					rightSpeed = MAX_SPEED - 900;
					Angle = 90 - bigTurn;  // ��������ת
					Flag = 3;//3Ϊ�����ת��
				}
				else if(Flag == 3){//�Ӵ����ת������������з���ƫ
					if(canTurn()){
						leftSpeed = MAX_SPEED -300;
						rightSpeed = MAX_SPEED - 900;
						Angle = 90 - middleTurn;  // �����ת
						Flag = 2;//2Ϊ�з���ת��
					}else{
						leftSpeed = MAX_SPEED -300;
						rightSpeed = MAX_SPEED - 900;
						Angle = 90 - bigTurn;  // ��������ת
					}
				}else if(Flag == 2){//���з���ת������������з���ƫ
					leftSpeed = MAX_SPEED -300;    // �ҵ������
					rightSpeed = MAX_SPEED - 900;
					Angle = 90 - middleTurn;  // �����ת
					Flag = 2;//2Ϊ�з���ת��
				}
				break;

			default:
				Angle = LastAngle;  // �������
				break;
		}
		
        LastAngle = Angle;
		if(Angle >= 175)Angle = 175;
		if(Angle <= 5)Angle = 5;
		
		control_motor(leftSpeed,rightSpeed);
		Servo_Set_Angle(Angle);
		
		if(getSensorNum(SensorState) >= 3 && time >= 35000){
			control_motor(0,0);
			Servo_Set_Angle(90);
			Delay_s(30);
		}
		time ++;
		Delay_ms(1);
    }  
}

/**
  * ��    ����TIM2�жϺ���
  * ��    ������
  * �� �� ֵ����
  * ע������˺���Ϊ�жϺ�����������ã��жϴ������Զ�ִ��
  *           ������ΪԤ����ָ�����ƣ����Դ������ļ�����
  *           ��ȷ����������ȷ���������κβ��죬�����жϺ��������ܽ���
  */
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)		//�ж��Ƿ���TIM2�ĸ����¼��������ж�
	{
		time ++;												//Num�������������ڲ��Զ�ʱ�ж�
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);			//���TIM2�����¼����жϱ�־λ
															//�жϱ�־λ�������
															//�����жϽ��������ϵش�����������������
	}
}
