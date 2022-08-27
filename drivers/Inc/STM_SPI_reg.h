#ifndef INC_STM_SPI_REG_H_
#define INC_STM_SPI_REG_H_
#include "stm32f446re.h"
/*
* Configuration structure for SPIx peripheral
*/
typedef struct
{
    __vo uint32_t SPI_CR1;
    __vo uint32_t SPI_CR2;
    __vo uint32_t SPI_SR;
    __vo uint32_t SPI_DR;
    __vo uint32_t SPI_CRCPR;
    __vo uint32_t SPI_RXCRCR;
    __vo uint32_t SPI_TXCRCR;
    __vo uint32_t SPI_I2SCFGR;
    __vo uint32_t SPI_I2SPR;
}SPI_RegDef_t;


#define SPI1               ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2               ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3               ((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4               ((SPI_RegDef_t*)SPI4_BASEADDR)

#define EIGHT_BIT_DATA_FRAME                             0
#define SIXTEEN_BIT_DATA_FRAME                           1
/*******************  Bits definition for SPI_CR1 register  ******************/
#define SPI_CR1_CPHA_Pos                                (0U)
#define SPI_CR1_CPHA_Msk                                (0x1u << SPI_CR1_CPHA_Pos)
#define SPI_CR1_CPHA                                    SPI_CR1_CPHA_Msk

#define SPI_CR1_CPOL_Pos                                (1U)
#define SPI_CR1_CPOL_Msk                                (0x1u << SPI_CR1_CPOL_Pos)
#define SPI_CR1_CPOL                                    SPI_CR1_CPOL_Msk

#define SPI_CR1_MSTR_Pos                                (2U)
#define SPI_CR1_MSTR_Msk                                (0x1u << SPI_CR1_MSTR_Pos)
#define SPI_CR1_MSTR                                    SPI_CR1_MSTR_Msk

#define SPI_CR1_BR_Pos                                  (3U)
#define SPI_CR1_BR_Msk                                  (0x7u << SPI_CR1_BR_Pos)
#define SPI_CR1_BR                                      SPI_CR1_BR_Msk

#define SPI_CR1_SPE_Pos                                 (6U)
#define SPI_CR1_SPE_Msk                                 (0x1u << SPI_CR1_SPE_Pos)
#define SPI_CR1_SPE                                     SPI_CR1_SPE_Msk

#define SPI_CR1_LSBFIRST_Pos                            (7U)
#define SPI_CR1_LSBFIRST_Msk                            (0x1u << SPI_CR1_LSBFIRST_Pos)
#define SPI_CR1_LSBFIRST                                SPI_CR1_LSBFIRST_Msk

#define SPI_CR1_SSI_Pos                                 (8U)
#define SPI_CR1_SSI_Msk                                 (0x1u << SPI_CR1_SSI_Pos)
#define SPI_CR1_SSI                                     SPI_CR1_SSI_Msk

#define SPI_CR1_SSM_Pos                                 (9U)
#define SPI_CR1_SSM_Msk                                 (0x1u << SPI_CR1_SSM_Pos)
#define SPI_CR1_SSM                                     SPI_CR1_SSM_Msk

#define SPI_CR1_RxONLY_Pos                              (10U)
#define SPI_CR1_RxONLY_Msk                              (0x1u << SPI_CR1_RxONLY_Pos)
#define SPI_CR1_RxONLY                                   SPI_CR1_RxONLY_Msk

#define SPI_CR1_DFF_Pos                                 (11U)
#define SPI_CR1_DFF_Msk                                 (0x1u << SPI_CR1_DFF_Pos)
#define SPI_CR1_DFF                                     SPI_CR1_DFF_Msk

#define SPI_CR1_CRCNEXT_Pos                             (12U)
#define SPI_CR1_CRCNEXT_Msk                             (0x1u << SPI_CR1_CRCNEXT_Pos)
#define SPI_CR1_CRCNEXT                                  SPI_CR1_CRCNEXT_Msk

#define SPI_CR1_CRCNEN_Pos                              (13U)
#define SPI_CR1_CRCNEN_Msk                              (0x1u << SPI_CR1_CRCNEN_Pos)
#define SPI_CR1_CRCNEN                                  SPI_CR1_CRCNEN_Msk

#define SPI_CR1_BIDEIOE_Pos                             (14U)
#define SPI_CR1_BIDEIOE_Msk                             (0x1u << SPI_CR1_BIDEIOE_Pos)
#define SPI_CR1_BIDEIOE                                  SPI_CR1_BIDEIOE_Msk

