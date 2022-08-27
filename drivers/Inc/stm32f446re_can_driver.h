#ifndef INC_STM32F446RE_CAN_DRIVER_H_
#define INC_STM32F446RE_CAN_DRIVER_H_
#include "STM32_CAN_reg.h"
#include "STM_RCC_reg.h"
typedef struct
{
    uint8_t TTCM;
    uint8_t ABOM;
    uint8_t AWUM;
    uint8_t NART;
    uint8_t RFLM;
    uint8_t TXFP;
    uint8_t TS1;
    uint8_t TS2;
    uint8_t SJW;
    uint8_t LBKM;
    uint8_t SILM;
    uint32_t BRP;
}CAN_BitTiming_t;

typedef struct
{
    uint32_t FilterIdHigh;
    uint32_t FilterIdLow;
    uint32_t FilterMaskIdHigh;
    uint32_t FilterMaskIdLow;
    uint32_t FilterFIFOAssigment;
    uint32_t FilterMode;
    uint32_t FilterScale;
    uint32_t FilterActivation;
    uint32_t BankNumber;
} CAN_FilterCon_t;

typedef struct
{   
    CAN_RegDef_t* pCANx;
    CAN_BitTiming_t CAN_BitTiming;
}CAN_Handle_t;

typedef struct
{
    uint32_t StdId;
    uint32_t ExtId;
    uint32_t IDE;
    uint32_t RTR;
    uint32_t DLC;
}CAN_TxHeaderTypeDef;

typedef struct
{
    uint32_t StdId;
    uint32_t ExtId;
    uint32_t IDE;
    uint32_t RTR;
    uint32_t DLC;
    uint32_t FMI;
    uint32_t TimeStamp;
    uint32_t FilterMatchIndex;
}CAN_RxHeaderTypeDef;

#define CAN_INIT_TimeOut                      0U
#define CAN_INIT_SUCC                         1U
#define CAN_FILTER_FIFO0                      0U
#define CAN_FILTER_FIFO1                      1U
#define CAN_STDID                             0U
#define CAN_EXTID                             1U
#define CAN_32BIT_FILTER_STIDPOS              21U
#define CAN_32BIT_FILTER_EXIDPOS              3U
#define CAN_16BIT_FILTER_HIGH_STIDPOS         21U
#define CAN_16BIT_FILTER_LOW_STIDPOS          5U    
#define CAN_RX_FIFO0                          0U
#define CAN_RX_FIFO1                          1U
void Clock_Configure();
void CAN_TXRX_GPIO_Configure(uint8_t PinNumber);
void CAN_Init(CAN_Handle_t* pCANHandle);
void CAN_FilterConfig(CAN_RegDef_t* pCANx, CAN_FilterCon_t* Filter_Config);
void Send_TxMessage(CAN_TxHeaderTypeDef* pHeader, CAN_RegDef_t* pCANx, uint8_t Data[8]);
void Receive_RxMessage(CAN_RegDef_t* pCANx, CAN_RxHeaderTypeDef* pheader, uint32_t RxFifo, uint8_t Data[8]);
int Wait_CAN_Init();
int Enter_CAN_InitMode();
void CAN_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void CAN_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPiority);
void Float_To_Uint8(float* val, uint8_t buffer[4]);
void Uint8_To_Float(uint8_t buffer[4], float* val);
#endif /* INC_STM32F446RE_CAN_DRIVER_H_ */
