
#ifndef __MAIN_H
#define __MAIN_H
#ifdef __cplusplus

extern "C" {
#endif

#include "stm32f4xx_hal.h"



void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define builtin_LED_Pin GPIO_PIN_13
#define builtin_LED_GPIO_Port GPIOC
#define push_Button_Pin GPIO_PIN_2
#define push_Button_GPIO_Port GPIOA
#define push_Button_EXTI_IRQn EXTI2_IRQn
#define mode_Button_Pin GPIO_PIN_3
#define mode_Button_GPIO_Port GPIOA
#define ir_Sensor_Pin GPIO_PIN_2
#define ir_Sensor_GPIO_Port GPIOB
#define servo_PWM_Pin GPIO_PIN_8
#define servo_PWM_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif


