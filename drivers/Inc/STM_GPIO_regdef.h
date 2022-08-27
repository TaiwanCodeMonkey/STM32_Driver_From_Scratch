#ifndef INC_STM_GPIO_REGDEF_H_
#define INC_STM_GPIO_REGDEF_H_

#include "stm32f446re.h"
typedef struct _STM_GPIO_MODER_Bits
{
    STM_UREG_32Bit MODER0:2;                   /**< \brief [0:1] Port 0 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER1:2;                   /**< \brief [2:3] Port 1 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER2:2;                   /**< \brief [4:5] Port 2 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER3:2;                   /**< \brief [6:7] Port 3 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER4:2;                   /**< \brief [8:9] Port 4 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER5:2;                   /**< \brief [10:11] Port 5 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER6:2;                   /**< \brief [12:13] Port 6 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER7:2;                   /**< \brief [14:15] Port 7 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER8:2;                   /**< \brief [16:17] Port 8 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER9:2;                   /**< \brief [18:19] Port 9 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER10:2;                  /**< \brief [20:21] Port 10 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER11:2;                  /**< \brief [22:23] Port 11 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER12:2;                  /**< \brief [24:25] Port 12 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER13:2;                  /**< \brief [26:27] Port 13 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER14:2;                  /**< \brief [28:29] Port 14 mode cofiguration bits (rw) */
    STM_UREG_32Bit MODER15:2;                  /**< \brief [30:31] Port 15 mode cofiguration bits (rw) */
}STM_GPIO_MODER_Bits;

typedef struct _STM_GPIO_OTYPER_Bits
{
    STM_UREG_32Bit OT0:1;                    /**< \brief [0] Port 0 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT1:1;                    /**< \brief [1] Port 1 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT2:1;                    /**< \brief [2] Port 2 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT3:1;                    /**< \brief [3] Port 3 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT4:1;                    /**< \brief [4] Port 4 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT5:1;                    /**< \brief [5] Port 5 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT6:1;                    /**< \brief [6] Port 6 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT7:1;                    /**< \brief [7] Port 7 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT8:1;                    /**< \brief [8] Port 8 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT9:1;                    /**< \brief [9] Port 9 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT10:1;                    /**< \brief [10] Port 0 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT11:1;                    /**< \brief [11] Port 0 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT12:1;                    /**< \brief [12] Port 0 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT13:1;                    /**< \brief [13] Port 0 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT14:1;                    /**< \brief [14] Port 0 output type cofiguration bits (rw) */
    STM_UREG_32Bit OT15:1;                    /**< \brief [15] Port 0 output type cofiguration bits (rw) */
    STM_UREG_32Bit Reserved:16;               /**< \brief [16-31] Reserved bit (not accessable) */
}STM_GPIO_OTYPER_Bits;

typedef struct _STM_GPIO_OSPEEDR_Bits
{
    STM_UREG_32Bit OSPEEDR0:2;                   /**< \brief [0:1] Port 0 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR1:2;                   /**< \brief [2:3] Port 1 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR2:2;                   /**< \brief [4:5] Port 2 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR3:2;                   /**< \brief [6:7] Port 3 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR4:2;                   /**< \brief [8:9] Port 4 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR5:2;                   /**< \brief [10:11] Port 5 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR6:2;                   /**< \brief [12:13] Port 6 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR7:2;                   /**< \brief [14:15] Port 7 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR8:2;                   /**< \brief [16:17] Port 8 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR9:2;                   /**< \brief [18:19] Port 9 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR10:2;                  /**< \brief [20:21] Port 10 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR11:2;                  /**< \brief [22:23] Port 11 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR12:2;                  /**< \brief [24:25] Port 12 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR13:2;                  /**< \brief [26:27] Port 13 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR14:2;                  /**< \brief [28:29] Port 14 output speed cofiguration bits (rw) */
    STM_UREG_32Bit OSPEEDR15:2;                  /**< \brief [30:31] Port 15 output speed cofiguration bits (rw) */ 
}STM_GPIO_OSPEEDR_Bits;

