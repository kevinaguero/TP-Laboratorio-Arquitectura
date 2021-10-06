/*Ejercicio 1
Diseñe e implemente un Firmware sobre la placa STM32F4 - Discovery que controle
de manera secuencial el encendido y apagado de 4 LEDs. El tiempo de encendido/apagado entre cada led
deberá ser 300ms.
Alumno: Aguero Kevin MU: 014563*/

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

#pragma GCC diagnostic push

void main()
{
        HAL_Init();
        Init_GPIO_LEDS();

      while (1)
        {
    	  //Cada led cambia su estado a medida que pasan los 300 ms

    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);	// Led en color verde
    	  HAL_Delay(300);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);	// Led en color anaranjado
    	  HAL_Delay(300);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);	// Led en color rojo
    	  HAL_Delay(300);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);	// Led en color azul
    	  HAL_Delay(300);
    	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
        }
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}

void Init_GPIO_LEDS(void){					//Inicializacion de leds
    GPIO_InitTypeDef GPIO_InitStruct = {0};
        __HAL_RCC_GPIOD_CLK_ENABLE();

        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;//
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

        HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);
}

#pragma GCC diagnostic pop
