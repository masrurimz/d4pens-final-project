/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : communication.c
  * @brief          : communication program body
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "queue.h"

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

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
volatile uint16_t queueBuffer[500][2];
volatile uint16_t queueTail = 0;
volatile uint16_t queueHead = 0;
const uint16_t queueSize = 500 - 1;

/* USER CODE END 0 */
void queueInsertTail(uint16_t *d)
{
    for (size_t i = 0; i < 2; i++)
    {
        queueBuffer[queueTail][i] = d[i];
    }
    if (++queueTail > queueSize)
    {
        queueTail = 0;
    }
}

void queueResetTail()
{
    queueTail = 0;
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */