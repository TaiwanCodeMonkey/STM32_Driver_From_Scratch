#include <stm32f446re_gpio_driver.h>

/*
 * Peripheral Clock setup
 */

/***************************************************************
 * @fn                  - GPIO_PeriClockControl
 * 
 * @brief               - This functions enables or disables peripheral clock for the given GPIO port
 * 
 * @param pGPIOx        - base address of the GPIO peripheral  
 * @param EnorDi        - ENABLE or DISABLE macros
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void GPIO_PeriClockControl(GPIO_RegDef_t* pGPIOx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE) {
        if (pGPIOx == GPIOA)
            GPIOA_PCLK_EN();
        else if (pGPIOx == GPIOB)
            GPIOB_PCLK_EN();
        else if (pGPIOx == GPIOC)
            GPIOC_PCLK_EN();
        else if (pGPIOx == GPIOD)
            GPIOD_PCLK_EN();
        else if (pGPIOx == GPIOE)
            GPIOE_PCLK_EN();
        else if (pGPIOx == GPIOF)
            GPIOF_PCLK_EN();
        else if (pGPIOx == GPIOG)
            GPIOG_PCLK_EN();
        else
            GPIOH_PCLK_EN();
    }
    else {
        if (pGPIOx == GPIOA)
            GPIOA_PCLK_DIS();
        else if (pGPIOx == GPIOB)
            GPIOB_PCLK_DIS();
        else if (pGPIOx == GPIOC)
            GPIOC_PCLK_DIS();
        else if (pGPIOx == GPIOD)
            GPIOD_PCLK_DIS();
        else if (pGPIOx == GPIOE)
            GPIOE_PCLK_DIS();
        else if (pGPIOx == GPIOF)
            GPIOF_PCLK_DIS();
        else if (pGPIOx == GPIOG)
            GPIOG_PCLK_DIS();
        else
            GPIOH_PCLK_DIS();
    }
}

/***************************************************************
 * @fn                  - GPIO_Init
 * 
 * @brief               - 
 * 
 * @param pGPIOHandle   - Configuration Structure  
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void GPIO_Init(GPIO_Handle_t* pGPIOHandle)
{
    uint32_t temp = 0;
    GPIO_PeriClockControl(pGPIOHandle -> pGPIOx, ENABLE);
    if (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG) {
        // the non interrupt mode
        temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
        pGPIOHandle -> pGPIOx -> MODER &= ~(0x3 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
        pGPIOHandle -> pGPIOx -> MODER |= temp;
        temp = 0;
    }
    else {
        if (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT) {
            EXTI -> FTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
            EXTI -> RTSR &= ~(1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
        }
        else if (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT) {
            EXTI -> RTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
            EXTI -> FTSR &= ~(1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
        }
        else if (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RFT) {
            EXTI -> RTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
            EXTI -> FTSR |= (1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
        }
        uint8_t temp1 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber / 4;
        uint8_t temp2 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber % 4;
        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIOHandle -> pGPIOx);
        SYSCFG_CLC_EN();
        SYSCFG -> EXTICR[temp1] = portcode << (temp2 * 4);
        EXTI -> IMR |= 1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber;
    }
    temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle -> pGPIOx -> OSPEEDR &= ~(0x3 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle -> pGPIOx -> OSPEEDR |= temp;
    temp = 0;

    temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle -> pGPIOx -> PUPDR &= ~(0x3 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber); // clearing
    pGPIOHandle -> pGPIOx -> PUPDR |= temp;
    temp = 0;

    temp = pGPIOHandle -> GPIO_PinConfig.GPIO_PinOPType << (1 * pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber);
    pGPIOHandle -> pGPIOx -> OTYPER &= ~(0x1 << pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber); // clearing
    pGPIOHandle -> pGPIOx -> OTYPER |= temp;
    temp = 0;

    if (pGPIOHandle -> GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN) {
        uint32_t temp1, temp2;
        temp1 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber / 8;
        temp2 = pGPIOHandle -> GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIOHandle -> pGPIOx -> AFR[temp1] &= ~(0xF << (4 * temp2));
        pGPIOHandle -> pGPIOx -> AFR[temp1] |= (pGPIOHandle -> GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
    }

    
}

/***************************************************************
 * @fn                  - GPIO_DeInit
 * 
 * @brief               - 
 * 
 * @param pGPIOx        - base address of the GPIO peripheral  
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void GPIO_DeInit(GPIO_RegDef_t* pGPIOx) {
    if (pGPIOx == GPIOA)
        GPIOA_REG_RESRT();
    else if (pGPIOx == GPIOB)
        GPIOB_REG_RESRT();
    else if (pGPIOx == GPIOC)
        GPIOC_REG_RESRT();
    else if (pGPIOx == GPIOD)
        GPIOD_REG_RESRT();
    else if (pGPIOx == GPIOE)
        GPIOE_REG_RESRT();
    else if (pGPIOx == GPIOF)
        GPIOF_REG_RESRT();
    else if (pGPIOx == GPIOG)
        GPIOG_REG_RESRT();
    else if (pGPIOx == GPIOH)
        GPIOH_REG_RESRT();

}

/*
 * Data read and write
*/

