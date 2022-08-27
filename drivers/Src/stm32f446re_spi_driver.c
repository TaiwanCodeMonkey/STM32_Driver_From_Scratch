#include "stm32f446re_spi_driver.h"
static void spi_txe_interupt_handler(SPI_Handle_t *pSPIHandle);
static void spi_rxne_interupt_handler(SPI_Handle_t *pSPIHandle);
static void spi_err_interupt_handler(SPI_Handle_t *pSPIHandle);
/***************************************************************
 * @fn                  - SPI_PeriClockControl
 * 
 * @brief               - This functions enables or disables peripheral clock for the given SPI
 * 
 * @param[in]           - base address of the SPI peripheral  
 * @param[in]           - ENABLE or DISABLE macros
 * @param[in]           - 
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void SPI_PeriClockControl(SPI_RegDef_t* pSPIx, uint8_t EnorDi)
{
    if (EnorDi == ENABLE) {
        if (pSPIx == SPI1)
            SPI1_PCLK_EN();
        else if (pSPIx == SPI2)
            SPI2_PCLK_EN();
        else if (pSPIx == SPI3)
            SPI3_PCLK_EN();
        else if (pSPIx == SPI4)
            SPI4_PCLK_EN();
    }
    else {
        if (pSPIx == SPI1)
            SPI1_PCLK_DIS();
        else if (pSPIx == SPI2)
            SPI2_PCLK_DIS();
        else if (pSPIx == SPI3)
            SPI3_PCLK_DIS();
        else if (pSPIx == SPI4)
            SPI4_PCLK_DIS();
    }
}

/***************************************************************
 * @fn                  - SPI_Init
 * 
 * @brief               - 
 * 
 * @param[in]           -  base address of the SPI peripheral 
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void SPI_Init(SPI_Handle_t* pSPIHandle)
{
    // peripheral clock enable
    SPI_PeriClockControl(pSPIHandle -> pSPIx, ENABLE);
    uint32_t tempreg = 0;
    // 1. configure the device mode
    tempreg |= (pSPIHandle -> SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR_Pos);

    // 2. configre the bus config
    if (pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
        tempreg &= ~(SPI_CR1_BIDIMODE_Msk);
    else if (pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
        tempreg |= SPI_CR1_BIDIMODE_Msk;
    else if (pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_RXONLY)
    {
        // BIDI mode should be set
        tempreg &= ~(SPI_CR1_BIDIMODE_Msk);
        tempreg |= SPI_CR1_RxONLY_Msk;
    }

    // 3. configure the spi serial clock speed (baud rate)
    tempreg |= (pSPIHandle -> SPIConfig.SPI_SclkSpeed << SPI_CR1_BR_Pos);
    // 4. configure the DFF
    tempreg |= (pSPIHandle -> SPIConfig.SPI_DFF << SPI_CR1_DFF_Pos);
    // 5. configure the CPOL
    tempreg |= (pSPIHandle -> SPIConfig.SPI_CPOL << SPI_CR1_CPOL_Pos);
    // 6. configure the CPHA
    tempreg |= (pSPIHandle -> SPIConfig.SPI_CPHA << SPI_CR1_CPHA_Pos);

    pSPIHandle -> pSPIx -> SPI_CR1 = tempreg;
}



/***************************************************************
 * @fn                  - SPI_DeInit
 * 
 * @brief               - 
 * 
 * @param[in]           - base address of the SPI peripheral 
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void SPI_DeInit(SPI_RegDef_t* pSPIx)
{
    if (pSPIx == SPI1)
        SPI1_REG_RESRT();
    else if (pSPIx == SPI2)
        SPI2_REG_RESRT();
    else if (pSPIx == SPI3)
        SPI3_REG_RESRT();
    else if (pSPIx == SPI4)
        SPI4_REG_RESRT();
}


/***************************************************************
 * @fn                  - SPI_Send
 * 
 * @brief               - 
 * 
 * @param[in]           - base address of the SPI peripheral 
 * @param[in]           - pointer to Tx buffer
 * @param[in]           - Tx data length
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void SPI_Send(SPI_RegDef_t* pSPIx, uint8_t* pTxBuffer, uint32_t Len)
{
    if (Len == 0)
        return;
    while (Len > 0) {
        // 1. wait until TXE is set
        while (SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);
        // while (!((SPI_SP_TXE_Msk & pSPIx -> SPI_SR) >> SPI_SR_TXE_Pos));
        if (pSPIx -> SPI_CR1 >> SPI_CR1_DFF_Pos == SIXTEEN_BIT_DATA_FRAME) {

            // 16 bit DFF
            // 1. load the data in to the the buffer
            pSPIx -> SPI_DR = *((uint16_t*)pTxBuffer);
            Len --;
            Len --;
            (uint16_t*)pTxBuffer ++;
        }

        else {
            // 8 bit DFF
            pSPIx -> SPI_DR = *pTxBuffer;
            Len --;
            pTxBuffer ++;
        }   

        Len --;
    }
}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t* pSPIx, uint32_t FlagName)
{
    if ((SPI_SR_TXE_Msk & pSPIx -> SPI_SR) >> SPI_SR_TXE_Pos == SPI_TXE_FLAG)
        return FLAG_SET;
    return FLAG_RESET;
}

/***************************************************************
 * @fn                  - SPI_PeripheralControl
 * 
 * @brief               - 
 * 
 * @param pSPIx         - base address of the SPI peripheral 
 * @param EnOrDi        - Enable or Disable
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void SPI_PeripheralControl(SPI_RegDef_t* pSPIx, uint8_t EnOrDi)
{
    if (EnOrDi == ENABLE)
        pSPIx -> SPI_CR1 |= SPI_CR1_SPE_Msk;
    else
        pSPIx -> SPI_CR1 &= ~(SPI_CR1_SPE_Msk);
}

/***************************************************************
 * @fn                  - SPI_SSIConfig
 * 
 * @brief               - 
 * 
 * @param pSPIx         - base address of the SPI peripheral 
 * @param EnOrDi        - Enable or Disable
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void SPI_SSIConfig(SPI_RegDef_t* pSPIx, uint8_t EnOrDi)
{
    if (EnOrDi == ENABLE)
        pSPIx -> SPI_CR1 |= SPI_CR1_SSI_Msk;
    else
        pSPIx -> SPI_CR1 &= ~(SPI_CR1_SSI_Msk);
}

/***************************************************************
 * @fn                  - SPI_Receive
 * 
 * @brief               - 
 * 
 * @param pSPIx         - base address of the SPI peripheral 
 * @param pRxBuffer     - Enable or Disable
 * @param Len
 * @return              -  none
 * 
 * @Note                -  none
 */
