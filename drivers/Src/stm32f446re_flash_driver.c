#include <stm32f446re_flash_driver.h>

/***************************************************************
 * @fn                  - Unlock_Flash
 * 
 * @brief               - 
 * 
 * @param[in]           - None
 * 
 * @return              -  none
 * 
 */
void Unlock_Flash()
{
    WRITE_REG(FLASH -> FLASH_KEYR, KEY1);
    WRITE_REG(FLASH -> FLASH_KEYR, KEY2);
}

/***************************************************************
 * @fn                  - Lock_Flash
 * 
 * @brief               - 
 * 
 * @param[in]           - None
 * 
 * @return              -  none
 * 
 */
void Lock_Flash()
{
    FLASH -> FLASH_CR |= FLASH_CR_LOCK;
}

/***************************************************************
 * @fn                  - Flash_Busy
 * 
 * @brief               - 
 * 
 * @param[in]           - None
 * 
 * @return              -  none
 * 
 */
int Flash_Busy()
{   
    uint32_t temp = FLASH -> FLASH_SR;
    if ((FLASH -> FLASH_SR & FLASH_SR_BSY_Msk) >> FLASH_SR_BSY_Pos)
        return 1;
    return 0;
}

/***************************************************************
 * @fn                  - Sector_Erase
 * 
 * @brief               - 
 * 
 * @param[in]           - which sector that need to erase
 * 
 * @return              -  none
 * 
 */
FLASH_Status Sector_Erase(uint8_t Sector_Idx)
{
    // 1. Unclock Flash
    // 2 Wait, untile flash operation is not busy
    FLASH_Status status = Wait_Last_Operation();
    if (status == FLASH_OK)
    {
        // 3 Set SER bit
        FLASH -> FLASH_CR |= FLASH_CR_SER;
        // 4 select which Sector to erase
        CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_SNB);
        FLASH -> FLASH_CR |= (Sector_Idx << FLASH_CR_SNB_Pos);
        // 5 Set the start bit
        FLASH -> FLASH_CR |= FLASH_CR_START;
        FLASH_Status status = Wait_Last_Operation();
        CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_SER_POS);
    }
    return status;
}

FLASH_Status Mass_Erase()
{
    // 1 Wait, untile flash operation is not busy
    FLASH_Status status = Wait_Last_Operation();
    if (status == FLASH_OK)
    {
        // 2. Set MER bit
        FLASH -> FLASH_CR |= FLASH_CR_MER;
        // 3.Set the start bit
        FLASH -> FLASH_CR |= FLASH_CR_START;
        FLASH_Status status = Wait_Last_Operation();
        CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_MER_Pos);
        Lock_Flash();
    }
    return status;
}

FLASH_Status Wait_Last_Operation()
{
    uint32_t counter = 0;
    while (Flash_Busy() != FREE) {
        counter += 1;
        if (counter >= TIMEOUT)
            return FLASH_TIMEOUT;
    }
    return FLASH_OK;
}
FLASH_Status Flash_Program(uint32_t TypeProgram, uint32_t Address, uint32_t Data)
{
    // Unlock_Flash();
    FLASH_Status status = Wait_Last_Operation();
    if (status == FLASH_OK)
    {
        if (TypeProgram == PROGRAM_BYTE)
            Program_Byte(Address, (uint8_t)Data);
        else if (TypeProgram == PROGRAM_HALFWORD)
            Program_HalfWord(Address, (uint16_t)Data);
        else
            Program_Word(Address, (uint32_t)Data);
    }
    status = Wait_Last_Operation();
    CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_PG_Pos);
    return status;

}
void Program_Byte(uint32_t Address, uint8_t Data)
{
    CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_PSIZE);
    FLASH -> FLASH_CR |= (FLASH_PSIZE_BYTE << FLASH_CR_PSIZE_Pos);
    FLASH -> FLASH_CR |= FLASH_CR_PG;
    *(__vo uint8_t*)Address = Data;
}
// FLASH_Status Program_Byte(uint32_t Address, uint8_t Data)
// {
//     FLASH_Status status;
//     status = Wait_Last_Operation();
//     if (status == FLASH_OK)
//     {
//         CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_PSIZE);
//         FLASH -> FLASH_CR |= (FLASH_PSIZE_BYTE << FLASH_CR_PSIZE_Pos);
//         FLASH -> FLASH_CR |= FLASH_CR_PG;
//         *(__vo uint8_t*)Address = Data;
//         status = Wait_Last_Operation();
//         CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_PG);
//     }
//     return status;
// }

void Program_HalfWord(uint32_t Address, uint16_t Data)
{
    CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_PSIZE);
    FLASH -> FLASH_CR |= (FLASH_PSIZE_HALF_WORD << FLASH_CR_PSIZE_Pos);
    FLASH -> FLASH_CR |= FLASH_CR_PG;
    *(__vo uint16_t*) Address = Data;
}


void Program_Word(uint32_t Address, uint32_t Data)
{
    CLEAR_BIT(FLASH -> FLASH_CR, FLASH_CR_PSIZE);
    FLASH -> FLASH_CR |= (FLASH_PSIZE_WORD << FLASH_CR_PSIZE_Pos);
    FLASH -> FLASH_CR |= FLASH_CR_PG;
    *(__vo uint32_t*) Address = Data;
}