typedef struct _STM_GPIO_PUPDR_Bits
{
    STM_UREG_32Bit PUPDR0:2;                   /**< \brief [0:1] Port 0 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR1:2;                   /**< \brief [2:3] Port 1 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR2:2;                   /**< \brief [4:5] Port 2 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR3:2;                   /**< \brief [6:7] Port 3 pull-up/pull-downcofiguration bits (rw) */
    STM_UREG_32Bit PUPDR4:2;                   /**< \brief [8:9] Port 4 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR5:2;                   /**< \brief [10:11] Port 5 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR6:2;                   /**< \brief [12:13] Port 6 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR7:2;                   /**< \brief [14:15] Port 7 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR8:2;                   /**< \brief [16:17] Port 8 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR9:2;                   /**< \brief [18:19] Port 9 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR10:2;                  /**< \brief [20:21] Port 10 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR11:2;                  /**< \brief [22:23] Port 11 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR12:2;                  /**< \brief [24:25] Port 12 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR13:2;                  /**< \brief [26:27] Port 13 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR14:2;                  /**< \brief [28:29] Port 14 pull-up/pull-down cofiguration bits (rw) */
    STM_UREG_32Bit PUPDR15:2;                  /**< \brief [30:31] Port 15 pull-up/pull-down cofiguration bits (rw) */ 
}STM_GPIO_PUPDR_Bits;

typedef struct _Stm_GPIO_IDR_Bits
{
    STM_UREG_32Bit IDR:1;                     /**< \brief [0] Port 0  input data bits (rw) */
    STM_UREG_32Bit IDR1:1;                    /**< \brief [1] Port 1  input data bits (rw) */
    STM_UREG_32Bit IDR2:1;                    /**< \brief [2] Port 2  input data bits (rw) */
    STM_UREG_32Bit IDR3:1;                    /**< \brief [3] Port 3  input data bits (rw) */
    STM_UREG_32Bit IDR4:1;                    /**< \brief [4] Port 4  input data (rw) */
    STM_UREG_32Bit IDR5:1;                    /**< \brief [5] Port 5  input data (rw) */
    STM_UREG_32Bit IDR6:1;                    /**< \brief [6] Port 6  input data (rw) */
    STM_UREG_32Bit IDR7:1;                    /**< \brief [7] Port 7  input data (rw) */
    STM_UREG_32Bit IDR8:1;                    /**< \brief [8] Port 8  input data (rw) */
    STM_UREG_32Bit IDR9:1;                    /**< \brief [9] Port 9  input data (rw) */
    STM_UREG_32Bit IDR10:1;                    /**< \brief [10] Port 10  input data bits (rw) */
    STM_UREG_32Bit IDR11:1;                    /**< \brief [11] Port 11  input data bits (rw) */
    STM_UREG_32Bit IDR12:1;                    /**< \brief [12] Port 12  input data bits (rw) */
    STM_UREG_32Bit IDR13:1;                    /**< \brief [13] Port 13  input data bits (rw) */
    STM_UREG_32Bit IDR14:1;                    /**< \brief [14] Port 14  input data bits (rw) */
    STM_UREG_32Bit IDR15:1;                    /**< \brief [15] Port 15  input data bits (rw) */
    STM_UREG_32Bit Reserved:16;               /**< \brief [16-31] Reserved bit (not accessable) */
}STM_GPIO_IDR_Bits;

