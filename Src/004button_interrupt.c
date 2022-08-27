#include "stm32f446re.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void delay(void)
{
    for (uint32_t i = 0; i < 50000 / 2; i++);
}
int main(void)
{

    GPIO_Handle_t GpioLed, GPIOBtn;
    memset(&GpioLed, 0, sizeof(GpioLed));
    memset(&GPIOBtn, 0, sizeof(GPIOBtn));
    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = 5;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioLed);

   // this is btn gpio configuration
    GPIOBtn.pGPIOx = GPIOC;
    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = 13;
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
    GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PULLUP;
    GPIO_PeriClockControl(GPIOC, ENABLE);
    GPIO_Init(&GPIOBtn);
    GPIO_WriteToOutputPin(GPIOA, 5, GPIO_PIN_RESET);
    // IRQ configuration
    GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, 15);
    GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);
    while(1);
    return 0;
}

void EXTI15_10_IRQHandler(void) {
//	delay();
    GPIO_IRQHandling(13);
    GPIO_ToggleOutputPin(GPIOA, 5);
}
