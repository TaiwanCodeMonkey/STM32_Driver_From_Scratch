#include <stm32f446re_gpio_driver.h>
#include "stm32f446re_can_driver.h"
#include <string.h>
#define MAX_TIMEOUT            10000

/***************************************************************
 * @fn                  - CAN_Init
 * 
 * @brief               - 
 * 
 * @param pCANHandle    -  Pointer of CAN_Handle_t that contain the configuration information for specified CAN 
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
CAN_Status CAN_Init(CAN_Handle_t* pCANHandle) {
    // memcpy()
    CAN_Status status;
    status = CAN_WakeUp(pCANHandle -> pCANx);
    if (status != CAN_OK)
        return status;
    
    status = CAN_Enter_InitMode(pCANHandle -> pCANx);
    if (status != CAN_OK)
        return status;
    // status = CAN_Start(pCANHandle -> pCANx);
    // if (status != CAN_OK)
    //     return status;
    uint8_t TTCM = pCANHandle -> CAN_BitTiming.TTCM;
    pCANHandle -> pCANx -> CAN_MCR &= ~(CAN_MCR_TTCMF_Msk);
    pCANHandle -> pCANx -> CAN_MCR |= (TTCM << CAN_MCR_TTCMF_Pos);
    
    uint8_t TS1 = pCANHandle -> CAN_BitTiming.TS1;
    pCANHandle -> pCANx -> CAN_BTR &= ~(CAN_BTR_TS1_Msk);
    pCANHandle -> pCANx -> CAN_BTR |= (TS1 << CAN_BTR_TS1_Pos);

    uint8_t TS2 = pCANHandle -> CAN_BitTiming.TS2;
    pCANHandle -> pCANx -> CAN_BTR &= ~(CAN_BTR_TS2_Msk);
    pCANHandle -> pCANx -> CAN_BTR |= (TS2 << CAN_BTR_TS2_Pos);

    uint8_t SJW = pCANHandle -> CAN_BitTiming.SJW;
    pCANHandle -> pCANx -> CAN_BTR &= ~(CAN_BTR_SJW_Msk);
    pCANHandle -> pCANx -> CAN_BTR |= (SJW << CAN_BTR_SJW_Pos);

    uint8_t LBKM = pCANHandle -> CAN_BitTiming.LBKM;
    pCANHandle -> pCANx -> CAN_BTR &= ~(CAN_BTR_LBKM_Msk);
    pCANHandle -> pCANx -> CAN_BTR |= (LBKM << CAN_BTR_LBKM_Pos);

    uint8_t SILM = pCANHandle -> CAN_BitTiming.SILM;
    pCANHandle -> pCANx -> CAN_BTR &= ~(CAN_BTR_SILM_Msk);
    pCANHandle -> pCANx -> CAN_BTR |= (SILM << CAN_BTR_SILM_Pos);

    uint32_t BRP = pCANHandle -> CAN_BitTiming.BRP;
    pCANHandle -> pCANx -> CAN_BTR &= ~(CAN_BTR_BRP_Msk);
    pCANHandle -> pCANx -> CAN_BTR |= (BRP << CAN_BTR_BRP_Pos);
    return CAN_OK;
}

/***************************************************************
 * @fn                  - CAN_TXRX_GPIO_Configure
 * 
 * @brief               - 
 * 
 * @param PinNumber     -  PinNumber for CAN
 * 
 * @return              -  none
 * 
 * @Note                -  none
 */
void CAN_TXRX_GPIO_Configure(uint8_t PinNumber) {

    GPIO_Handle_t CAN; 
    CAN.GPIO_PinConfig.GPIO_PinNumber = PinNumber;
    CAN.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
    CAN.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    CAN.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    CAN.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PULLUP;
    CAN.GPIO_PinConfig.GPIO_PinAltFunMode = AF9;
    CAN.pGPIOx = GPIOA;
    GPIO_Init(&CAN);
    return;
}

/***************************************************************
 * @fn                  - CAN_WakeUp
 * 
 * @brief               - 
 * 
 * @param pCANx         -  CAN Base address
 * 
 * @return              -  CAN_Status
 * 
 * @Note                -  none
 */
