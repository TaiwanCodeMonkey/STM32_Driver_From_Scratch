#include "stm32f446re.h"
#include <stdlib.h>
#include <stdio.h>
uint8_t getRandom(void)
{
	uint8_t random_number = (rand() % (255 - 1 + 1)) + 1;
	return random_number;
}
 int main(void)
 {
	PLL_Clock_Config pll_config;
	pll_config.PLL_Clc_Source = 2;
	pll_config.AHB_Prescaler = 2;
	pll_config.APB1_Prescaler = 2;
	pll_config.APB2_Prescaler = 0;
	pll_config.PLLM = 16;
	pll_config.PLLN = 336;
	pll_config.PLLP = 4;
	PLL_CLC_Init(&pll_config);
//    HSI_SysClock_Enable();
	CAN1_CLC_EN();
	GPIO_PeriClockControl(GPIOA, ENABLE);
	CAN_TXRX_GPIO_Configure(11);
	CAN_TXRX_GPIO_Configure(12);
	CAN_Handle_t CAN1_Config;
	CAN1_Config.pCANx = CAN1;
	CAN1_Config.CAN_BitTiming.TS1 = 10;
	CAN1_Config.CAN_BitTiming.TS2 = 2;
	CAN1_Config.CAN_BitTiming.SJW =  1;
	CAN1_Config.CAN_BitTiming.LBKM = 1;
	CAN1_Config.CAN_BitTiming.SILM = 0;
	CAN1_Config.CAN_BitTiming.BRP = 3;
	CAN_Status status;
	status = CAN_Init(&CAN1_Config);
	status = CAN_Start(CAN1_Config.pCANx);
	SET_BIT(CAN1 -> CAN_MCR, 16);
	CAN_FilterCon_t Filter_Config;
	Filter_Config.FilterIdHigh = 0x298;
	Filter_Config.FilterIdLow = 0x293;
	Filter_Config.FilterMaskIdHigh = 0;
	Filter_Config.FilterMaskIdLow = 0x0;
	Filter_Config.FilterFIFOAssigment = CAN_FILTER_FIFO0;
	Filter_Config.BankNumber = 2;
	Filter_Config.FilterMode = CAN_FILTERMODE_IDLIST;
	Filter_Config.FilterScale = CAN_FILTERSCALE_32BIT;
	CAN_FilterConfig(CAN1, &Filter_Config);
	uint8_t data[8];
	CAN_TxHeaderTypeDef header;
	header.StdId = 0x293;
	header.ExtId = 0;
	header.IDE = 0;
	header.DLC = 8;
	header.RTR = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 8; i++)
			data[i] = getRandom();
		status = Send_TxMessage(&header, CAN1, data);
		uint8_t rxbuffer[8];
		CAN_RxHeaderTypeDef rheader;
		Receive_RxMessage(CAN1, &rheader, 0, rxbuffer);
	}
	while (1);
	return 1;
 }
