#ifndef INC_STM_FLASH_REG_H_
#define INC_STM_FLASH_REG_H_
#include "stm32f446re.h"

#define Flash_REG_BASEADDR             ((uint32_t)0x40023C00)
typedef struct 
{
    __vo uint32_t FLASH_ACR;
    __vo uint32_t FLASH_KEYR;
    __vo uint32_t FLASH_OPTKEYR;
    __vo uint32_t FLASH_SR;
    __vo uint32_t FLASH_CR;
    __vo uint32_t FLASH_OPTCR;
}FLASH_RegDef_t;

/*******************  Bits definition for FLASH_ACR register  ******************/
#define FLASH_ACR_LATENCY_POS            (0U)
#define FLASH_ACR_LATENCY_Msk            (0x7UL << FLASH_ACR_LATENCY)
#define FLASH_ACR_LATENCY                FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS            0U
#define FLASH_ACR_LATENCY_1WS            1U
#define FLASH_ACR_LATENCT_2WS            2U
#define FLASH_ACR_LATENCY_3WS            3U
#define FLASH_ACR_LATENCY_4WS            4U
#define FLASH_ACR_LATENCY_5NS            5U
#define FLASH_ACR_LATENCT_6NS            6U
#define FLASH_ACR_LATENCT_7NS            7U
#define FLASH_ACR_LATENCT_8NS            8U

#define FLASH_ACR_PRFTEN_POS             (8U)
#define FLASH_ACR_PRFTEN_Msk             (0x1UL << FLASH_ACR_PRFTEN_POS)
#define FLASH_ACR_PRFTEN                 FLASH_ACR_PRFTEN_Msk
#define FLASH_ACR_ICEN_POS               (9U)
#define FLASH_ACR_ICEN_Msk               (0x1UL << FLASH_ACR_ICEN_POS)
#define FLASH_ACR_ICEN                   FLASH_ACR_ICEN_Msk
#define FLASH_ACR_DCEN_POS               (10U)
#define FLASH_ACR_DCEN_Msk               (0x1UL << FLASH_ACR_DCEN_POS)
#define FLASH_ACR_DCEN                   FLASH_ACR_DCEN_Msk
#define FLASH_ACR_ICRST_POS              (11U)
#define FLASH_ACR_ICRST_Msk              (0x1UL << FLASH_ACR_ICRST_POS)
#define FLASH_ACR_ICRST                  FLASH_ACR_ICRST_Msk
#define FLASH_ACR_DCRST_POS              (12U)
#define FLASH_ACR_DCRST_Msk              (0x1UL << FLASH_ACR_DCRST_POS)
#define FLASH_ACR_DCRST                  FLASH_ACR_DCRST_Msk

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_POS                    (0U)
#define FLASH_SR_EOP_Msk                    (0x1UL << FLASH_EOP_POS)
#define FLASH_SR_EOP                        FLASH_EOP_Msk
#define FLASH_SR_OPERR_POS                  (1U)
#define FLASH_SR_OPERR_Msk                  (0x1UL << FLASH_OPERR_POS)
#define FLASH_SR_OPERR                      FLASH_SR_OPERR_Msk
#define FLASH_SR_WRPERR_Pos                 (4U)
#define FLASH_SR_WRPERR_Msk                 (0x1UL << FLASH_SR_WRPERR)
#define FLASH_SR_WRPERR                     FLASH_SR_WRPERR_Msk
#define FLASH_SR_PGAERR_Pos                 (5U)                                    
#define FLASH_SR_PGAERR_Msk                 (0x1UL << FLASH_SR_PGAERR_Pos)           
#define FLASH_SR_PGAERR                     FLASH_SR_PGAERR_Msk                     
#define FLASH_SR_PGPERR_Pos                 (6U)                                    
#define FLASH_SR_PGPERR_Msk                 (0x1UL << FLASH_SR_PGPERR_Pos)           
#define FLASH_SR_PGPERR                      FLASH_SR_PGPERR_Msk                     
#define FLASH_SR_PGSERR_Pos                 (7U)                                    
#define FLASH_SR_PGSERR_Msk                 (0x1UL << FLASH_SR_PGSERR_Pos)           
#define FLASH_SR_PGSERR                     FLASH_SR_PGSERR_Msk                     
#define FLASH_SR_RDERR_Pos                  (8U)                                    
#define FLASH_SR_RDERR_Msk                  (0x1UL << FLASH_SR_RDERR_Pos)             
#define FLASH_SR_RDERR                      FLASH_SR_RDERR_Msk                     
#define FLASH_SR_BSY_Pos                    (16U)                                   
#define FLASH_SR_BSY_Msk                    (0x1UL << FLASH_SR_BSY_Pos)              
#define FLASH_SR_BSY                        FLASH_SR_BSY_Msk    

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_CR_PG_Pos                     (0U)
#define FLASH_CR_PG_Msk                     (0x1UL << FLASH_CR_PG_Pos)
#define FLASH_CR_PG                         FLASH_CR_PG_Msk
#define FLASH_CR_SER_POS                    (1U)
#define FLASH_CR_SER_Msk                    (0x1UL << FLASH_CR_SER_POS)
#define FLASH_CR_SER                        FLASH_CR_SER_Msk
#define FLASH_CR_MER_Pos                    (2U)
#define FLASH_CR_MER_Msk                    (0x1UL << FLASH_CR_MER_Pos)
#define FLASH_CR_MER                        FLASH_CR_MER_Msk
#define FLASH_CR_SNB_Pos                    (3U)
#define FLASH_CR_SNB_Msk                    (0xfUL << FLASH_CR_SNB_Pos)
#define FLASH_CR_SNB                        FLASH_CR_SNB_Msk
#define FLASH_CR_PSIZE_Pos                  (8U)
#define FLASH_CR_PSIZE_Msk                  (0x3UL << FLASH_CR_PSIZE_Pos)
#define FLASH_CR_PSIZE                      FLASH_CR_PSIZE_Msk
#define FLASH_CR_START_Pos                  (16U)
#define FLASH_CR_START_Msk                  (0x1UL << FLASH_CR_START_Pos)
#define FLASH_CR_START                      FLASH_CR_START_Msk
#define FLASH_CR_EOPIE_Pos                  (24U)
#define FLASH_CR_EOPIE_Msk                  (0x1UL << FLASH_CR_EOPIE_Pos)
#define FLASH_CR_EOPIE                      FLASH_CR_EOPIE_Msk
#define FLASH_CR_EPRIE_Pos                  (25U)
#define FLASH_CR_EPRIE_Msk                  (0x1UL << FLASH_CR_EPRIE_Pos)
#define FLASH_CR_EPRIE                      FLASH_CR_EPRIE_Msk
#define FLASH_CR_LOCK_Pos                   (31U)
#define FLASH_CR_LOCK_Msk                   (0x1UL << FLASH_CR_LOCK_Pos)
#define FLASH_CR_LOCK                       FLASH_CR_LOCK_Msk

// #define FLASH_CR
#define FLASH                    ((FLASH_RegDef_t*)Flash_REG_BASEADDR)  

#endif /* INC_STM_FLASH_REG_H_ */
