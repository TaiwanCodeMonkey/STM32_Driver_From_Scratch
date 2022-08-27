
// PB12 SPI2 NSS
// PB13 SPI2 SCK
// PB14 SPI2 MISO
// PB15 SPI2 MOSI
// ALT function mode : 5
#include "stm32f446re.h"
#include <string.h>
void SPI_GPIOInits(void)
{
	GPIO_Handle_t SPIPins;
	SPIPins.pGPIOx = GPIOB;
	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = AF5;
    SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	// NSS
	//SPIPins.GPIO_PinConfig.GPIO_PinNumber = 12;
	//GPIO_Init(&SPIPins);
	// SCLK
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = 13;
	GPIO_Init(&SPIPins);
    // MISO
	//SPIPins.GPIO_PinConfig.GPIO_PinNumber = 14;
	//GPIO_Init(&SPIPins);
    // MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = 15;
	GPIO_Init(&SPIPins);
}
void SPI2_Inits(void)
{
	SPI_Handle_t SPI2handle;
	SPI2handle.pSPIx = SPI2;
	SPI2handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	SPI2handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	SPI2handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV2;
	SPI2handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI2handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI2handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	SPI2handle.SPIConfig.SPI_SSM = SPI_SSM_EN; // software salve managment enabled for NSS pin
	SPI_Init(&SPI2handle);
}
int main(void)
{
	char user_data[] = "Hello world";
	SPI_GPIOInits();
	SPI2_Inits();
	SPI_PeripheralControl(SPI2, ENABLE);
	SPI_Send(SPI2, (uint8_t*)user_data, strlen(user_data));
	SPI_PeripheralControl(SPI2, DISABLE);
	while(1);
	return 0;
}