#define SPI_CR1_BIDIMODE_Pos                             (15U)
#define SPI_CR1_BIDIMODE_Msk                             (0x1u << SPI_CR1_BIDIMODE_Pos)
#define SPI_CR1_BIDIMODE                                  SPI_CR1_BIDIMODE_Msk

/*******************  Bits definition for SPI_CR1 register  ******************/
#define SPI_CR2_RXDMAEN_Pos                              (0U)
#define SPI_CR2_RXDMAEN_Msk                              (0x1u << SPI_CR2_RXDMAEN_Pos)
#define SPI_CR2_RXDMAEN_Pos                              SPI_CR2_RXDMAEN_Msk
 
#define SPI_CR2_TXDMAEN_Pos                              (1U)
#define SPI_CR2_TXDMAEN_Msk                              (0x1u << SPI_CR2_TXDMAEN_Pos)
#define SPI_CR2_TXDMAEN_Pos                              SPI_CR2_TXDMAEN_Msk

#define SPI_CR2_SSOE_Pos                                 (2U)
#define SPI_CR2_SSOE_Msk                                 (0x1u << SPI_CR2_SSOE_Pos)
#define SPI_CR2_SSOE_Pos                                 SPI_CR2_SSOE_Msk

#define SPI_CR2_FRF_Pos                                  (4U)
#define SPI_CR2_FRF_Msk                                  (0x1u << SPI_CR2_FRF_Pos)
#define SPI_CR2_FRF_Pos                                  SPI_CR2_FRF_Msk

#define SPI_CR2_ERRIE_Pos                                (5U)
#define SPI_CR2_ERRIE_Msk                                (0x1u << SPI_CR2_ERRIE_Pos)
#define SPI_CR2_ERRIE_Pos                                SPI_CR2_ERRIE_Msk

#define SPI_CR2_RXNEIE_Pos                               (6u)
#define SPI_CR2_RXNEIE_Msk                               (0x1u << SPI_CR2_RXNEIE_Pos)
#define SPI_CR2_RXNEIE                                   SPI_CR2_RXNEIE_Msk

#define SPI_CR2_TXEIE_Pos                               (7u)
#define SPI_CR2_TXEIE_Msk                               (0x1u << SPI_CR2_RXNEIE_Pos)
#define SPI_CR2_TXEIE                                   SPI_CR2_RXNEIE_Msk


/*******************  Bits definition for SPI_SR register  ******************/
#define SPI_SR_RXNE_Pos                                 (0u)
#define SPI_SR_RXNE_Msk                                 (0x1u << SPI_SR_RXNE_Pos)
#define SPI_SR_RXNE                                     SPI_SP_RXNE_Msk

#define SPI_SR_TXE_Pos                                  (1u)
#define SPI_SR_TXE_Msk                                  (0x1u << SPI_SR_TXE_Pos)
#define SPI_SR_TXE                                      SPI_SR_TXE_Msk

#define SPI_SR_CHSIDE_Pos                               (2u)
#define SPI_SR_CHSIDE_Msk                               (0x1u << SPI_SR_CHSIDE_Pos)
#define SPI_SR_CHSIDE                                   SPI_SR_CHSIDE_Msk

#define SPI_SR_UDR_Pos                                  (3u)
#define SPI_SR_UDR_Msk                                  (0x1u << SPI_SR_UDR_Pos)
#define SPI_SR_UDR                                      SPI_SR_UDR_Msk

#define SPI_SR_CRCERR_Pos                               (4u)
#define SPI_SR_CRCERR_Msk                               (0x1u << SPI_SR_CRCERR_Pos)
#define SPI_SR_CRCERR                                   SPI_SR_CRCERR_Msk

#define SPI_SR_MODF_Pos                                 (5u)
#define SPI_SR_MODF_Msk                                 (0x1u << SPI_SR_MODF_Pos)
#define SPI_SR_MODF                                     SPI_SR_MODF_Msk

#define SPI_SR_OVR_Pos                                 (6u)
#define SPI_SR_OVR_Msk                                 (0x1u << SPI_SR_OVR_Pos)
#define SPI_SR_OVR                                     SPI_SR_OVR_Msk

#define SPI_SR_BSY_Pos                                 (7u)
#define SPI_SR_BSY_Msk                                 (0x1u << SPI_SR_BSY_Pos)
#define SPI_SR_BSY                                     SPI_SR_BSY_Msk

#define SPI_SR_FRE_Pos                                 (8u)
#define SPI_SR_FRE_Msk                                 (0x1u << SPI_SR_FRE_Pos)
#define SPI_SR_FRE                                     SPI_SR_FRE_Msk
#endif /* INC_STM_SPI_REG_H_ */
