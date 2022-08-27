#ifndef INC_STM32_CAN_REG_H_
#define INC_STM32_CAN_REG_H_
#include "stm32f446re.h"
#define CAN1_BASE_ADDR                 ((uint32_t)0x40006400)
#define CAN2_BASE_ADDR                 ((uint32_t)0x40006800)

typedef struct
{
    __vo uint32_t CAN_TIR;
    __vo uint32_t CAN_TDTR;
    __vo uint32_t CAN_TDLR;
    __vo uint32_t CAN_TDHR;
}TxMailBox_Reg;

typedef struct
{
    __vo uint32_t CAN_RIR;
    __vo uint32_t CAN_RDTR;
    __vo uint32_t CAN_RDLR;
    __vo uint32_t CAN_RDHR;
}FIFO_MailBox_Reg;

typedef struct
{
    __vo uint32_t FR1;
    __vo uint32_t FR2;
}CAN_FilterRegister;


typedef struct
{
    __vo uint32_t CAN_MCR;
    __vo uint32_t CAN_MSR;
    __vo uint32_t CAN_TSR;
    __vo uint32_t CAN_RF0R;
    __vo uint32_t CAN_RF1R;
    __vo uint32_t CAN_IER;
    __vo uint32_t CAN_ESR;
    __vo uint32_t CAN_BTR;
    uint32_t reserved0[88];
    TxMailBox_Reg CAN_TxMailbox[3];
    FIFO_MailBox_Reg CAN_FIFOMailBox[2];
    uint32_t reserved1[12];
    __vo uint32_t CAN_FMR;
    __vo uint32_t CAN_FM1R;
    uint32_t reserved2;
    __vo uint32_t CAN_FS1R;
    uint32_t reserved3;
    __vo uint32_t CAN_FFA1R;
    uint32_t reserved4;
    __vo uint32_t CAN_FA1R;
    uint32_t reserved5[8];
    CAN_FilterRegister Filter[28];
}CAN_RegDef_t;
/*******************  Bits definition for CAN_MCR register  ******************/
#define CAN_MCR_INRQ_Pos                                      0U
#define CAN_MCR_INRQ_Msk                                      ((0x1) << CAN_MCR_INRQ_Pos)
#define CAN_MCR_INRQ                                          CAN_MCR_INRQ_Msk

#define CAN_MCR_SLEEP_Pos                                     1U
#define CAN_MCR_SLEEP_Msk                                     ((0x1) << CAN_MCR_SLEEP_Pos)
#define CAN_MCR_SLEEP                                         CAN_MCR_SLEEP_Msk

#define CAN_MCR_TXFP_Pos                                      2U
#define CAN_MCR_TXFP_Msk                                      ((0x1) << CAN_MCR_TXFP_Pos)
#define CAN_MCR_TXFP                                          CAN_MCR_TXFP_Msk

#define CAN_MCR_RFLM_Pos                                      3U
#define CAN_MCR_RFLM_Msk                                      ((0x1) << CAN_MCR_RFLM_Pos)
#define CAN_MCR_RFLM                                          CAN_MCR_RFLM_Msk

#define CAN_MCR_NART_Pos                                      4U
#define CAN_MCR_NART_Msk                                      ((0x1) << CAN_MCR_NART_Pos)
#define CAN_MCR_NART                                          CAN_MCR_NART_Msk

#define CAN_MCR_AWUM_Pos                                      5U
#define CAN_MCR_AWUM_Msk                                      ((0x1) << CAN_MCR_AWUM_Pos)
#define CAN_MCR_AWUM                                          CAN_MCR_AWUM_Msk

#define CAN_MCR_ABOM_Pos                                      6U
#define CAN_MCR_ABOM_Msk                                      ((0x1) << CAN_MCR_ABOM_Pos)
#define CAN_MCR_ABOM                                          CAN_MCR_ABOM_Msk

#define CAN_MCR_TTCMF_Pos                                      6U
#define CAN_MCR_TTCMF_Msk                                     ((0x1) << CAN_MCR_TTCMF_Pos)
#define CAN_MCR_TTCMF                                          CAN_MCR_TTCMF_Msk

#define CAN_MCR_DBF_Pos                                      16U
#define CAN_MCR_DBF_Msk                                      ((0x1) << CAN_MCR_ABOM_Pos)
#define CAN_MCR_DBF                                          CAN_MCR_DBF_Msk