typedef struct _STM_GPIO_ODR_Bits
{
    STM_UREG_32Bit ODR:1;                     /**< \brief [0] Port 0 output data bits (rw) */
    STM_UREG_32Bit ODR1:1;                    /**< \brief [1] Port 1 output data bits (rw) */
    STM_UREG_32Bit ODR2:1;                    /**< \brief [2] Port 2 output data bits (rw) */
    STM_UREG_32Bit ODR3:1;                    /**< \brief [3] Port 3 output data bits (rw) */
    STM_UREG_32Bit ODR4:1;                    /**< \brief [4] Port 4 output data bits (rw) */
    STM_UREG_32Bit ODR5:1;                    /**< \brief [5] Port 5 output data bits (rw) */
    STM_UREG_32Bit ODR6:1;                    /**< \brief [6] Port 6 output data bits (rw) */
    STM_UREG_32Bit ODR7:1;                    /**< \brief [7] Port 7 output data bits (rw) */
    STM_UREG_32Bit ODR8:1;                    /**< \brief [8] Port 8 output data bits (rw) */
    STM_UREG_32Bit ODR9:1;                    /**< \brief [9] Port 9 output data bits (rw) */
    STM_UREG_32Bit ODR10:1;                    /**< \brief [10] Port 10 output data bits (rw) */
    STM_UREG_32Bit ODR11:1;                    /**< \brief [11] Port 11 output data bits (rw) */
    STM_UREG_32Bit ODR12:1;                    /**< \brief [12] Port 12 output data bits (rw) */
    STM_UREG_32Bit ODR13:1;                    /**< \brief [13] Port 13 output data bits (rw) */
    STM_UREG_32Bit ODR14:1;                    /**< \brief [14] Port 14 output data bits (rw) */
    STM_UREG_32Bit ODR15:1;                    /**< \brief [15] Port 15 output data bits (rw) */
    STM_UREG_32Bit Reserved:16;               /**< \brief [16-31] Reserved bit (not accessable) */
}STM_GPIO_ODR_Bits;

typedef struct _STM_GPIO_BSRR_Bits
{
    STM_UREG_32Bit BS0:1;                     /**< \brief [0] Port 0 reset bits (rw) */
    STM_UREG_32Bit BS1:1;                     /**< \brief [1] Port 1 reset bits (rw) */
    STM_UREG_32Bit BS2:1;                     /**< \brief [2] Port 2 reset bits (rw) */
    STM_UREG_32Bit BS3:1;                     /**< \brief [3] Port 3 reset bits (rw) */
    STM_UREG_32Bit BS4:1;                     /**< \brief [4] Port 4 reset  bits (rw) */
    STM_UREG_32Bit BS5:1;                     /**< \brief [5] Port 5 reset bits (rw) */
    STM_UREG_32Bit BS6:1;                     /**< \brief [6] Port 6 reset bits (rw) */
    STM_UREG_32Bit BS7:1;                     /**< \brief [7] Port 7 reset bits (rw) */
    STM_UREG_32Bit BS8:1;                     /**< \brief [8] Port 8 reset bits (rw) */
    STM_UREG_32Bit BS9:1;                     /**< \brief [9] Port 9 reset bits (rw) */
    STM_UREG_32Bit BS10:1;                    /**< \brief [10] Port 10 reset bits (rw) */
    STM_UREG_32Bit BS11:1;                    /**< \brief [11] Port 11 reset bits (rw) */
    STM_UREG_32Bit BS12:1;                    /**< \brief [12] Port 12 reset bits (rw) */
    STM_UREG_32Bit BS13:1;                    /**< \brief [13] Port 13 reset bits (rw) */
    STM_UREG_32Bit BS14:1;                    /**< \brief [14] Port 14 reset bits (rw) */
    STM_UREG_32Bit BS15:1;                    /**< \brief [15] Port 15 reset bits (rw) */
    STM_UREG_32Bit BR0:1;                     /**< \brief [0] Port 0 set bits (rw) */
    STM_UREG_32Bit BR1:1;                     /**< \brief [1] Port 1 set bits (rw) */
    STM_UREG_32Bit BR2:1;                     /**< \brief [2] Port 2 set bits (rw) */
    STM_UREG_32Bit BR3:1;                     /**< \brief [3] Port 3 set bits (rw) */
    STM_UREG_32Bit BR4:1;                    /**< \brief [4] Port 4 set bits (rw) */
    STM_UREG_32Bit BR5:1;                    /**< \brief [5] Port 5 set bits (rw) */
    STM_UREG_32Bit BR6:1;                    /**< \brief [6] Port 6 set bits (rw) */
    STM_UREG_32Bit BR7:1;                    /**< \brief [7] Port 7 set bits (rw) */
    STM_UREG_32Bit BR8:1;                    /**< \brief [8] Port 8 set bits (rw) */
    STM_UREG_32Bit BR9:1;                    /**< \brief [9] Port 9 set bits (rw) */
    STM_UREG_32Bit BR10:1;                    /**< \brief [10] Port 10 set bits (rw) */
    STM_UREG_32Bit BR11:1;                    /**< \brief [1] Port 11 set bits (rw) */
    STM_UREG_32Bit BR12:1;                    /**< \brief [12] Port 12 set bits (rw) */
    STM_UREG_32Bit BR13:1;                    /**< \brief [13] Port 13 set bits (rw) */
    STM_UREG_32Bit BR14:1;                    /**< \brief [14] Port 14 set bits (rw) */
    STM_UREG_32Bit BR15:1;                    /**< \brief [15] Port 15 set bits (rw) */
}STM_GPIO_BSRR_Bits;