void SPI_Receive(SPI_RegDef_t* pSPIx, uint8_t* pRxBuffer, uint32_t Len)
{
    if (Len == 0)
        return;

    while (Len > 0)
    {
        while (SPI_GetFlagStatus(pSPIx, SPI_SR_RXNE_Msk) != FLAG_RESET)
        {
            if ((pSPIx -> SPI_CR1 >> SPI_CR1_DFF_Pos) & SPI_OFF_16BITS)
            {
                *(uint16_t*)pRxBuffer = pSPIx -> SPI_DR;
                Len --;
                Len --;
                (uint16_t*)pRxBuffer ++;
            }
            else
            {
                pRxBuffer = pSPIx -> SPI_DR;
                Len --;
                pRxBuffer ++;
            }
        }
    }
}

/***************************************************************
 * @fn                  - SPI_IRQInterruptConfig
 * 
 * @brief               - 
 * 
 * @param IRQNumber     - SPI Position Number in Vector Table
 * @param EnorDi        - Enable or Disable 
 * 
 * @return              -  
 * 
 * @Note                -  none
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
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
 * @fn                  - SPI_PriorityConfig
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
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPiority) {

    // 1. first lets find out the IPR register
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;
    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
    *(NVIC_PR_BASE_ADDR + iprx) |= IRQPiority << (shift_amount);
}


/***************************************************************
 * @fn                  - SPI_SendDataIT
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
uint8_t SPI_SendDataIT(SPI_Handle_t* pSPIHandle, uint8_t* pTxBuffer, uint32_t Len)
{
    uint8_t State = pSPIHandle -> TxState;
    if (State != SPI_BUSY_IN_TX)
    {
        pSPIHandle -> pTxBuffer = pTxBuffer;
        pSPIHandle -> TxLen = Len;
        pSPIHandle -> TxState = SPI_BUSY_IN_TX;
        pSPIHandle -> pSPIx -> SPI_CR2 |= SPI_CR2_TXEIE_Msk; 
    }
    return State;
}

/***************************************************************
 * @fn                  - SPI_ReceiveDataIT
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
uint8_t SPI_ReceiveDataIT(SPI_Handle_t* pSPIHandle, uint8_t* pRxBuffer, uint32_t Len)
{
    uint8_t State = pSPIHandle -> RxState;
    if (State != SPI_BUSY_IN_RX)
    {
        pSPIHandle -> pRxBuffer = pRxBuffer;
        pSPIHandle -> RxLen = Len;
        pSPIHandle -> RxState = SPI_BUSY_IN_RX;
        pSPIHandle -> pSPIx -> SPI_CR2 |= SPI_CR2_RXNEIE_Msk; 
    }
    return State;
}

void SPI_IRQHandling(SPI_Handle_t* pHandle)
{
    // 1 Check Interupt request source
    // Tx
    uint8_t temp1, temp2;
    temp1 = (pHandle -> pSPIx -> SPI_SR & SPI_SR_TXE_Msk) >> SPI_SR_TXE_Pos;
    temp2 = (pHandle -> pSPIx -> SPI_CR2 & SPI_CR2_TXEIE_Msk) >> SPI_CR2_TXEIE_Pos;

    if ((temp1 == SPI_Tx_Buffer_Empty) & temp2)
    {
        spi_txe_interupt_handler(pHandle);
    }

    // 2 Check Interupt request source
    // Rx
    temp1 = (pHandle -> pSPIx -> SPI_SR & SPI_SR_RXNE_Msk) >> SPI_SR_CRCERR_Pos;
    temp2 = (pHandle -> pSPIx -> SPI_CR2 & SPI_CR2_RXNEIE_Msk) >> SPI_CR2_RXNEIE_Pos;
    if ((temp1 == SPI_Rx_Buffer_NotEmpty) && temp2)
    {
        spi_rxne_interupt_handler(pHandle);
    }

    // 3 Check Interupt request source
    // CRC Error
    temp1 = (pHandle -> pSPIx -> SPI_SR & SPI_SR_OVR_Msk) >> SPI_SR_OVR_Pos;
    temp2 = (pHandle -> pSPIx -> SPI_CR2 & SPI_SR_OVR_Msk) >> SPI_SR_OVR_Pos;
    if (temp1 & temp2)
    {
        spi_err_interupt_handler(pHandle);
    }
}


static void spi_txe_interupt_handler(SPI_Handle_t *pSPIHandle)
{
    if (pSPIHandle -> pSPIx -> SPI_CR1 >> SPI_CR1_DFF_Pos == SIXTEEN_BIT_DATA_FRAME) {

    // 16 bit DFF
    // 1. load the data in to the the buffer
    pSPIHandle -> pSPIx -> SPI_DR = *((uint16_t*)pSPIHandle -> pTxBuffer);
    pSPIHandle -> TxLen -= 2;
    (uint16_t*)pSPIHandle -> pTxBuffer ++;
    }

    else {
    // 8 bit DFF
    pSPIHandle -> pSPIx -> SPI_DR = *(pSPIHandle -> pTxBuffer);
    pSPIHandle -> TxLen --;
    pSPIHandle -> pTxBuffer ++;
    }

    if (pSPIHandle -> TxLen == 0)
    {
        CLEAR_BIT(pSPIHandle -> pSPIx -> SPI_CR2, SPI_CR2_TXEIE_Pos);
        pSPIHandle -> pTxBuffer = NULL;
        pSPIHandle -> TxLen = 0;
        pSPIHandle -> TxState = SPI_Ready;
    }   
}

static void spi_rxne_interupt_handler(SPI_Handle_t *pSPIHandle)
{
    if (pSPIHandle -> pSPIx -> SPI_CR1 >> SPI_CR1_DFF_Pos == SIXTEEN_BIT_DATA_FRAME)
    {
        *((uint16_t*)pSPIHandle -> pRxBuffer) = pSPIHandle -> pSPIx-> SPI_DR;
        pSPIHandle -> RxLen -= 2;
        pSPIHandle -> pRxBuffer += 2; 
    }
    else {
        pSPIHandle -> pRxBuffer = pSPIHandle -> pSPIx -> SPI_DR;
        pSPIHandle -> RxLen --;
        pSPIHandle -> pRxBuffer --;
    }

    if (pSPIHandle -> RxLen == 0)
    {
        CLEAR_BIT(pSPIHandle -> pSPIx -> SPI_CR2, SPI_CR2_RXNEIE_Pos);
        pSPIHandle -> pRxBuffer = NULL;
        pSPIHandle -> RxLen = 0;
        pSPIHandle -> RxState = SPI_Ready;
    }
}