CAN_Status CAN_WakeUp(CAN_RegDef_t *pCANx)
{
    CLEAR_BIT(pCANx -> CAN_MCR, CAN_MCR_SLEEP_Pos);
    uint32_t count = 0;
    do
    {
        count ++;
        if (count >= TIMEOUT)
            return CAN_TIMEOUT;
    }while(READBIT(pCANx -> CAN_MSR, CAN_MSR_SLAK_Pos));
    return CAN_OK;
}

/***************************************************************
 * @fn                  - CAN_Enter_InitMode
 * 
 * @brief               - 
 * 
 * @param pCANx         -  CAN Base address
 * 
 * @return              -  CAN_Status
 * 
 * @Note                -  none
 */
CAN_Status CAN_Enter_InitMode(CAN_RegDef_t *pCANx)
{
    SET_BIT(pCANx -> CAN_MCR, CAN_MCR_INRQ_Pos);
    uint32_t count = 0;
    do
    {
        count += 1;
        if (count >= TIMEOUT)
            return CAN_TIMEOUT;
    }while(!READBIT(pCANx -> CAN_MSR, CAN_MSR_INAK_Pos));

    return CAN_OK;
}

/***************************************************************
 * @fn                  - CAN_Start
 * 
 * @brief               - 
 * 
 * @param pCANx         -  CAN Base address
 * 
 * @return              -  CAN_Status
 * 
 * @Note                -  none
 */
CAN_Status CAN_Start(CAN_RegDef_t *pCANx) {
    
	CLEAR_BIT(pCANx -> CAN_MCR, CAN_MCR_INRQ_Pos);
    uint32_t count = 0;
    do
    {
        count += 1;
        if (count >= TIMEOUT)
            return CAN_TIMEOUT;
    }while(READBIT(pCANx -> CAN_MSR, CAN_MSR_INAK_Pos));
    return CAN_OK;
}

/***************************************************************
 * @fn                  - CAN_FilterConfig
 * 
 * @brief               - 
 * 
 * @param pCANx         -  Pointer to the CAN Base Address
 * @param Filter_Config -  Pointer to the CAN_FilterCon_t that contains the configuration infor for Filter
 * @return              -  none
 * 
 * @Note                -  none
 */
