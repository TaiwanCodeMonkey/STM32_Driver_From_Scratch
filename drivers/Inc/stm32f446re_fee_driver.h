#ifndef INC_STM32F446RE_FEE_DRIVER_H_
#define INC_STM32F446RE_FEE_DRIVER_H_
#include "stm32f446re_flash_driver.h"


/* Define the size of the sectors to be used */
#define PAGE_SIZE                             (uint32_t)0x4000

/* EEPROM start address in Flash */
#define EEPROM_START_ADDRESS                  FLASH_SECTOR_TWO_START_ADDR /* EEPRON emulation start address:*/        
                                                                          /*from sector2 : after 16KByte of used FLASH memory */

/* Pages 0 and 1 base and end addresses */
#define PAGE0_BASE_ADDRESS                    ((uint32_t)(EEPROM_START_ADDRESS + 0x0000))
#define PAGE0_END_ADDRESS                     ((uint32_t)EEPROM_START_ADDRESS + (PAGE_SIZE - 1))
#define PAGE0_ID                              2

#define PAGE1_BASE_ADDRESS                    ((uint32_t)(EEPROM_START_ADDRESS + 0x4000))
#define PAGE1_END_ADDRESS                     ((uint32_t)(EEPROM_START_ADDRESS + (2 * PAGE_SIZE - 1)))
#define PAGE1_ID                              3
/* Page status definition */
#define ERASED                                ((uint16_t)0xFFFF)
#define RECEIVE_DATA                          ((uint16_t)0xEEEE)
#define VALID_PAGE                            ((uint16_t)0x0000)

#define WRITE_OPERATION                       1
#define READ_OPERATION                        0
#define PAGE0_AVALIABLE                       0
#define PAGE1_AVALIABLE                       1
#define N0_VALID_PAGE                         2
#define PAGE_FULL                             (uint16_t)0x20
#define SAMPLE_VIRADD_LEN                     3
// Function Prototype
uint16_t FEE_Init(void);
uint8_t FEE_FindValidPage(uint8_t operation);
uint16_t FEE_PageTransfer(uint16_t VirtialAdd_Arr, uint16_t Data);
uint16_t FEE_VerifyPageFullyErased(uint32_t Address);
uint16_t FEE_ReadVariable(uint16_t VirtualAddress, uint16_t* Data);
uint16_t FEE_VerifyPageFullWriteVariable(uint16_t VirtualAddress, uint16_t Data);
uint16_t FEE_Format();
#endif /* INC_STM32F446RE_FEE_DRIVER_H_ */