typedef struct _STM_GPIO_LCKR_Bits
{
    STM_UREG_32Bit LCK_K0:1;                     /**< \brief [0] Port 0 lock bits (rw) */
    STM_UREG_32Bit LCK_K1:1;                    /**< \brief [1] Port 1 lock bits (rw) */
    STM_UREG_32Bit LCK_K2:1;                    /**< \brief [2] Port 2 lock bits (rw) */
    STM_UREG_32Bit LCK_K3:1;                    /**< \brief [3] Port 3 lock bits (rw) */
    STM_UREG_32Bit LCK_K4:1;                    /**< \brief [4] Port 4 lock bits (rw) */
    STM_UREG_32Bit LCK_K5:1;                    /**< \brief [5] Port 5 lock bits (rw) */
    STM_UREG_32Bit LCK_K6:1;                    /**< \brief [6] Port 6 lock bits (rw) */
    STM_UREG_32Bit LCK_K7:1;                    /**< \brief [7] Port 7 lock bits (rw) */
    STM_UREG_32Bit LCK_K8:1;                    /**< \brief [8] Port 8 lock bits (rw) */
    STM_UREG_32Bit LCK_K9:1;                    /**< \brief [9] Port 9 lock bits (rw) */
    STM_UREG_32Bit LCK_K10:1;                    /**< \brief [10] Port 10 lock bits (rw) */
    STM_UREG_32Bit LCK_K11:1;                    /**< \brief [11] Port 11 lock bits (rw) */
    STM_UREG_32Bit LCK_K12:1;                    /**< \brief [12] Port 12 lock bits (rw) */
    STM_UREG_32Bit LCK_K13:1;                    /**< \brief [13] Port 13 lock bits (rw) */
    STM_UREG_32Bit LCK_K14:1;                    /**< \brief [14] Port 14 lock bits (rw) */
    STM_UREG_32Bit LCK_K15:1;                    /**< \brief [15] Port 15 lock bits (rw) */
    STM_UREG_32Bit LCK_K16:1;                     /**< \brief [16] (rw) */
    STM_UREG_32Bit Reserved:16;               /**< \brief [16-31] Reserved bit (not accessable) */    
}STM_GPIO_LCKR_Bits;

