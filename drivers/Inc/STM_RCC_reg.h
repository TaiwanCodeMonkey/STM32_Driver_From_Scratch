#ifndef INC_STM_RCC_REG_H_
#define INC_STM_RCC_REG_H_
#include "stm32f446re.h"

/*******************  PLL Clock Config Structure  ******************/

typedef struct
{
    uint8_t PLL_Clc_Source;
    uint8_t AHB_Prescaler;
    uint8_t APB1_Prescaler;
    uint8_t APB2_Prescaler;
    uint16_t PLLM;
    uint16_t PLLN;
    uint16_t PLLP;
}PLL_Clock_Config;

/*******************  Bits definition for RCC_CR register  ******************/
#define RCC_CR_HSION_Pos                                                       0U
#define RCC_CR_HSION_Msk                                                       ((0x1) << RCC_CR_HSION_Pos)
#define RCC_CR_HSION                                                           RCC_CR_HSION_Msk

#define RCC_CR_HSIRDY_Pos                                                      1U
#define RCC_CR_HSIRDY_Msk                                                      ((0x2) << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSIRDY                                                          RCC_CR_HSIRDY_Msk

#define RCC_CR_HSITRIM_Pos                                                     3U
#define RCC_CR_HSIRIM_Msk                                                      ((0x1fU) << RCC_CR_HSITRIM)
#define RCC_CR_HSIRIM                                                          RCC_CR_HSIRIM_Msk

#define RCC_CR_HSICAL_Pos                                                      8U
#define RCC_CR_HSICAL_Msk                                                      ((0x7fU) << RCC_CR_HSICAL_Pos)
#define RCC_CR_HSICAL                                                          RCC_CR_HSICAL_Msk

#define RCC_CR_HSEON_Pos                                                       16U
#define RCC_CR_HSEON_Msk                                                       ((0x1 << RCC_CR_HSEON_Pos))
#define RCC_CR_HSEON                                                           RCC_CR_HSEON_Msk

#define RCC_CR_HSERDY_Pos                                                      17U

#define RCC_CR_HSEBYP_Pos                                                      18U
#define RCC_CR_HSEBYP_Msk                                                      ((0x1 << RCC_CR_HSEBYP_Pos))
#define RCC_CR_HSEBYP                                                          RCC_CR_HSEBYP_Msk

#define RCC_CR_CSSON_Pos                                                       19U
#define RCC_CR_CSSON_Msk                                                       ((0x1 << RCC_CR_CSSON_Pos))
#define RCC_CR_CSSON                                                           RCC_CR_CSSON_Msk

#define RCC_CR_PLLON_Pos                                                       24U
#define RCC_CR_PLLON_Msk                                                       ((0x1 << RCC_CR_PLLON_Pos))
#define RCC_CR_PLLON                                                           RCC_CR_PLLON_Msk

#define RCC_CR_PLLRDY_Pos                                                      25U

#define RCC_CR_PLLI2SON_Pos                                                    26U
#define RCC_CR_PLLI2SON_Msk                                                    ((0x1 << RCC_CR_PLLI2SON_Pos))
#define RCC_CR_PLLI2SON                                                        RCC_CR_PLLI2SON_Msk

#define RCC_CR_PLLI2SRDY_Pos                                                   27U

#define RCC_CR_PLLSAION_Pos                                                    28U
#define RCC_CR_PLLSAION_Msk                                                    ((0x1) << RCC_CR_PLLSAION_Pos)
#define RCC_CR_PLLSAION                                                        RCC_CR_PLLSAION_Msk

#define RCC_CR_PLLSAIRDY_Pos                                                   29U

/*******************  Bits definition for RCC_PLLCFGR register  ******************/
#define RCC_PLLCFGR_PLLM_Pos                                                   0U
#define RCC_PLLCFGR_PLLM_Msk                                                   ((0x3fU) << RCC_PLLCFGR_PLLM_Pos)
#define RCC_PLLCFGR_PLLM                                                       RCC_PLLCFGR_PLLM_Msk

