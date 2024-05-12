/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#define _USE_MATH_DEFINES
#include <math.h>
#include "Codec/CodecDriver.h"
#include "DSP/DSP.h"
#include "IO/IO.h"


/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ShiftRegFDat_Pin GPIO_PIN_13
#define ShiftRegFDat_GPIO_Port GPIOC
#define ShiftRegFStoClk_Pin GPIO_PIN_14
#define ShiftRegFStoClk_GPIO_Port GPIOC
#define ShiftRegFClk_Pin GPIO_PIN_15
#define ShiftRegFClk_GPIO_Port GPIOC
#define ShiftRegLBarDat_Pin GPIO_PIN_0
#define ShiftRegLBarDat_GPIO_Port GPIOC
#define ShiftRegLBarStoClk_Pin GPIO_PIN_2
#define ShiftRegLBarStoClk_GPIO_Port GPIOC
#define ShiftRegLBarClk_Pin GPIO_PIN_3
#define ShiftRegLBarClk_GPIO_Port GPIOC
#define RotEncoderInA_Pin GPIO_PIN_6
#define RotEncoderInA_GPIO_Port GPIOC
#define RotEncoderInA_EXTI_IRQn EXTI9_5_IRQn
#define RotEncoderInB_Pin GPIO_PIN_7
#define RotEncoderInB_GPIO_Port GPIOC
#define RotEncoderInB_EXTI_IRQn EXTI9_5_IRQn
#define RotEncoderButton_Pin GPIO_PIN_8
#define RotEncoderButton_GPIO_Port GPIOC
#define RotEncoderButton_EXTI_IRQn EXTI9_5_IRQn
#define ToggleInput4_Pin GPIO_PIN_9
#define ToggleInput4_GPIO_Port GPIOA
#define ToggleInput3_Pin GPIO_PIN_10
#define ToggleInput3_GPIO_Port GPIOA
#define ToggleInput2_Pin GPIO_PIN_11
#define ToggleInput2_GPIO_Port GPIOA
#define ToggleInput1_Pin GPIO_PIN_12
#define ToggleInput1_GPIO_Port GPIOA
#define ToggleInput8_Pin GPIO_PIN_15
#define ToggleInput8_GPIO_Port GPIOA
#define ToggleInput7_Pin GPIO_PIN_10
#define ToggleInput7_GPIO_Port GPIOC
#define ToggleInput6_Pin GPIO_PIN_11
#define ToggleInput6_GPIO_Port GPIOC
#define ToggleInput5_Pin GPIO_PIN_12
#define ToggleInput5_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
