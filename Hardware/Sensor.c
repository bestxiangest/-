#include "stm32f10x.h"                  // Device header

/*
    SENSOR0(B3)  SENSOR1(B4)  SENSOR2(B5)  SENSOR3(B6)  SENSOR4(B7)
*/
void Sensor_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7; // 初始化五个引脚
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // GPIO速度
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

// 获取传感器状态
uint8_t Sensor0_Get_State()
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4); // 读取传感器0状态
}

uint8_t Sensor1_Get_State()
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5); // 读取传感器1状态
}

uint8_t Sensor2_Get_State()
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6); // 读取传感器2状态
}

uint8_t Sensor3_Get_State()
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7); // 读取传感器3状态
}

uint8_t Sensor4_Get_State()
{
    return GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8); // 读取传感器4状态
}