#define RCC_PLLCFGR_PLLN_Pos                                                   6U
#define RCC_PLLCFGR_PLLN_Msk                                                   ((0x1ffU) << RCC_PLLN_Pos)
#define RCC_PLLCFGR_PLLN                                                       RCC_PLLCFGR_PLLN_Msk

#define RCC_PLLCFGR_PLLP_Pos                                                   16U
#define RCC_PLLCFGR_PLLP_Msk                                                   ((0x3U) << RCC_PLLCFGR_PLLP_Pos)
#define RCC_PLLCFGR_PLLP                                                       RCC_PLLCFGR_PLLP_Msk

#define RCC_PLLCFGR_PLLSRC_Pos                                                 22U
#define RCC_PLLCFGR_PLLSRC_Msk                                                 ((0x1U) << RCC_PLLCFGR_PLLSRC_Pos)
#define RCC_PLLCFGR_PLLSRC                                                     RCC_PLLCFGR_PLLSRC_Msk

#define RCC_PLLCFGR_PLLQ_Pos                                                   24U
#define RCC_PLLCFGR_PLLQ_Msk                                                   ((0xfU) << RCC_PLLCFGR_PLLQ_Pos)
#define RCC_PLLCFGR_PLLQ                                                       RCC_PLLCFGR_PLLQ_Msk

#define RCC_PLLCFGR_PLLR_Pos                                                   29U
#define RCC_PLLCFGR_PLLR_Msk                                                   ((0x7U) << RCC_PLLCFGR_PLLR_Pos)
#define RCC_PLLCFGR_PLLR                                                       RCC_PLLCFGR_PLLR_Msk

/*******************  Bits definition for RCC_CFGR register  ******************/
#define RCC_CFGR_SW_Pos                                                        0U
#define RCC_CFGR_SW_Msk                                                        ((0x3U) << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW                                                            RCC_CFGR_SW_Msk

#define RCC_CFGR_SWS_Pos                                                       1U

#define RCC_CFGR_HPRE_Pos                                                      4U
#define RCC_CFGR_HPRE_Msk                                                      ((0xfU) << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE                                                          RCC_CFGR_HPRE_Msk

#define RCC_CFGR_PPRE1_Pos                                                      10U
#define RCC_CFGR_PPRE1_Msk                                                      ((0x7U) << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1                                                          RCC_CFGR_PPRE1_Msk

#define RCC_CFGR_PPRE2_Pos                                                     13U
#define RCC_CFGR_PPRE2_Msk                                                     ((0xfU) << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2                                                         RCC_CFGR_PPRE2_Msk

#define RCC_CFGR_RTCPRE_Pos                                                    16U
#define RCC_CFGR_RTCPRE_Msk                                                    ((0x1fU) << RCC_CFGR_RTCPRE_Pos)
#define RCC_CFGR_RTCPRE                                                        RCC_CFGR_RTCPRE_Msk

#define RCC_CFGR_MCO1_Pos                                                      21U
#define RCC_CFGR_MCO1_Msk                                                      ((0x3) << RCC_CFGR_MCO1_Pos)
#define RCC_CFGR_MCO1                                                          RCC_CFGR_MCO1_Msk

#define RCC_CFGR_MCO1PRE_Pos                                                   24U
#define RCC_CFGR_MCO1PRE_Msk                                                   ((0x7U) << RCC_CFGR_MCO1PRE_Pos)
#define RCC_CFGR_MCO1PRE                                                       RCC_CFGR_MCO1PRE_Msk

#define RCC_CFGR_MCO2PRE_Pos                                                   27U
#define RCC_CFGR_MCO2PRE_Msk                                                   ((0x7U) << RCC_CFGR_MCO2PRE_Pos)
#define RCC_CFGR_MCO2PRE                                                       RCC_CFGR_MCO2PRE_Msk

#define RCC_CFGR_MCO2_Pos                                                      30U
#define RCC_CFGR_MCO2_Msk                                                      ((0x3) << RCC_CFGR_MCO2_Pos)
#define RCC_CFGR_MCO2                                                          RCC_CFGR_MCO2_Msk