/*******************  Bits definition for CAN_MSR register  ******************/
#define CAN_MSR_INAK_Pos                                    0U
#define CAN_MSR_SLAK_Pos                                    1U
// #define CAN_MSR_INAK

/*******************  Bits definition for CAN_TSR register  ******************/
#define CAN_TSR_PQCP0_Pos                                    0U
#define CAN_TSR_PQCP0_Msk                                    ((0x1) << CAN_TSR_PQCP0_Pos)
#define CAN_TSR_PQCP                                         CAN_TSR_PQCP0_Msk

#define CAN_TSR_TXOK0_Pos                                    1U
#define CAN_TSR_TXOK0_Msk                                    ((0x1) << CAN_TSR_TXOK0_Pos)
#define CAN_TSR_TXOK0                                        CAN_TSR_TXOK0_Msk

#define CAN_TSR_ALST0_Pos                                    2U
#define CAN_TSR_ALST0_Msk                                    ((0x1) << CAN_TSR_ALST0_Pos)
#define CAN_TSR_ALST0                                        CAN_TSR_ALST0_Msk

#define CAN_TSR_TERR0_Pos                                    3U
#define CAN_TSR_TERR0_Msk                                    ((0x1) << CAN_TSR_TERR0_Pos)
#define CAN_TSR_TERR0                                        CAN_TSR_TERR0_Msk

#define CAN_TSR_ABRQ0_Pos                                    7U
#define CAN_TSR_ABRQ0_Msk                                    ((0x1) << CAN_TSR_ABRQ0_Pos)
#define CAN_TSR_ABRQ0                                        CAN_TSR_ABRQ0_Msk

#define CAN_TSR_RQCP1_Pos                                    8U
#define CAN_TSR_RQCP1_Msk                                    ((0x1) << CAN_TSR_RQCP1_Pos)
#define CAN_TSR_RQCP1                                        CAN_TSR_RQCP1_Msk

#define CAN_TSR_TXOK1_Pos                                    9U
#define CAN_TSR_TXOK1_Msk                                    ((0x1) << CAN_TSR_TXOK1_Pos)
#define CAN_TSR_TXOK1                                        CAN_TSR_TXOK1_Msk

#define CAN_TSR_ALST1_Pos                                    10U
#define CAN_TSR_ALST1_Msk                                    ((0x1) << CAN_TSR_ALST1_Pos)
#define CAN_TSR_ALST1                                        CAN_TSR_ALST1_Msk

#define CAN_TSR_TERR1_Pos                                    11U
#define CAN_TSR_TERR1_Msk                                    ((0x1) << CAN_TSR_TERR1_Pos)
#define CAN_TSR_TERR1                                        CAN_TSR_TERR1_Msk

#define CAN_TSR_ABRQ1_Pos                                    15U
#define CAN_TSR_ABRQ1_Msk                                    ((0x1) << CAN_TSR_ABRQ1_Pos)
#define CAN_TSR_ABRQ1                                        CAN_TSR_ABRQ1_Msk


#define CAN_TSR_RQCP2_Pos                                    16U
#define CAN_TSR_RQCP2_Msk                                    ((0x1) << CAN_TSR_RQCP2_Pos)
#define CAN_TSR_RQCP2                                        CAN_TSR_RQCP2_Msk

#define CAN_TSR_TXOK2_Pos                                    17U
#define CAN_TSR_TXOK2_Msk                                    ((0x1) << CAN_TSR_TXOK2_Pos)
#define CAN_TSR_TXOK2                                        CAN_TSR_TXOK2_Msk

#define CAN_TSR_ALST2_Pos                                    18U
#define CAN_TSR_ALST2_Msk                                    ((0x1) << CAN_TSR_ALST2_Pos)
#define CAN_TSR_ALST2                                        CAN_TSR_ALST2_Msk

#define CAN_TSR_TERR2_Pos                                    19U
#define CAN_TSR_TERR2_Msk                                    ((0x1) << CAN_TSR_TERR2_Pos)
#define CAN_TSR_TERR2                                        CAN_TSR_TERR2_Msk

#define CAN_TSR_ABRQ2_Pos                                    23U
#define CAN_TSR_ABRQ2_Msk                                    ((0x1) << CAN_TSR_ABRQ2_Pos)
#define CAN_TSR_ABRQ2                                        CAN_TSR_ABRQ2_Msk

