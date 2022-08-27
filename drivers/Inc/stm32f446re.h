
#ifndef INC_STM32F446RE_H_
#define INC_STM32F446RE_H_
#include <stdint.h>
#include <stddef.h>
#define __vo volatile
typedef unsigned int STM_UREG_32Bit;
typedef signed int STM_SREG_32Bit;

/************************************START:Processor Specific Details**************************************
 * 
 * ARM Cortex Mx Processor NVIC ISERx Register Address
*/
#define NVIC_ISER0                   ((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1                   ((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2                   ((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3                   ((__vo uint32_t*)0xE000E10C)

/*
* ARM Cortex Mx Processor NVIC ICERx Register Address
*/
#define NVIC_ICER0                   ((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1                   ((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2                   ((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3                   ((__vo uint32_t*)0xE000E18C)

/*
* ARM Cortex Mx Processor NVIC IPRx Register Address
*/
#define NVIC_PR_BASE_ADDR            ((__vo uint32_t*)0xE000E400)
#define NO_PR_BITS_IMPLEMENTED       4
/*
* base addresses of Flash and SRAM memories
*/
#define FLASH_BASEADDR               (uint32_t)0x08000000
#define SRAM1_BASEADDR               (uint32_t)0x20000000 //112KB
#define SRAN2_BASEADDR               (uint32_t)0x20001C00
#define ROM                          (uint32_t)0x1FFF0000
#define SRAM                         SRAM1_BASEADDR

/*
* AHBx and APBx Bus Peripheral base addresses
*/

#define PERIPH_BASE                   (uint32_t)0x40000000
#define APB1PERIPH_BASE                PERIPH_BASE
#define APB2PERIPH_BASE               (uint32_t)0x40010000
#define AHB1PERIPH_BASE               (uint32_t)0x40020000
#define AHB2PERIPH_BASE               (uint32_t)0x50000000

/*
* Base address of peripheral which are hanging on AHB1 bus
*/
#define GPIOA_BASEADDR                (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR                (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR                (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR                (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR                (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR                (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR                (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR                (AHB1PERIPH_BASE + 0x1C00)
#define RCC_BASEADDR                  (AHB1PERIPH_BASE + 0x3800)
/*
* Base address of peripheral which are hanging on APB1 Bus
*/

#define I2C1_BASEADDR                 (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR                 (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR                 (APB1PERIPH_BASE + 0x5C00)

#define SPI1_BASEADDR                 (APB2PERIPH_BASE + 0x3000)
#define SPI2_BASEADDR                 (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR                 (APB1PERIPH_BASE + 0x3C00)
#define SPI4_BASEADDR                 (APB2PERIPH_BASE + 0x3400)

#define USART2_BASEADDR                (APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR                (APB1PERIPH_BASE + 0x4800)
#define UART4_BASEADDR                (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR                (APB1PERIPH_BASE + 0x5000)

#define CAN1_BASEADDR                 (APB1PERIPH_BASE + 0x6400)
#define CAN2_BASEADDR                 (APB1PERIPH_BASE + 0x6800)
/*
* Base address of peripheral which are hanginh on APB2 Bus
*/
#define EXTI_BASEADDR                 (APB2PERIPH_BASE + 0x3C00)
#define SPI1_BASEADDR                 (APB2PERIPH_BASE + 0x3000)
#define USART1_BASEADDR               (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR               (APB2PERIPH_BASE + 0x1400)
#define SYSCFG_BASEADDR               (APB2PERIPH_BASE + 0x3800)


/*
* Note : Register of peripheral are specific to MCU
*/
typedef struct
{
    __vo uint32_t MODER;                   // GPIO port mode register                   Address offset 0x00
    __vo uint32_t OTYPER;                  // GPIO port output type register            Address offset 0x04
    __vo uint32_t OSPEEDR;                // GPIO port output speed register           Address offset 0x08
    __vo uint32_t PUPDR;                   // GPIO port pull-up/pull-down register      Address offset 0x0C
    __vo uint32_t IDR;                     // GPIO port input data register             Address offset 0x10
    __vo uint32_t ODR;                     // GPIO port output data register            Address offset 0x14
    __vo uint32_t BSRR;                    // GPIO port bit set/reset register          Address offset 0x18
    __vo uint32_t LCKR;                    // GPIO port configuration lock register     Address offset 0x1C
    __vo uint32_t AFR[2];                  // GPIO alternate function low/high register Address offset 0x20 0x24
}GPIO_RegDef_t;