/*******************  Bits definition for RCC_APB1RSTR register  ******************/
#define RCC_APB1RSTR_Tim2RST_Pos                                               0U
#define RCC_APB1RSTR_Tim3RST_Pos                                               1U
#define RCC_APB1RSTR_Tim4RST_Pos                                               2U
#define RCC_APB1RSTR_Tim5RST_Pos                                               3U
#define RCC_APB1RSTR_Tim6RST_Pos                                               4U
#define RCC_APB1RSTR_Tim7RST_Pos                                               5U
#define RCC_APB1RSTR_Tim12RST_Pos                                              6U
#define RCC_APB1RSTR_Tim13RST_Pos                                              7U
#define RCC_APB1RSTR_Tim14RST_Pos                                              8U
#define RCC_APB1RSTR_WWDGRST_Pos                                               11U
#define RCC_APB1RSTR_SPI2RST_Pos                                               14U
#define RCC_APB1RSTR_SPI3RST_Pos                                               15U
#define RCC_APB1RSTR_SPDIFRXRST_Pos                                            16U
#define RCC_APB1RSTR_UART2RST_Pos                                              17U
#define RCC_APB1RSTR_UART3RST_Pos                                              18U
#define RCC_APB1RSTR_UART4RST_Pos                                              19U
#define RCC_APB1RSTR_UART5RST_Pos                                              20U
#define RCC_APB1RSTR_I2C1RST_Pos                                               21U
#define RCC_APB1RSTR_I2C2RST_Pos                                               22U
#define RCC_APB1RSTR_I2C3RST_Pos                                               23U
#define RCC_APB1RSTR_FMPI2C1RST_Pos                                            24U
#define RCC_APB1RSTR_CAN1RST_Pos                                               25U
#define RCC_APB1RSTR_CAN2RST_Pos                                               26U
#define RCC_APB1RSTR_CECRST_Pos                                                27U
#define RCC_APB1RSTR_PWRRST_Pos                                                28U
#define RCC_APB1RSTR_DACRST_Pos                                                29U
// Macro for PLL Clock configuration and function declear
#define PLL_CLC_ENABLE()                                                       (RCC -> RCC_CR |= RCC_CR_PLLON_Msk)
#define PLL_CLC_PLLM(Div_Factor)                                               do{ (RCC -> RCC_PLLCFGR &= ~(0x3Fu << RCC_PLLCFGR_PLLM_Pos)); (RCC -> RCC_PLLCFGR |= (Div_Factor << RCC_PLLCFGR_PLLM_Pos));}while(0)
#define PLL_CLC_PLLN(Div_Factor)                                               do{ (RCC -> RCC_PLLCFGR &= ~(0x1FFu << RCC_PLLCFGR_PLLN_Pos)); (RCC -> RCC_PLLCFGR |= (Div_Factor << RCC_PLLCFGR_PLLM_Pos));}while(0)
// #define PLL_CLC_PLLP(Div_Factor)                                               (RCC -> RCC_PLLCFGR |= (Div_Factor << RCC_PLLCFGR_PLLP_Pos))
#define PLL_CLL_HSI_SRC()                                                      (RCC -> RCC_PLLCFGR &= ~(1U << RCC_PLLCFGR_PLLSRC_Pos))
#define PLL_CLL_HSE_SRC()                                                      (RCC -> RCC_PLLCFGR |= (1U << RCC_PLLCFGR_PLLSRC_Pos))
// Macro for Setting System Clock
#define System_Clock_Switch(data)                                               (RCC -> RCC_CFGR |= (data << RCC_CFGR_SW_Pos))
void PLL_CLC_PLLP(RCC_RegDef_t* RCC_PTR, uint8_t Div_Factor);
void AHB_Prescaler(RCC_RegDef_t* RCC_PTR, uint8_t Scaler);
void APB1_Prescaler(RCC_RegDef_t* RCC_PTR, uint8_t Scaler);
void APB2_Prescaler(RCC_RegDef_t* RCC_PTR, uint8_t Scaler);
void PLL_CLC_Init(PLL_Clock_Config* PLL_CLC_Config);
#endif /* INC_STM_RCC_REG_H_ */
