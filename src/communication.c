/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : communication.c
  * @brief          : communication program body
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "communication.h"
#include "usart.h"
#include "printf.h"
#include "queue.h"
#include "adc.h"
#include "tim.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define dataReqLen 100
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t commCommand;
uint8_t commRxData;
char commBuffer[10];
volatile unsigned char buf[16 * 500];
volatile uint32_t commData2SendLen;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void commMainHandler();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void commADCData_SendasString()
{
    data2SendLen = sprintf_(
        data2Send,
        "%04u,%04u,%04u,%04u,%04u,%04u,%04u,%04u;",
        adcRaw[0], adcRaw[1], adcRaw[2], adcRaw[3],
        adcRaw[4], adcRaw[5], adcRaw[6], adcRaw[7]);
    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)data2Send, data2SendLen);
}

/**
  * @brief  Send data to the UART using DMA controller as Bytes
  * @param  data  Pointer to a data to be send
  * @param  dataLen Langth of data variable to be sent
  * @param  dataByteSize Sigle variable size in bytes
  * @retval none
  */
void commSendasBytes(uint16_t *data, uint32_t dataLen, uint8_t dataByteSize)
{
    uint8_t *byteData = (uint8_t *)(data);
    for (size_t i = 0; i < dataLen * dataByteSize; i++)
    {
        buf[i] = byteData[i];
    }
    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buf, (dataLen * dataByteSize));
}

void commListening()
{
    HAL_UART_Receive_IT(&huart1, &commRxData, 1);
}

void commRxHandler()
{
    commCommand = commRxData;
    // HAL_UART_Transmit(&huart1, (uint8_t *)commBuffer,
    //                   sprintf_(commBuffer, "%c", commRxData), 1);
    commListening();
    commMainHandler();
}

void commMainHandler()
{
    if (commCommand == 'g')
    {
        HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adcRaw, 8);
        HAL_TIM_Base_Start_IT(&htim3);
        // data2SendLen = queueTail * 8;
        // commSendasBytes((uint16_t *)queueBuffer, data2SendLen, 2);
        // queueResetTail();
        HAL_GPIO_WritePin(pinLed_GPIO_Port, pinLed_Pin, GPIO_PIN_RESET);
    }
    else if (commCommand == 's')
    {
        HAL_TIM_Base_Stop_IT(&htim3);
        HAL_ADC_Stop_DMA(&hadc1);
        queueResetTail();
        HAL_GPIO_WritePin(pinLed_GPIO_Port, pinLed_Pin, GPIO_PIN_SET);
    }
}
/* USER CODE END 0 */

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */