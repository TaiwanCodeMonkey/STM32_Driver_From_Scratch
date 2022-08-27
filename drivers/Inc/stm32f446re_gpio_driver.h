#ifndef INC_STM32F446RE_GPIO_DRIVER_H_
#define INC_STM32F446RE_GPIO_DRIVER_H_


#include "stm32f446re.h"
#include "STM_GPIO_regdef.h"

typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;
    uint8_t GPIO_PinPuPdControl;
    uint8_t GPIO_PinOPType;
    uint8_t GPIO_PinAltFunMode; 
}GPIO_PinConfig_t;

typedef struct
{
    GPIO_RegDef_t* pGPIOx;   // the base address of the GPIO port to which the pin belongs
    GPIO_PinConfig_t GPIO_PinConfig;   // this holds GPIO pin configuration settings
}GPIO_Handle_t;

// typedef struct
// {
//     STM_GPIO* pGPIOx;   // the base address of the GPIO port to which the pin belongs
//     GPIO_PinConfig_t GPIO_PinConfig;   // this holds GPIO pin configuration settings
// }GPIO_Handle_t;
/*
 * GPIO pin possiable modes
 */
#define GPIO_MODE_INPUT   0
#define GPIO_MODE_OUT     1 
#define GPIO_MODE_ALTFN   2 
#define GPIO_MODE_ANALOG  3
#define GPIO_MODE_IT_FT   4
#define GPIO_MODE_IT_RT   5
#define GPIO_MODE_IT_RFT  6
#define GPIO_NO_PUPD      0
/*
 * GPIO PIN possible output types
*/
#define GPIO_OP_TYPE_PP   0
#define GPIO_OP_TYPE_OD   1

/*
 * GPIO PIN possible output speeds
*/

#define GPIO_SPEED_LOW      0
#define GPIO_SPEED_MEDIUM   1
#define GPIO_SPEED_FAST     2
#define GPIO_SPEED_HIGH     3

/*
* GPIO PIN possible pull-up/pull-down
*/
#define GPIO_NO_PULLUP_PULLDOWN  0
#define GPIO_PULLUP              1
#define GPIO_PULLDOWN            2
#define GPIO_RESERVED            3

/* 
* GPIO PIN alternate function configure
*/
#define AF0                      0
#define AF1                      1
#define AF2                      2
#define AF3                      3
#define AF4                      4
#define AF5                      5
#define AF6                      6
#define AF7                      7
#define AF8                      8
#define AF9                      9
#define AF10                     10
#define AF11                     11
#define AF12                     12
#define AF13                     13
#define AF14                     14
#define AF15                     15

/**********************************************************************
 *             APIs supported by this driver
 *       For more information about the APIs check the function definitions
 **********************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t* pGPIOx, uint8_t EnorDi);

/*
 * Init and De-Init
*/
void GPIO_Init(GPIO_Handle_t* pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t* pGPIOx) ;

/*
 * Data read and write
*/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t* pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t* pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber);
/*
 * IRQ Configuration and ISR handling
*/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPiority);
void GPIO_IRQHandling(uint8_t PinNumber);
#endif /* INC_STM32F446RE_GPIO_DRIVER_H_ */
