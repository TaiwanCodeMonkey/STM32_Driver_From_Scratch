#include "STM_RCC_reg.h"
#define HSE_SOURCE     1
#define HSI_SOURCE     2
void PLL_CLC_Init(PLL_Clock_Config* PLL_CLC)
{
    uint8_t Pll_Source = PLL_CLC -> PLL_Clc_Source;
    uint8_t AHB = PLL_CLC -> AHB_Prescaler;
    uint8_t APB1 = PLL_CLC -> APB1_Prescaler;
    uint8_t APB2 = PLL_CLC -> APB2_Prescaler;
    uint16_t PLLM = PLL_CLC -> PLLM;
    uint16_t PLLN = PLL_CLC -> PLLN;
    uint16_t PLLP = PLL_CLC -> PLLP;

    switch(Pll_Source)
    {
        case HSE_SOURCE:
            HSE_ON();
            PLL_CLL_HSE_SRC();
            break;
        case HSI_SOURCE:
            PLL_CLL_HSI_SRC();
            break;
        default:
            break;
    }
    PLL_CLC_PLLM(PLLM);
    PLL_CLC_PLLN(PLLN);
    PLL_CLC_PLLP(RCC, PLLP);
    AHB_Prescaler(RCC,AHB);
    APB1_Prescaler(RCC, APB1);
    APB2_Prescaler(RCC, APB2);
    PLL_ON();
    PLL_SysClock_Enable();

}
void PLL_CLC_PLLP(RCC_RegDef_t* RCC_PTR, uint8_t Div_Factor) {

    RCC_PTR -> RCC_PLLCFGR &= ~(0x3 << RCC_PLLCFGR_PLLM_Pos);
    switch(Div_Factor)
    {
        case 2:
            RCC_PTR -> RCC_PLLCFGR |= (0 << RCC_PLLCFGR_PLLP_Pos);
            break;
        case 4:
            RCC_PTR -> RCC_PLLCFGR |= (1 << RCC_PLLCFGR_PLLP_Pos);
            break;
        case 6:
            RCC_PTR -> RCC_PLLCFGR |= (2 << RCC_PLLCFGR_PLLP_Pos);
            break;
        case 8:
            RCC_PTR -> RCC_PLLCFGR |= (3 << RCC_PLLCFGR_PLLP_Pos);
            break;
        default:
            break;
    }
}

void AHB_Prescaler(RCC_RegDef_t* RCC_PTR, uint8_t Scaler) {

    RCC_PTR -> RCC_CFGR &= ~(0xfu << RCC_CFGR_HPRE_Pos);
    switch(Scaler)
    {
        case 2:
            RCC_PTR -> RCC_CFGR |= (8 << RCC_CFGR_HPRE_Pos);
            break;
        case 4:
            RCC_PTR -> RCC_CFGR |= (9 << RCC_CFGR_HPRE_Pos);
            break;
        case 8:
            RCC_PTR -> RCC_CFGR |= (10 << RCC_CFGR_HPRE_Pos);
            break;
        case 16:
            RCC_PTR -> RCC_CFGR |= (11 << RCC_CFGR_HPRE_Pos);
            break;
        case 64:
            RCC_PTR -> RCC_CFGR |= (12 << RCC_CFGR_HPRE_Pos);
            break;
        case 128:
            RCC_PTR -> RCC_CFGR |= (13 << RCC_CFGR_HPRE_Pos);
            break;
        case 256:
            RCC_PTR -> RCC_CFGR |= (14 << RCC_CFGR_HPRE_Pos);
            break;
        case 512:
            RCC_PTR -> RCC_CFGR |= (15 << RCC_CFGR_HPRE_Pos);
            break;
        default:
            break; 
    }
}
void APB1_Prescaler(RCC_RegDef_t* RCC_PTR, uint8_t Scaler) {

    RCC_PTR -> RCC_CFGR &= ~(0x7u << RCC_CFGR_PPRE1_Pos);
    switch(Scaler)
    {
        case 2:
            RCC_PTR -> RCC_CFGR |= (4 << RCC_CFGR_PPRE1_Pos);
            break;
        case 4:
            RCC_PTR -> RCC_CFGR |= (5 << RCC_CFGR_PPRE1_Pos);
            break;
        case 8:
            RCC_PTR -> RCC_CFGR |= (6 << RCC_CFGR_PPRE1_Pos);
            break;
        case 16:
            RCC_PTR -> RCC_CFGR |= (7 << RCC_CFGR_PPRE1_Pos);
            break;
        default:
            break;
    }
}

void APB2_Prescaler(RCC_RegDef_t* RCC_PTR, uint8_t Scaler) {

    RCC_PTR -> RCC_CFGR &= ~(0x7u << RCC_CFGR_PPRE2_Pos);
    switch(Scaler)
    {
        case 2:
            RCC_PTR -> RCC_CFGR |= (4 << RCC_CFGR_PPRE2_Pos);
            break;
        case 4:
            RCC_PTR -> RCC_CFGR |= (5 << RCC_CFGR_PPRE2_Pos);
            break;
        case 8:
            RCC_PTR -> RCC_CFGR |= (6 << RCC_CFGR_PPRE2_Pos);
            break;
        case 16:
            RCC_PTR -> RCC_CFGR |= (7 << RCC_CFGR_PPRE2_Pos);
            break;
        default:
            break;
    }
}