typedef struct
{
    __vo uint32_t RCC_CR;
    __vo uint32_t RCC_PLLCFGR;
    __vo uint32_t RCC_CFGR;
    __vo uint32_t RCC_CIR;
    __vo uint32_t RCC_AHB1RSTR;
    __vo uint32_t RCC_AHB2RSTR;
    __vo uint32_t RCC_AHB3RSTR;
    __vo uint32_t Reserved0;
    __vo uint32_t RCC_APB1RSTR;
    __vo uint32_t RCC_APB2RSTR;
    __vo uint32_t Reserved1[2];
    __vo uint32_t RCC_AHB1ENR;
    __vo uint32_t RCC_AHB2ENR;
    __vo uint32_t RCC_AHB3ENR;
    __vo uint32_t Reserved2;
    __vo uint32_t RCC_APB1ENR;
    __vo uint32_t RCC_APB2ENR;
    uint32_t Reserved3[2];
    __vo uint32_t RCC_AHB1LPENR;
    __vo uint32_t RCC_AHB2LPENR;
    __vo uint32_t RCC_AHB3LPENR;
    uint32_t Reserved4[2];
    __vo uint32_t RCC_APB1LPENR;
    __vo uint32_t RCC_APB2LPENR;
    uint32_t Reserved5[2];
    __vo uint32_t RCC_BDCR;
    __vo uint32_t RCC_CSR;
    uint32_t Reserved6[2];
    __vo uint32_t RCC_SSCGR;
    __vo uint32_t RCC_PLLI2SCFGR;
    __vo uint32_t RCC_PLLSAICFGR;
    __vo uint32_t RCC_DCKCFGR;
    __vo uint32_t RCC_CKGATENR;
    __vo uint32_t RCC_DCKCFGR2;
}RCC_RegDef_t;

typedef struct
{
    __vo uint32_t IMR;
    __vo uint32_t EMR;
    __vo uint32_t RTSR;
    __vo uint32_t FTSR;
    __vo uint32_t SWIER;
    __vo uint32_t PR;
}EXIT_RegDef_t;

typedef struct
{
    __vo uint32_t MEMRMP;
    __vo uint32_t PMC;
    __vo uint32_t EXTICR[4];
    uint32_t RESERVED1[2];
    __vo uint32_t CMPCR;
    uint32_t RESERVED2[2];
    __vo uint32_t CFGR;
}SYSCFG_RegDef_t;

/*
* peripheral definitions ( Peripheral base address typecasted to xxx_RegDef_t)
*/
#define GPIOA            ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB            ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC            ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD            ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE            ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF            ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG            ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH            ((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC              ((RCC_RegDef_t*)RCC_BASEADDR)
#define EXTI             ((EXIT_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG          ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
/*
* Clock Enable Macros for GPIOx peripherals
*/
#define GPIOA_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()       (RCC -> RCC_AHB1ENR |= (1 << 7))

#define GPIOA_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DIS()      (RCC -> RCC_AHB1ENR &= ~(1 << 7))
/*
* Clock Enable Macros for I2Cx peripherals
*/
#define I2C1_PCLK_EN()         (RCC -> RCC_APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()         (RCC -> RCC_APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()         (RCC -> RCC_APB1ENR |= (1 << 23))

/*
* Clock Enable Macros for SPI peripherals
*/
#define SPI1_PCLK_EN()          (RCC -> RCC_APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()          (RCC -> RCC_APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()          (RCC -> RCC_APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()          (RCC -> RCC_APB2ENR |= (1 << 13))

#define SPI1_PCLK_DIS()          (RCC -> RCC_APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DIS()          (RCC -> RCC_APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DIS()          (RCC -> RCC_APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DIS()          (RCC -> RCC_APB2ENR &= ~(1 << 13))
/*
* Clock Enable Macros for CAN peripherals
*/
#define CAN1_CLC_EN()       (RCC -> RCC_APB1ENR |= (1 << 25))
#define CAN2_CLC_EN()       (RCC -> RCC_APB1ENR |= (1 << 26))

/*
* Clock Enable Macros for SYSCFG peripherals
*/
#define SYSCFG_CLC_EN()     (RCC -> RCC_APB2ENR |= (1 << 14))
/*
* Macros to set system clock
*/
#define HSI_ON()               (RCC -> RCC_CR |= RCC_CR_HSION)
#define PLL_ON()               (RCC -> RCC_CR |= RCC_CR_PLLON)
#define HSE_ON()               (RCC -> RCC_CR |= RCC_CR_HSEON)
#define HSI_SysClock_Enable()  (RCC -> RCC_CFGR &= ~(0x3))
#define PLL_SysClock_Enable()  (RCC -> RCC_CFGR |= 0x2)