#define CAN_TSR_CODE_Pos                                     24U
#define CAN_TSR_CODE_Msk                                     ((0x3) << CAN_TSR_CODE_Pos)
#define CAN_TSR_CODE                                         CAN_TSR_CODE_Msk

#define CAN_TSR_TME0_Pos                                     26U
#define CAN_TSR_TME0_Msk                                     ((0x1) << CAN_TSR_TME0_Pos)
#define CAN_TSR_TME0                                         CAN_TSR_TME0_Msk

#define CAN_TSR_TME1_Pos                                     27U
#define CAN_TSR_TME1_Msk                                     ((0x1) << CAN_TSR_TME1_Pos)
#define CAN_TSR_TME1                                         CAN_TSR_TME1_Msk

#define CAN_TSR_TME2_Pos                                     28U
#define CAN_TSR_TME2_Msk                                     ((0x1) << CAN_TSR_TME2_Pos)
#define CAN_TSR_TME2                                         CAN_TSR_TME2_Msk

#define CAN_TSR_LOW0_Pos                                     29U
#define CAN_TSR_LOW0_Msk                                     ((0x1) << CAN_TSR_LOW0_Pos)
#define CAN_TSR_LOW0                                         CAN_TSR_LOW0_Msk

#define CAN_TSR_LOW1_Pos                                     30U
#define CAN_TSR_LOW1_Msk                                     ((0x1) << CAN_TSR_LOW1_Pos)
#define CAN_TSR_LOW1                                         CAN_TSR_LOW1_Msk

#define CAN_TSR_LOW2_Pos                                     31U
#define CAN_TSR_LOW2_Msk                                     ((0x1) << CAN_TSR_LOW2_Pos)
#define CAN_TSR_LOW2                                         CAN_TSR_LOW2_Msk

/*******************  Bits definition for CAN_TIR register  ******************/
#define CAN_TIxR_TXRQ_Pos                                   0U
#define CAN_TIxR_TXRQ_Msk                                   ((0x1U) << CAN_TIxR_TXRQ_Pos)
#define CAN_TIxR_TXRQ                                       CAN_TIxR_TXRQ_Msk

#define CAN_TIxR_RTR_Pos                                    1U
#define CAN_TIxR_RTR_Msk                                    ((0x1U) << CAN_TIxR_RTR_Pos)
#define CAN_TIxR_RTR                                        CAN_TIxR_RTR_Msk

#define CAN_TIxR_IDE_Pos                                    2U
#define CAN_TIxR_IDE_Msk                                    ((0x1U) << CAN_TIxR_IDE_Pos)
#define CAN_TIxR_IDE                                        CAN_TIxR_IDE_Msk

#define CAN_TIxR_EXID_Pos                                   3U
#define CAN_TIxR_EXID_Msk                                   ((0x3ffffU) << CAN_TIxR_EXID_Pos)
#define CAN_TIxR_EXID                                       CAN_TIxR_EXID_Msk

#define CAN_TIxR_STID_Pos                                   21U
#define CAN_TIxR_STID_Msk                                   ((0x7ffU) << CAN_TIxR_STID_Pos)
#define CAN_TIxR_STID                                       CAN_TIxR_STID_Msk

#define CAN_TDTxR_DLC_Pos                                  0U
#define CAN_TDTxR_DLE_Msk                                  ((0xfU) << CAN_TDTxR_DLC_Pos)
#define CAN_TDTxR_DLE                                      CAN_TDTxR_DLE_Msk

#define CAN_TDTxR_TIME_Pos                                 16U
#define CAN_TDTxR_TIME_Msk                                 ((0xffffU) << CAN_TDTxR_TIME_Pos)
#define CAN_TDTxR_TIME                                     CAN_TDTxR_TIME_Msk

/*******************  Bits definition for CAN_RIxR register  ******************/
#define CAN_RIxR_RTR_Pos                                   1U
#define CAN_RIxR_IDE_Pos                                   2U
#define CAN_RIxR_EXID_Pos                                  3U
#define CAN_RIxR_STID_Pos                                  21U

/*******************  Bits definition for CAN_RDTR register  ******************/
#define CAN_RDTxR_DLC_Pos                                  0U
#define CAN_RDTxR_FMI_Pos                                  8U
#define CAN_RDTxR_TIME_Pos                                 16U

