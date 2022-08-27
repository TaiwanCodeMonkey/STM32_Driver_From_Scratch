#include "stm32f446re.h"
#include <stdlib.h>
#include <stdio.h>
 int main(void)
{
	Bus_EEPROM_Data eeprom;
    Bus_EEPROM_Data read_flash;
    eeprom.K_Motor_IdKi = 8.56f;
    eeprom.K_Motor_IdKp = 4.25f;
    eeprom.K_Motor_IqKi = 2.24f;
    eeprom.K_Motor_IqKp = 2.25f;
    eeprom.K_Motor_Flux = 4.231f;
    eeprom.K_HVDC_Offset = 3.21f;
    eeprom.K_Motor_IMax = 23;
    eeprom.K_Motor_IStall = 25;
    eeprom.K_Motor_torqueRate_Nmps = 26;
    eeprom.K_Motor_OverSpd_Trg = 27;
    eeprom.K_Resolver_Offset = 28;
    eeprom.K_Resolver_Resolution = 29;
    uint8_t* eeprom_ptr = &eeprom;
    uint32_t* read_eeprom_ptr = &read_flash;
    uint32_t* flash_add_ptr = (uint32_t*)FLASH_SECTOR_THREE_START_ADDR;
    uint32_t flash_add = (uint32_t)FLASH_SECTOR_FOUR_START_ADDR;
    Unlock_Flash();
//	Sector_Erase(4);
    for (int i = 0; i <= sizeof(Bus_EEPROM_Data); i += 1, flash_add += 1, eeprom_ptr ++)
//        Program_Byte(flash_add, *eeprom_ptr);
         Flash_Program(PROGRAM_BYTE, flash_add, *eeprom_ptr);
        // FLASH_(flash_add, *eeprom_ptr);

    for (int i = 0; i <= sizeof(Bus_EEPROM_Data); i+= 4, read_eeprom_ptr ++, flash_add_ptr ++)
        *read_eeprom_ptr = *flash_add_ptr;
//    Sector_Errase(3);
    eeprom.K_Resolver_Resolution = 29;
    return 1;
}
