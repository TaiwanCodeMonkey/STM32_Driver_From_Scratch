
#include "stm32f446re.h"
#include <stdlib.h>
#include <stdio.h>
void delay(void)
{
    for (uint32_t i = 0; i < 50000; i++);
}
int main(void)
{
    GPIO_Handle_t GpioLed;
    GpioLed.pGPIOx = GPIOA;
//     GpioLed.pGPIOx = MODULE_GPIOA;
   GpioLed.GPIO_PinConfig.GPIO_PinNumber = 5;
   GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
   GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
   GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
   GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
//    MODULE_GPIOA -> MODER.B.MODER5 = 1;
   GPIO_PeriClockControl(GPIOA, ENABLE);
//    MODULE_GPIOA -> MODER.B.MODER5 = 0;
   GPIO_Init(&GpioLed);
   while (1)
   {
       GPIO_ToggleOutputPin(GPIOA, 5);
       delay();
   }
    printf("Finish!!\n");
   return 0;
}

