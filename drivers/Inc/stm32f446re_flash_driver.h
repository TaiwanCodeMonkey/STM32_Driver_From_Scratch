#ifndef INC_STM32F446RE_FLASH_DRIVER_H_
#define INC_STM32F446RE_FLASH_DRIVER_H_
#include "STM_Flash_reg.h"
#include <stdint.h>
/*
* Start and End addresses of each Flash Sector
*/
#define FLASH_SECTOR_ONE_START_ADDR               (uint32_t)0x08004000
#define FLASH_SECTOR_ONE_END_ADDR                 (uint32_t)0x08007FFF

#define FLASH_SECTOR_TWO_START_ADDR               (uint32_t)0x08008000
#define FLASH_SECTOR_TWO_END_ADDR                 (uint32_t)0x0800BFFF

#define FLASH_SECTOR_THREE_START_ADDR             (uint32_t)0x0800C000
#define FLASH_SECTOR_THREE_END_ADDR               (uint32_t)0x0800FFFF

#define FLASH_SECTOR_FOUR_START_ADDR              (uint32_t)0x08010000
#define FLASH_SECTOR_FOUR_END_ADDR                (uint32_t)0x0801FFFF

#define FLASH_SECTOR_FIVE_START_ADDR              (uint32_t)0x08020000
#define FLASH_SECTOR_FIVE_END_ADDR                (uint32_t)0x0803FFFF

#define FLASH_SECTOR_SIX_START_ADDR              (uint32_t)0x08040000
#define FLASH_SECTOR_SIX_END_ADDR                (uint32_t)0x0805FFFF

#define FLASH_SECTOR_SEVEN_START_ADDR              (uint32_t)0x08060000
#define FLASH_SECTOR_SEVEN_END_ADDR                (uint32_t)0x0807FFFF

#define KEY1              ((uint32_t)0x45670123)
#define KEY2              ((uint32_t)0xCDEF89AB)
#define OPTKEY1           ((uint32_t)0x08192A3B)
#define OPTKEY2           ((uint32_t)0x4C5D6E7F)
#define TIMEOUT           50000
#define FlASH_TYPEPROGRAM_BYTE               0U
#define FLASH_TYPEPROGRAM_HALFWORD           1U
#define FLASH_TYPEPROGRAM_WORD               2U
#define FLASH_TYPEPROGRAM_DOUBLEWORD         3U
#define FLASH_PSIZE_BYTE                     0U
#define FLASH_PSIZE_HALF_WORD                1U
#define FLASH_PSIZE_WORD                     2U
#define FLASH_PSIZE_DOUBLE_WORD              3U             

#define PROGRAM_BYTE                         0U
#define PROGRAM_HALFWORD                     1U
#define PROGRAM_WORD                         2U
#define PROGRAM_DOUBLEWORD                   3U
/**
 * @brief FLASH Status structures definitions
 * 
 */
typedef enum
{
  FLASH_OK = 0x00U,
  FLASH_ERROR = 0x01U,
  FLASH_BUSY = 0x02U,
  FLASH_TIMEOUT = 0x03U
}FLASH_Status;

void Unlock_Flash(void);
void Lock_Flash(void);
int Flash_Busy(void);
FLASH_Status Sector_Erase(uint8_t Sector_Idx);
FLASH_Status Mass_Erase(void);
FLASH_Status Flash_Program (uint32_t TypeProgram, uint32_t Address, uint32_t Data);
void Program_Byte(uint32_t Address, uint8_t Data);
void Program_HalfWord(uint32_t Address, uint16_t Data);
void Program_Word(uint32_t Address, uint32_t Data);
void Program_DoubleWord(uint32_t Address, uint64_t Data);
FLASH_Status Wait_Last_Operation(void);
typedef struct
{
  float K_Motor_IdKi;
  float K_Motor_IdKp;
  float K_Motor_IqKi;
  float K_Motor_IqKp;
  float K_Motor_Flux;
  float K_HVDC_Offset;
  uint32_t K_Motor_IMax;
  uint32_t K_Motor_IStall;
  uint32_t K_Motor_torqueRate_Nmps;
  uint32_t K_Motor_OverSpd_Trg;
  uint32_t K_Resolver_Offset;
  uint32_t K_Resolver_Resolution;
} Bus_EEPROM_Data;
#endif /* INC_STM32F446RE_FLASH_DRIVER_H_ */
