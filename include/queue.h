/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __queue_H
#define __queue_H
#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

  /* USER CODE BEGIN Includes */

  /* USER CODE END Includes */

  /* Exported variable ------------------------------------------------------------*/
  /* USER CODE BEGIN EV */
  // Queue Variable
  extern volatile uint16_t queueBuffer[500][2];
  extern volatile uint16_t queueTail;
  /* USER CODE END ET */

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
  /* USER CODE BEGIN EFP */
  void queueInsertTail(uint16_t *d);
  void queueResetTail();
  /* USER CODE END EFP */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