/***************************************************************
 * @fn                  - GPIO_ReadFromInputPin
 * 
 * @brief               - 
 * 
 * @param pGPIOx        - base address of the GPIO peripheral  
 * @param PinNumber     - PinNumber 
 * @param[in]           - 
 * 
 * @return              -  0 or 1
 * 
 * @Note                -  none
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber)
{
   uint8_t value;
   value = (uint8_t)(pGPIOx -> IDR >> PinNumber) & (0x00000001);
   return value;
}

/***************************************************************
 * @fn                  - GPIO_ReadFromInputPort
 * 
 * @brief               - 
 * 
 * @param pGPIOx        - base address of the GPIO peripheral  
 * 
 * @return              -  0 or 1
 * 
 * @Note                -  none
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t* pGPIOx)
{

    uint16_t value;
    value = (uint16_t)(pGPIOx -> IDR);
    return value;
}

/***************************************************************
 * @fn                  - GPIO_WriteToOutputPin
 * 
 * @brief               - 
 * 
 * @param pGPIOx        - base address of the GPIO peripheral  
 * @param PinNumber     - PinNumber
 * @param Value         - Data to be write 
 * 
 * @return              -  
 * 
 * @Note                -  none
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber, uint8_t Value)
{
    if (Value == GPIO_PIN_RESET) {
        pGPIOx -> ODR |= (1 << PinNumber);
    }
    else {
        pGPIOx -> ODR &= ~(1 << PinNumber);
    }

}

/***************************************************************
 * @fn                  - GPIO_WriteToOutputPort
 * 
 * @brief               - 
 * 
 * @param pGPIOx        - base address of the GPIO peripheral  
 * @param Value         - Data to be write 
 * 
 * @return              -  
 * 
 * @Note                -  none
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t* pGPIOx, uint16_t Value)
{
    pGPIOx -> ODR = Value;
}

/***************************************************************
 * @fn                  - GPIO_ToggleOutputPin
 * 
 * @brief               - 
 * 
 * @param pGPIOx        - base address of the GPIO peripheral  
 * @param PinNumber     - PinNumber
 * 
 * @return              -  
 * 
 * @Note                -  none
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber)
{
    pGPIOx -> ODR ^= (1 << PinNumber);
    // pGPIOx -> ODR.B.ODR5 ^= 1;
}
/*
 * IRQ Configuration and ISR handling
*/

/***************************************************************
 * @fn                  - GPIO_IRQConfig
 * 
 * @brief               - 
 * 
 * @param[in]           -  
 * @param[in]           - 
 * @param[in]           - 
 * 
 * @return              -  
 * 
 * @Note                -  none
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{
    if (EnorDi == ENABLE)
    {
        if (IRQNumber <= 31) {
            // program ISER0 register
            *NVIC_ISER0 |= (1 << IRQNumber);
        }
        else if (IRQNumber > 31 && IRQNumber < 64) {
            *NVIC_ISER1 |= (1 << (IRQNumber % 32));
            // program ISER1 register
        }
        else if (IRQNumber >= 64 && IRQNumber < 96) {
            *NVIC_ISER3 |= (1 << (IRQNumber % 64));
            // program ISER2 register // 64 to 95
        }
    }
    else {
        if (IRQNumber <= 31) {
            *NVIC_ICER0 |= (1 << IRQNumber);
        }
        else if (IRQNumber > 31 && IRQNumber < 64) {
            // *NVIC_ICER1 |= (1 << (IRQNumber % 32));
            // program ICER0 register
        }
        else if (IRQNumber >= 64 && IRQNumber < 96) {
            *NVIC_ICER3 |= (1 << (IRQNumber % 64));
        }
    }
}

/***************************************************************
 * @fn                  - GPIO_PriorityConfig
 * 
 * @brief               - 
 * 
 * @param[in]           -  
 * @param[in]           - 
 * @param[in]           - 
 * 
 * @return              -  
 * 
 * @Note                -  none
 */
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPiority) {

    // 1. first lets find out the IPR register
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;
    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
    *(NVIC_PR_BASE_ADDR + iprx) |= IRQPiority << (shift_amount);
}
void GPIO_IRQHandling(uint8_t PinNumber) {

    // clear the exti PR Register corresponding to the pin number
    if (EXTI -> PR & (1 << PinNumber)) {
        EXTI -> PR |= (1 << PinNumber);
    }
}