typedef struct _STM_GPIO_AFRL_Bits
{
    STM_UREG_32Bit AFRL0:4;                     /**< \brief[0:3] port 0 alternate function low configuration bits */
    STM_UREG_32Bit AFRL1:4;                     /**< \brief[4:7] port 1 alternate function low configuration bits */
    STM_UREG_32Bit AFRL2:4;                     /**< \brief[8:11] port 2 alternate function low configuration bits */
    STM_UREG_32Bit AFRL3:4;                     /**< \brief[12:15] port 3 alternate function low configuration bits */
    STM_UREG_32Bit AFRL4:4;                     /**< \brief[16:19] port 4 alternate function low configuration bits */
    STM_UREG_32Bit AFRL5:4;                     /**< \brief[20:23] port 5 alternate function low configuration bits */
    STM_UREG_32Bit AFRL6:4;                     /**< \brief[24:27] port 6 alternate function low configuration bits */
    STM_UREG_32Bit AFRL7:4;                     /**< \brief[28:31] port 7 alternate function low configuration bits */
}STM_GPIO_AFRL_Bits;

typedef struct _STM_GPIO_AFRH_Bits
{
    STM_UREG_32Bit AFRH0:4;                     /**< \brief[0:3] port 0 alternate function high configuration bits */
    STM_UREG_32Bit AFRH1:4;                     /**< \brief[4:7] port 1 alternate function high configuration bits */
    STM_UREG_32Bit AFRH2:4;                     /**< \brief[8:11] port 2 alternate function high configuration bits */
    STM_UREG_32Bit AFRH3:4;                     /**< \brief[12:15] port 3 alternate function high configuration bits */
    STM_UREG_32Bit AFRH4:4;                     /**< \brief[16:19] port 4 alternate function high configuration bits */
    STM_UREG_32Bit AFRH5:4;                     /**< \brief[20:23] port 5 alternate function high configuration bits */
    STM_UREG_32Bit AFRH6:4;                     /**< \brief[24:27] port 6 alternate function high configuration bits */
    STM_UREG_32Bit AFRH7:4;                     /**< \brief[28:31] port 7 alternate function high configuration bits */
}STM_GPIO_AFRH_Bits;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_MODER_Bits B;
}STM_GPIO_MODER;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_OTYPER_Bits B;
}STM_GPIO_OTYPER;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_OSPEEDR_Bits B;
}STM_GPIO_OSPEEDR;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_PUPDR_Bits B;
}STM_GPIO_PUPDR;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_IDR_Bits B;
}STM_GPIO_IDR;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_ODR_Bits B;
}STM_GPIO_ODR;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_BSRR_Bits B;
}STM_GPIO_BSRR;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_LCKR_Bits B;
}STM_GPIO_LCKR;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_AFRL_Bits B;
}STM_GPIO_AFRL;

typedef union 
{
    STM_UREG_32Bit U;
    STM_SREG_32Bit I;
    STM_GPIO_AFRH_Bits B;
}STM_GPIO_AFRH;


typedef volatile struct _STM_GPIO
{
    STM_GPIO_MODER MODER;
    STM_GPIO_OTYPER OTYPER;
    STM_GPIO_OSPEEDR OSPEEDR;
    STM_GPIO_PUPDR PUPDR;
    STM_GPIO_IDR IDR;
    STM_GPIO_ODR ODR;
    STM_GPIO_BSRR BSRR;
    STM_GPIO_LCKR LCKR;
    STM_GPIO_AFRL AFRL;
    STM_GPIO_AFRH AFRH;
}STM_GPIO;

#define MODULE_GPIOA                ((STM_GPIO*)0x40020000)
#define MODULE_GPIOB                ((STM_GPIO*)0x40020400)
#define MODULE_GPIOC                ((STM_GPIO*)0x40020800)
#define MODULE_GPIOD                ((STM_GPIO*)0x40020C00)
#define MODULE_GPIOE                ((STM_GPIO*)0x40021000)
#define MODULE_GPIOF                ((STM_GPIO*)0x40021400)
#define MODULE_GPIOG                ((STM_GPIO*)0x40021800)
#define MODULE_GPIOH                ((STM_GPIO*)0x40021C00)
#endif /* INC_STM_GPIO_REGDEF_H_ */