/*

/*
* Macros to set PLL Configuration
*/
// #define 
/*
*Macros to reset GPIOx peripherals
*/
#define GPIOA_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 0)); (RCC -> RCC_AHB1RSTR &= ~(1 << 0));}while(0)
#define GPIOB_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 1)); (RCC -> RCC_AHB1RSTR &= ~(1 << 1));}while(0)
#define GPIOC_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 2)); (RCC -> RCC_AHB1RSTR &= ~(1 << 2));}while(0)
#define GPIOD_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 3)); (RCC -> RCC_AHB1RSTR &= ~(1 << 3));}while(0)
#define GPIOE_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 4)); (RCC -> RCC_AHB1RSTR &= ~(1 << 4));}while(0)
#define GPIOF_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 5)); (RCC -> RCC_AHB1RSTR &= ~(1 << 5));}while(0)
#define GPIOG_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 6)); (RCC -> RCC_AHB1RSTR &= ~(1 << 6));}while(0)
#define GPIOH_REG_RESRT()                      do{ (RCC -> RCC_AHB1RSTR |= (1 << 7)); (RCC -> RCC_AHB1RSTR &= ~(1 << 7));}while(0)

#define GPIO_BASEADDR_TO_CODE(x)                    ( (x == GPIOA) ? 0 :\
                                                       (x == GPIOB) ? 1 :\
                                                       (x == GPIOC) ? 2 :\
                                                       (x == GPIOD) ? 3 :\
                                                       (x == GPIOF) ? 4 :\
                                                       (x == GPIOG) ? 5 :\
                                                       (x == GPIOH) ? 6 : 0)


/*
*Macros to reset SPIx peripherals
*/
#define SPI1_REG_RESRT()                     do {(RCC -> RCC_APB2RSTR |= (1 << 12)); (RCC -> RCC_APB2RSTR &= ~(1 << 12));}while(0)
#define SPI2_REG_RESRT()                     do {(RCC -> RCC_APB1RSTR |= (1 << 14)); (RCC -> RCC_APB1RSTR &= ~(1 << 14));}while(0)
#define SPI3_REG_RESRT()                     do {(RCC -> RCC_APB1RSTR |= (1 << 15)); (RCC -> RCC_APB1RSTR &= ~(1 << 15));}while(0)
#define SPI4_REG_RESRT()                     do {(RCC -> RCC_APB2RSTR |= (1 << 12)); (RCC -> RCC_APB2RSTR &= ~(1 << 13));}while(0)
/* IRQ(Interrupt Request) Numbers of STM32F407x MCU
* NOTE: update these macros with valid values according to MCU
*/
#define IRQ_NO_EXTI0           6
#define IRQ_NO_EXTI1           7
#define IRQ_NO_EXTI2           8
#define IRQ_NO_EXTI3           9
#define IRQ_NO_EXTI4           10
#define IRQ_NO_EXTI9_5         23
#define IRQ_NO_EXTI15_10       40
#define IRQ_NO_SPI1            35
#define IRQ_NO_SPI2            36
#define IRQ_NO_SPI3            51

/*
* MACROS for all the possible priority levels
*/
#define NVIC_IRQ_PRI0          0
#define NVIC_IRQ_PRI15         15
/*
* Macros to reset CAN peripherals
*/
#define CAN1_REG_RESRT()                       do{ (RCC -> RCC_APB1RSTR |= (1 << RCC_APB1RSTR_CAN1RST_Pos)); (RCC -> RCC_APB1RSTR &= ~(1 << RCC_APB1RSTR_CAN1RST_Pos));}while(0)
#define CAN2_REG_RESRT()                       do{ (RCC -> RCC_APB1RSTR |= (1 << RCC_APB1RSTR_CAN2RST_Pos)); (RCC -> RCC_APB1RSTR &= ~(1 << RCC_APB1RSTR_CAN2RST_Pos));}while(0)
// some genric Macros
#define ENABLE                 1
#define DISABLE                0
#define SET                    ENABLE
#define RESET                  DISABLE
#define GPIO_PIN_SET           SET
#define GPIO_PIN_RESET         RESET
#define BUSY                   1
#define FREE                   0
#define FLAG_RESET             RESET
#define FLAG_SET               SET
#define WRITE_REG(REG, VAL)    ((REG) = (VAL))
#define CLEAR_BIT(REG, BIT)    ((REG) &= ~(1U << BIT))
#define SET_BIT(REG, BIT)      ((REG) |= (1U << BIT))
#define READBIT(REG, BIT)      (((REG) >> (BIT)) & 1)
#include "stm32f446re_gpio_driver.h"
#include "stm32f446re_flash_driver.h"
#include "stm32f446re_can_driver.h"
#include "stm32f446re_spi_driver.h"
#endif /* INC_STM32F446RE_H_ */ 
