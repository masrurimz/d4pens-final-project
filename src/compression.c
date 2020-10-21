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
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "compression.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// Data Encoder
const uint8_t compressionDictionaryIndex[] = {
    "0123456789,;"};

const uint8_t compressionDictionary[] = {
    0b0000, 0b0001, 0b0010, 0b0011, 0b0100,
    0b0101, 0b0110, 0b0111, 0b1000, 0b1001,
    [44] = 0b1010,
    [59] = 0b1011};

const uint8_t compressionDictionaryARM[] = {
    ['0'] = 0b0000,
    ['1'] = 0b0001,
    ['2'] = 0b0010,
    ['3'] = 0b0011,
    ['4'] = 0b0100,
    ['5'] = 0b0101,
    ['6'] = 0b0110,
    ['7'] = 0b0111,
    ['8'] = 0b1000,
    ['9'] = 0b1001,
    [','] = 0b1010,
    [';'] = 0b1011};

const uint8_t compressionDictionarySymbol[] = {
    0b1010, 0b1011};

uint8_t compressionData1 = 0, compressionData2 = 0, compressionData2Send = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint16_t compressionEncoder(char dataRaw[], size_t dataRawLen, 
                            char dataEncoded[], size_t dataEncodedStartIndex)
{
    volatile uint8_t compressionData1 = 0, compressionData2 = 0;
    int dataIndex = dataEncodedStartIndex - 1;

    for (size_t i = 0; i < dataRawLen; i += 2)
    {
        compressionData1 = compressionDictionaryARM[(uint8_t)dataRaw[i]];
        compressionData2 = i + 1 < dataRawLen ? compressionDictionaryARM[(uint8_t)dataRaw[i + 1]] : 0;
        dataEncoded[++dataIndex] = (compressionData1 << 4) + compressionData2;
    }
    // dataEncoded[++dataIndex] = '\n';
    dataEncoded[++dataIndex] = '~';
    dataEncoded[++dataIndex] = '\0';
    return dataIndex;
}
/* USER CODE END 0 */

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */