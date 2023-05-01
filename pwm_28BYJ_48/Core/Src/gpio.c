/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, MOTOR_A_Pin|MOTOR_B_Pin|MOTOR_C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(MOTOR_D_GPIO_Port, MOTOR_D_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = MOTOR_A_Pin|MOTOR_B_Pin|MOTOR_C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = MOTOR_D_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(MOTOR_D_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
void MOTOR_CONTRAL(uint8_t direction)
{
	static uint8_t step = 0;
	if(1 == direction){
		if(0 == step) step = 8;
		step--;
	}
	if(0 == step){
		MOTOR_A_H;
		MOTOR_B_L;
		MOTOR_C_L;
		MOTOR_D_L;
	}else if(1 == step){
		MOTOR_A_H;
		MOTOR_B_H;
		MOTOR_C_L;
		MOTOR_D_L;
	}else if(2 == step){
		MOTOR_A_L;
		MOTOR_B_H;
		MOTOR_C_L;
		MOTOR_D_L;
	}else if(3 == step){
		MOTOR_A_L;
		MOTOR_B_H;
		MOTOR_C_H;
		MOTOR_D_L;
	}else if(4 == step){
		MOTOR_A_L;
		MOTOR_B_L;
		MOTOR_C_H;
		MOTOR_D_L;
	}else if(5 == step){
		MOTOR_A_L;
		MOTOR_B_L;
		MOTOR_C_H;
		MOTOR_D_H;
	}else if(6 == step){
		MOTOR_A_L;
		MOTOR_B_L;
		MOTOR_C_L;
		MOTOR_D_H;
	}else if(7 == step){
		MOTOR_A_H;
		MOTOR_B_L;
		MOTOR_C_L;
		MOTOR_D_H;
	}
	if(0 == direction){
		step++; if(8 == step) step = 0;
	}
}

void Step_Motor_Start(uint16_t angle, uint8_t direction){
	int i = 0;
	int pulse = (int)((double)(angle/5.625)*64);
	for(i = 0; i<pulse; i++){
		MOTOR_CONTRAL(direction);
		HAL_Delay(2);
	}
}

void Step_Motor_Stop(void){
	MOTOR_A_L;
	MOTOR_B_L;
	MOTOR_C_L;
	MOTOR_D_L;
}
/* USER CODE END 2 */
