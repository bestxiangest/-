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

//角度
uint8_t Flag = 0;
uint16_t Angle = 90; //初始角度
uint16_t LastAngle = 90;
//速度
int leftSpeed = MAX_SPEED;
int rightSpeed = MAX_SPEED;
//传感器状态
uint8_t SensorState[5];  // 灰度传感器状态

int weight[5] = {10000, 1000, 100, 10, 1};  // 用整数数组来代替 pow()
int getSensorState(uint8_t *SensorState) {
    // 读取传感器数据的代码
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
			case 100:  // 中间传感器S3检测到黑线
				leftSpeed = MAX_SPEED;//直行
				rightSpeed = MAX_SPEED;
				Angle = 90;  // 舵机保持中立
				Flag = 0;//0为直线
				break;

			case 1000:                           // S2检测到黑线，稍微向左偏
				if(Flag == 0){                      //从直线过来，向左小幅度偏
					leftSpeed = MAX_SPEED - 600;     // 左电机减速
					rightSpeed = MAX_SPEED;  
					Angle = 90 + smallTurn;         // 舵机左转小角度
					Flag = 1;                       //1为小幅度转向
				}
				else if(Flag == 3){                //从大幅度转向过来，向左中幅度偏
					leftSpeed = MAX_SPEED - 600;    // 左电机减速
					rightSpeed = MAX_SPEED; 
					Angle = 90 + smallTurn;        // 舵机左转中角度
					Flag = 1;                       //2为中幅度转向
				}
				else if(Flag == 2){                //从中幅度转向过来，向左小幅度偏
					leftSpeed = MAX_SPEED - 600;    // 左电机减速
					rightSpeed = MAX_SPEED;
					Angle = 90 + smallTurn;        // 舵机左转小角度
					Flag = 1;//2为中幅度转向
				}
				else if(Flag == 1){                         //从小幅度转向过来，向左小幅度偏
					leftSpeed = MAX_SPEED - 600;     // 左电机减速
					rightSpeed = MAX_SPEED;
					Angle = 90 + smallTurn;         // 舵机左转小角度
					Flag = 1;                       //1为小幅度转向
				}
				break;

			case 10000:  // S1检测到黑线，大幅向左偏
				if(Flag == 1){//从小幅度转向过来，向左大幅度偏
					leftSpeed = MAX_SPEED - 900;
					rightSpeed = MAX_SPEED -300;
					Angle = 90 + bigTurn;  // 舵机大幅左转
					Flag = 3;//3为大幅度转向
				}
				else if(Flag == 3){//从大幅度转向过来，向左中幅度偏
					if(canTurn()){
						leftSpeed = MAX_SPEED - 900;
						rightSpeed = MAX_SPEED -300;
						Angle = 90 + middleTurn;  // 舵机中转
						Flag = 2;//2为中幅度转向
					}else{
						leftSpeed = MAX_SPEED - 900;
						rightSpeed = MAX_SPEED -300;
						Angle = 90 + bigTurn;  // 舵机大幅左转
					}
				}else if(Flag == 2){//从中幅度转向过来，向左中幅度偏
					leftSpeed = MAX_SPEED - 900;    // 左电机减速
					rightSpeed = MAX_SPEED -300;
					Angle = 90 + middleTurn;  // 舵机中转
					Flag = 2;//2为中幅度转向
				}
				break;

			case 10:  // S4检测到黑线，小幅向右偏
				if(Flag == 0){                      //从直线过来，向右小幅度偏
					leftSpeed = MAX_SPEED;     // 右电机减速
					rightSpeed = MAX_SPEED - 600;  
					Angle = 90 - smallTurn;         // 舵机右转小角度
					Flag = 1;                       //1为小幅度转向
				}
				else if(Flag == 3){                //从大幅度转向过来，向右中幅度偏
					leftSpeed = MAX_SPEED;    // 右电机减速
					rightSpeed = MAX_SPEED - 600; 
					Angle = 90 - smallTurn;        // 舵机右转中角度
					Flag = 1;                       //2为中幅度转向
				}
				else if(Flag == 2){                //从中幅度转向过来，向右小幅度偏
					leftSpeed = MAX_SPEED;    // 右电机减速
					rightSpeed = MAX_SPEED - 600;
					Angle = 90 - smallTurn;        // 舵机右转小角度
					Flag = 1;//2为中幅度转向
				}
				else if(Flag == 1){                         //从小幅度转向过来，向右小幅度偏
					leftSpeed = MAX_SPEED;     // 右电机减速
					rightSpeed = MAX_SPEED - 600;
					Angle = 90 - smallTurn;         // 舵机右转小角度
					Flag = 1;                       //1为小幅度转向
				}
				break;

			case 1:  // 仅S5检测到黑线，极大右偏
				if(Flag == 1){//从小幅度转向过来，向右大幅度偏
					leftSpeed = MAX_SPEED -300;
					rightSpeed = MAX_SPEED - 900;
					Angle = 90 - bigTurn;  // 舵机大幅右转
					Flag = 3;//3为大幅度转向
				}
				else if(Flag == 3){//从大幅度转向过来，向右中幅度偏
					if(canTurn()){
						leftSpeed = MAX_SPEED -300;
						rightSpeed = MAX_SPEED - 900;
						Angle = 90 - middleTurn;  // 舵机中转
						Flag = 2;//2为中幅度转向
					}else{
						leftSpeed = MAX_SPEED -300;
						rightSpeed = MAX_SPEED - 900;
						Angle = 90 - bigTurn;  // 舵机大幅右转
					}
				}else if(Flag == 2){//从中幅度转向过来，向右中幅度偏
					leftSpeed = MAX_SPEED -300;    // 右电机减速
					rightSpeed = MAX_SPEED - 900;
					Angle = 90 - middleTurn;  // 舵机中转
					Flag = 2;//2为中幅度转向
				}
				break;

			default:
				Angle = LastAngle;  // 舵机保持
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
  * 函    数：TIM2中断函数
  * 参    数：无
  * 返 回 值：无
  * 注意事项：此函数为中断函数，无需调用，中断触发后自动执行
  *           函数名为预留的指定名称，可以从启动文件复制
  *           请确保函数名正确，不能有任何差异，否则中断函数将不能进入
  */
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)		//判断是否是TIM2的更新事件触发的中断
	{
		time ++;												//Num变量自增，用于测试定时中断
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);			//清除TIM2更新事件的中断标志位
															//中断标志位必须清除
															//否则中断将连续不断地触发，导致主程序卡死
	}
}
