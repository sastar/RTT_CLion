/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */

/* USER CODE END Header */
#define LOG_TAG "main"

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "rtthread.h"
#include "ulog.h"

static void tled(int argc, char **argv) {
    if (argc != 2) {
        log_d("argument count must 2");
        return;
    }

    if (rt_strncmp(argv[1], "red", 3) == 0) {
        HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
        log_d("toggled red %s", argv[1]);

    } else if (rt_strncmp(argv[1], "green", 5) == 0) {
        HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
        log_d("toggled green %s", argv[1]);

    } else if (rt_strncmp(argv[1], "blue", 4) == 0) {
        HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
        log_d("toggled blue %s", argv[1]);
    } else {
        log_d("arg error");
    }
}
MSH_CMD_EXPORT(tled, toggle led);

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
    ulog_init();

    LOG_D("Hello ulog");


    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        // 释放CPU控制权
        rt_thread_mdelay(1000);
    }
}


/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state
     */

    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line) {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line
       number, tex: printf("Wrong parameters value: file %s on line %d\r\n",
       file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
