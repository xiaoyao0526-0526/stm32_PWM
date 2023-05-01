/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define MOTOR_A_H HAL_GPIO_WritePin(MOTOR_A_GPIO_Port, MOTOR_A_Pin, GPIO_PIN_SET)
#define MOTOR_A_L HAL_GPIO_WritePin(MOTOR_A_GPIO_Port, MOTOR_A_Pin, GPIO_PIN_RESET)

#define MOTOR_B_H HAL_GPIO_WritePin(MOTOR_B_GPIO_Port, MOTOR_B_Pin, GPIO_PIN_SET)
#define MOTOR_B_L HAL_GPIO_WritePin(MOTOR_B_GPIO_Port, MOTOR_B_Pin, GPIO_PIN_RESET)

#define MOTOR_C_H HAL_GPIO_WritePin(MOTOR_C_GPIO_Port, MOTOR_C_Pin, GPIO_PIN_SET)
#define MOTOR_C_L HAL_GPIO_WritePin(MOTOR_C_GPIO_Port, MOTOR_C_Pin, GPIO_PIN_RESET)

#define MOTOR_D_H HAL_GPIO_WritePin(MOTOR_D_GPIO_Port, MOTOR_D_Pin, GPIO_PIN_SET)
#define MOTOR_D_L HAL_GPIO_WritePin(MOTOR_D_GPIO_Port, MOTOR_D_Pin, GPIO_PIN_RESET)

/* USER CODE END Private defines */


/* USER CODE BEGIN Prototypes */
void MOTOR_CONTRAL(uint8_t direction);
void Step_Motor_Start(uint16_t angle, uint8_t direction);
void Step_Motor_Stop(void);
/* USER CODE END Private defines */

void MX_GPIO_Init(void);


#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