/*******************  Bits definition for CAN_BTR register  ******************/
#define CAN_BTR_BRP_Pos                                    0U
#define CAN_BTR_BRP_Msk                                    ((0x1ffU) << CAN_BTR_BRP_Pos)
#define CAN_BTR_BRP                                        CAN_BTR_BRP_Msk

#define CAN_BTR_TS1_Pos                                    16U
#define CAN_BTR_TS1_Msk                                    ((0xfU) << CAN_BTR_TS1_Pos)
#define CAN_BTR_TS1                                        CAN_BTR_TS1_Msk

#define CAN_BTR_TS2_Pos                                    20U
#define CAN_BTR_TS2_Msk                                    ((0x7U) << CAN_BTR_TS2_Pos)
#define CAN_BTR_TS2                                        CAN_BTR_TS2_Msk

#define CAN_BTR_SJW_Pos                                    24U
#define CAN_BTR_SJW_Msk                                    ((0x3U) << CAN_BTR_SJW_Pos)
#define CAN_BTR_SJW                                        CAN_BTR_SJW_Msk

#define CAN_BTR_LBKM_Pos                                    30U
#define CAN_BTR_LBKM_Msk                                    ((0x1U) << CAN_BTR_LBKM_Pos)
#define CAN_BTR_LBKM                                        CAN_BTR_LBKM_Msk

#define CAN_BTR_SILM_Pos                                    31U
#define CAN_BTR_SILM_Msk                                    ((0x1U) << CAN_BTR_SILM_Pos)
#define CAN_BTR_SILM                                        CAN_BTR_SILM_Msk

/*******************  Bits definition for CAN_FMR register  ******************/
#define CAN_FMR_FINIT_Pos                                   0U
#define CAN_FMR_FINIT_Msk                                   ((0x1u) << CAN_FMR_FINIT_Pos)
#define CAN_FMR_FINIT                                       CAN_FMR_FINIT_Msk

#define CAN_MSR_CANSB_Pos                                   8U
#define CAN_MSR_CANSB_Msk                                   ((0x3fu) << CAN_MSR_CANSB_Pos)
#define CAN_MSR_CANSB                                       CAN_MSR_CANSB_Msk

/*******************  Bits definition for CAN_FMR register  ******************/
#define CAN_RF0R_FMP_Pos                                    0U
#define CAN_RF0R_FULL0_FMP_Pos                              3U
#define CAN_RF0R_FOVR0_Pos                                  4U
#define CAN_RF0R_RFOM0_Pos                                  5u
/*******************  Bits definition for CAN_TDHxR register  ******************/
#define CAN_TDHxR_DATA7_Pos                                 24U
#define CAN_TDHxR_DATA6_Pos                                 16U
#define CAN_TDHxR_DATA5_Pos                                 8U
#define CAN_TDHxR_DATA4_Pos                                 0U
/*******************  Bits definition for CAN_TDLxR register  ******************/
#define CAN_TDLxR_DATA3_Pos                                 24U
#define CAN_TDLxR_DATA2_Pos                                 16U
#define CAN_TDLxR_DATA1_Pos                                 8U
#define CAN_TDLxR_DATA0_Pos                                 0U

#define CAN1                ((CAN_RegDef_t*)CAN1_BASE_ADDR)          

// #define 
/*
useful Marco
*/
#define SET_CAN_INIT()               (CAN1 -> CAN_MCR |= CAN_MCR_INRQ)
#define SET_CAN_LBKM()               (CAN1 -> CAN_BTR |= CAN_BTR_LBKM)
#define SET_CAN_SILM()               (CAN1 -> CAN_BTR |= CAN_BTR_SILM)
#define CAN_MAILBOXIDX_TO_BITPos(x)  ((x == 0) ? CAN_TSR_TME0_Pos :\
                                      (x == 1) ? CAN_TSR_TME1_Pos : \
                                      (x == 2) ? CAN_TSR_TME2_Pos : CAN_TSR_TME0_Pos)
#define CAN_FILTERSCALE_16BIT        0U
#define CAN_FILTERSCALE_32BIT        1U
#define CAN_FILTERMODE_IDMASK        0U
#define CAN_FILTERMODE_IDLIST        1U
 
// #define SET_CAN_SJW(data)            ()
/*
Function Prototype
*/
// void Send_TxMessage();
// void Wait_CAN_Init();
#endif /* INC_STM32_CAN_REG_H_ */