void CAN_FilterConfig(CAN_RegDef_t* pCANx, CAN_FilterCon_t* Filter_Config) {
    
    SET_BIT(pCANx -> CAN_FMR, CAN_FMR_FINIT_Pos);
    // Get filter bank number
    uint32_t Filter_Idx = Filter_Config -> BankNumber;
    // Get filter filter scale;
    uint32_t Filter_Scale = Filter_Config -> FilterScale;
    // Get filter Mode
    uint32_t Filter_Mode = Filter_Config -> FilterMode;
    uint32_t FilterIdHigh = Filter_Config -> FilterIdHigh;
    uint32_t FilterIdLow = Filter_Config -> FilterIdLow;
    uint32_t FilterMaskIdHigh = Filter_Config -> FilterMaskIdHigh;
    uint32_t FilterMaskIdLow = Filter_Config -> FilterMaskIdLow;
    uint32_t FilterFIFOAssigment = Filter_Config -> FilterFIFOAssigment;
    /* Filter Mode */
    WRITE_REG(pCANx -> Filter[Filter_Idx].FR1, 0);
    WRITE_REG(pCANx -> Filter[Filter_Idx].FR2, 0);
    if (Filter_Mode == CAN_FILTERMODE_IDMASK) {
        CLEAR_BIT(pCANx -> CAN_FM1R, Filter_Idx);
        if (Filter_Scale == CAN_FILTERSCALE_32BIT) {
            CLEAR_BIT(pCANx -> CAN_FS1R, Filter_Idx);
            pCANx -> Filter[Filter_Idx].FR1 |= (FilterIdHigh << CAN_32BIT_FILTER_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR2 |= (FilterMaskIdHigh << CAN_32BIT_FILTER_STIDPOS);
        }
        if (Filter_Scale == CAN_FILTERSCALE_16BIT) {
            SET_BIT(pCANx -> CAN_FS1R, Filter_Idx);
            pCANx -> Filter[Filter_Idx].FR1 |= (FilterIdHigh << CAN_16BIT_FILTER_LOW_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR1 |= (FilterMaskIdHigh << CAN_16BIT_FILTER_HIGH_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR2 |= (FilterIdLow << CAN_16BIT_FILTER_LOW_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR2 |= (FilterMaskIdLow << CAN_16BIT_FILTER_HIGH_STIDPOS);
        }
    }
    if (Filter_Mode == CAN_FILTERMODE_IDLIST) {
        SET_BIT(pCANx -> CAN_FM1R, Filter_Idx);
        if (Filter_Scale == CAN_FILTERSCALE_32BIT) {
            CLEAR_BIT(pCANx -> CAN_FS1R, Filter_Idx);
            pCANx -> Filter[Filter_Idx].FR1 |= (FilterIdHigh << CAN_32BIT_FILTER_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR2 |= (FilterIdLow << CAN_32BIT_FILTER_STIDPOS);
        }
        if (Filter_Scale == CAN_FILTERSCALE_16BIT) {
            SET_BIT(pCANx -> CAN_FS1R, Filter_Idx);
            pCANx -> Filter[Filter_Idx].FR1 |= (FilterIdLow << CAN_16BIT_FILTER_LOW_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR2 |= (FilterIdHigh << CAN_16BIT_FILTER_HIGH_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR1 |= (FilterMaskIdLow << CAN_16BIT_FILTER_LOW_STIDPOS);
            pCANx -> Filter[Filter_Idx].FR2 |= (FilterMaskIdHigh << CAN_16BIT_FILTER_HIGH_STIDPOS);
        }
    }

    if (FilterFIFOAssigment == CAN_FILTER_FIFO0)
        CLEAR_BIT(pCANx -> CAN_FFA1R, Filter_Idx);
    else
        SET_BIT(pCANx -> CAN_FFA1R, Filter_Idx);

    SET_BIT(pCANx -> CAN_FA1R, Filter_Idx);
    CLEAR_BIT(pCANx -> CAN_FMR, CAN_FMR_FINIT_Pos);
    return;

}

/***************************************************************
 * @fn                  - Send_TxMessage
 * 
 * @brief               - 
 * 
 * @param pHeader       -  Pointer to the CAN_TxHeaderTypeDef which contains the Tx frame configuration
 * @param pCANx         -  Pointer to the CAN Base Address
 * @param Data          -  Data that need to write to CAN TxMailBox Register
 * @return              -  none
 * 
 * @Note                -  none
 */
CAN_Status Send_TxMessage(CAN_TxHeaderTypeDef* pHeader, CAN_RegDef_t* pCANx, uint8_t Data[8]) {

    uint32_t StdId = pHeader -> StdId;
    uint32_t ExtId = pHeader -> ExtId;
    uint32_t IDE = pHeader -> IDE;
    uint32_t RTR = pHeader -> RTR;
    uint32_t DLC = pHeader -> DLC;
    // CLEAR_BIT(CAN1 -> CAN_MCR, CAN_MCR_INRQ_Pos);
    uint32_t temp = pCANx -> CAN_MSR;
    uint32_t TSR = pCANx -> CAN_TSR;
    // Check that all Tx mailboxes are not full
    uint8_t MailBox0_Empty = READBIT(pCANx -> CAN_TSR, CAN_TSR_TME0_Pos);
    uint8_t MailBox1_Empty = READBIT(pCANx -> CAN_TSR, CAN_TSR_TME1_Pos);
    uint8_t MailBox2_Empty = READBIT(pCANx -> CAN_TSR, CAN_TSR_TME2_Pos);
    if (MailBox0_Empty != 0 && MailBox1_Empty != 0 && MailBox2_Empty != 0)
    {
        // select empty mailbox
        uint8_t mailbox_idx = (TSR >> CAN_TSR_CODE_Pos) & 0x3U;
        CLEAR_BIT(pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR, 1);
        if (IDE == CAN_STDID) {
            CLEAR_BIT(pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR, CAN_TIxR_IDE_Pos);
            pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR &= ~(0x7FF << CAN_TIxR_STID_Pos);
            pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR |= StdId << CAN_TIxR_STID_Pos;
        }
        else {
            CLEAR_BIT(pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR, CAN_TIxR_IDE_Pos);
            SET_BIT(pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR, CAN_TIxR_IDE_Pos);
            pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR &= ~(0x1FFFFFFF << CAN_TIxR_EXID_Pos);
            pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR |= ExtId << CAN_TIxR_EXID_Pos;
        }
        pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TDTR &= ~(0xFU << CAN_TDTxR_DLC_Pos);
        pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TDTR |= (DLC << CAN_TDTxR_DLC_Pos);
        // Write Data to Register
        WRITE_REG(pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TDHR, ((Data[7] << CAN_TDHxR_DATA7_Pos) |
                                                                (Data[6] << CAN_TDHxR_DATA6_Pos) |
                                                                (Data[5] << CAN_TDHxR_DATA5_Pos) |
                                                                (Data[4] << CAN_TDHxR_DATA4_Pos)));
        WRITE_REG(pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TDLR, ((Data[3] << CAN_TDLxR_DATA3_Pos) |
                                                                (Data[2] << CAN_TDLxR_DATA2_Pos) |
                                                                (Data[1] << CAN_TDLxR_DATA1_Pos) |
                                                                (Data[0] << CAN_TDLxR_DATA0_Pos)));
        SET_BIT(pCANx -> CAN_TxMailbox[mailbox_idx].CAN_TIR, CAN_TIxR_TXRQ_Pos);
        return CAN_OK;
    }
    return CAN_ERROR;    
}

/***************************************************************
 * @fn                  - Receive_RxMessage
 * 
 * @brief               - 
 * @param pCANx         -  Pointer to the CAN Base Address
 * @param pHeader       -  Pointer to the CAN_RxHeaderTypeDef which contains the Rx frame configuration
 * @param Data          -  Data read from CAN RxMailBox Register
 * @return              -  none
 * 
 * @Note                -  none
 */
void Receive_RxMessage(CAN_RegDef_t* pCANx, CAN_RxHeaderTypeDef* pheader, uint32_t RxFifo, uint8_t Data[8]) {

    if (RxFifo == CAN_RX_FIFO0) {
        uint8_t FMP = (pCANx -> CAN_RF0R) & (0x3U);
        if (FMP == 0)
            return;
    }
    if (RxFifo == CAN_RX_FIFO1) {
        uint8_t FMP = (pCANx -> CAN_RF1R) & (0x3U);
        if (FMP == 0)
            return;
    }
    pheader -> IDE = READBIT(pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RIR, CAN_RIxR_IDE_Pos);
    if (pheader -> IDE == CAN_STDID)
        pheader -> StdId = pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RIR >> CAN_RIxR_STID_Pos;
    else
        pheader -> ExtId = pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RIR >>  CAN_RIxR_EXID_Pos;
        
    pheader -> RTR = READBIT(pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RIR, CAN_RIxR_RTR_Pos);
    pheader -> DLC =  pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RDTR & 0xFU;
    pheader -> FMI = (pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RDTR >> CAN_RDTxR_FMI_Pos) & 0xFFUL;
    pheader -> TimeStamp = (pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RDTR >> CAN_RDTxR_TIME_Pos) & 0xFFFFUL;
    
<<<<<<< Updated upstream
    for (int idx = 0, shift_position = CAN_TDLxR_DATA0_Pos; idx < 4, shift_position <= CAN_TDLxR_DATA3_Pos; idx++, shift_position += 8)
        Data[idx] = (uint8_t)(pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RDLR >> shift_position & 0xFFU);
    for (int idx = 4, shift_position = CAN_TDHxR_DATA4_Pos; idx < 8, shift_position <= CAN_TDHxR_DATA7_Pos; idx++, shift_position += 8)
        Data[idx] = (uint8_t)(pCANx -> CAN_FIFOMailBox[RxFifo].CAN_RDHR >> shift_position & 0xFFU);
    // Release Mailbox
    SET_BIT(pCANx -> CAN_RF0R, CAN_RF0R_RFOM0_Pos);
}


void CAN_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
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

void CAN_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPiority) {

    // 1. first lets find out the IPR register
    uint8_t iprx = IRQNumber / 4;
    uint8_t iprx_section = IRQNumber % 4;
    uint8_t shift_amount = (8 * iprx_section) + (8 - NO_PR_BITS_IMPLEMENTED);
    *(NVIC_PR_BASE_ADDR + iprx) |= IRQPiority << (shift_amount);
}
void Uint8_To_Float(uint8_t buffer[4], float* val) {
    memcpy(val, buffer, sizeof(float));
}
