/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"

#include <avr/io.h>

#include "extras/serial.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define sbi(x,y) x |= _BV(y) //set bit
#define cbi(x,y) x &= ~(_BV(y)) //clear bit
#define ibi(x,y) x ^= _BV(y) //flip bit

#define my_TASK_PRIORITY   (tskIDLE_PRIORITY)

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vTask1(void* pvParameters);
static void vTask2(void* pvParameters);
static void vTask3(void* pvParameters);

/**************************************************************************//**
 * \fn int main(void)
 *
 * \brief Main function.
 *
 * \return
 ******************************************************************************/


int main(void)
{
    {
        xTaskHandle handle1;
        xTaskHandle handle2;
        xTaskHandle handle3;

        xTaskCreate( vTask1, (signed char*)"task01", configMINIMAL_STACK_SIZE, NULL, my_TASK_PRIORITY + 0, &handle1);
        xTaskCreate( vTask2, (signed char*)"task02", configMINIMAL_STACK_SIZE, NULL, my_TASK_PRIORITY + 1, &handle2);
        xTaskCreate( vTask3, (signed char*)"task03", configMINIMAL_STACK_SIZE, NULL, my_TASK_PRIORITY + 3, &handle3);
    }

    // Start scheduler.
    vTaskStartScheduler();

    return 0;
}

/**************************************************************************//**
 * \fn static vApplicationIdleHook(void)
 *
 * \brief
 ******************************************************************************/

void vApplicationIdleHook(void)
{

}

/******************************************************************************
 * Private function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn static void vBlinkLed(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/

static void vTask1(void* pvParameters)
{
    for(;;)
    {
		//...
    }

    vTaskDelete( NULL);
}

static void vTask2(void* pvParameters)
{
    for(;;)
    {
		//...
    }

    vTaskDelete( NULL);
}

static void vTask3(void* pvParameters)
{
    for(;;)
    {
		//...
    }

    vTaskDelete( NULL);
}
