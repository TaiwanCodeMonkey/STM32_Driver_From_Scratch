#include "stm32f446re_fee_driver.h"

uint16_t Sample_Virtual_Address[SAMPLE_VIRADD_LEN] = {0x6666, 0x7777, 0x8888};
uint16_t Flash_Data = 0;
/***************************************************************
 * @fn                  - FEE_Init
 * 
 * @brief               - This functions Restore the pages to a known good state in case of page's status
 * corruption after a power loss.
 * @param[in]           - 
 * 
 * @return              -  Flash error code
 * 
 * @Note                -  none
 */
uint16_t FEE_Init(void)
{
    uint16_t Page0_Status = *((uint16_t*)PAGE0_BASE_ADDRESS);
    uint16_t Page1_Status = *((uint16_t*)PAGE1_BASE_ADDRESS);
    uint16_t Flash_Status;
    switch(Page0_Status) {
        case ERASED:
            if (Page1_Status == ERASED) {
                Flash_Status = FEE_Format();
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            else if (Page1_Status == RECEIVE_DATA) {
                Flash_Status = Sector_Erase(PAGE0_ID);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
                Flash_Status = Flash_Program(PROGRAM_HALFWORD, PAGE1_BASE_ADDRESS, VALID_PAGE);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            else {
                Flash_Status = Sector_Erase(PAGE0_ID);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            break;
        case RECEIVE_DATA:
            if (Page1_Status == ERASED) {
                Flash_Status = Sector_Erase(PAGE1_ID);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
                Flash_Status = Flash_Program(PROGRAM_HALFWORD, PAGE1_BASE_ADDRESS, VALID_PAGE);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            else if (Page1_Status == RECEIVE_DATA) {
                Flash_Status = FEE_Format();
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            else {
                Flash_Status = FEE_PageTransfer(0x5555, 123);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            break;
        case VALID_PAGE:
            if (Page1_Status == ERASED) {
                Flash_Status = Sector_Erase(PAGE1_ID);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
                Flash_Status = Flash_Program(PROGRAM_HALFWORD, PAGE1_BASE_ADDRESS, ERASED);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            else if (Page1_Status == RECEIVE_DATA) {
                Flash_Status = FEE_PageTransfer(0x5555, 123);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            else {
                Flash_Status = FEE_Format();
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
            break;
        default:
            Flash_Status = FEE_Format();
            if (Flash_Status != FLASH_OK)
                return Flash_Status;
            break;
    }
    return FLASH_OK;
}

/***************************************************************
 * @fn                  - FEE_FindValidPage
 * 
 * @brief               - 
 * 
 * @param operation     - Read or Write Operation  
 * 
 * @return              -  
 * 
 * @Note                -  none
 */
uint8_t FEE_FindValidPage(uint8_t operation)
{
    uint16_t Page0_Status = *(__vo uint16_t*)PAGE0_BASE_ADDRESS;
    uint16_t Page1_Status = *(__vo uint16_t*)PAGE1_BASE_ADDRESS;
    
    switch(operation) {

        case WRITE_OPERATION:
            if (Page0_Status == VALID_PAGE) {
                if (Page1_Status == RECEIVE_DATA)
                    return PAGE1_AVALIABLE;
                else 
                    return PAGE0_AVALIABLE;
            }
            else if (Page1_Status == VALID_PAGE) {
                if (Page0_Status == RECEIVE_DATA)
                    return PAGE0_AVALIABLE;
                else 
                    return PAGE1_AVALIABLE;
            }
            else
                return N0_VALID_PAGE;
        case READ_OPERATION:
            if (Page0_Status == VALID_PAGE)
                return PAGE0_AVALIABLE;
            else if (Page1_Status == VALID_PAGE)
                return PAGE1_AVALIABLE;
            else
                return N0_VALID_PAGE;
        default:
            return PAGE0_AVALIABLE;
    }

}

/***************************************************************
 * @fn                  - FEE_PageTransfer
 * 
 * @brief               - 
 * 
 * @param VirtualAddress- Data Index  
 * @param Data          - Latest Data 
 * @return              -  
 * 
 * @Note                -  none
 */
uint16_t FEE_PageTransfer(uint16_t VirtualAddress, uint16_t Data)
{
    uint32_t NewPageAddress;
    uint8_t ErasePageId;
    uint16_t Flash_Status;
    uint16_t Valid_Page = FEE_FindValidPage(READ_OPERATION);
    if (Valid_Page == PAGE1_AVALIABLE) {
        NewPageAddress = PAGE0_BASE_ADDRESS;
        ErasePageId = PAGE1_ID;
    }
    else if (Valid_Page == PAGE0_AVALIABLE) {
        NewPageAddress = PAGE1_BASE_ADDRESS;
        ErasePageId = PAGE0_ID;
    }
    else
        return N0_VALID_PAGE;
    Flash_Status = Flash_Program(PROGRAM_HALFWORD, NewPageAddress, RECEIVE_DATA);
    if (Flash_Status != FLASH_OK)
        return Flash_Status;
    Flash_Status = FEE_VerifyPageFullWriteVariable(VirtualAddress, Data);
    // uint16_t* Flash_Data;
    for (int idx = 0; idx < SAMPLE_VIRADD_LEN; idx ++) {
        if (Sample_Virtual_Address[idx] != VirtualAddress)
        {
            uint16_t Read_Status = FEE_ReadVariable(Sample_Virtual_Address[idx], &Flash_Data);
            if (!Read_Status)
            {
                Flash_Status = FEE_VerifyPageFullWriteVariable(Sample_Virtual_Address[idx], Flash_Data);
                if (Flash_Status != FLASH_OK)
                    return Flash_Status;
            }
        }
    }
    Flash_Status = Sector_Erase(ErasePageId);
    if (Flash_Status != FLASH_OK)
        return Flash_Status;
    Flash_Status = Flash_Program(PROGRAM_HALFWORD, NewPageAddress, VALID_PAGE);
    if (Flash_Status != FLASH_OK)
        return Flash_Status;
    return FLASH_OK;

}

uint16_t FEE_VerifyPageFullyErased(uint32_t Address)
{
    uint16_t ReadStatus = 1, AddressValue;
    while (Address <= PAGE0_END_ADDRESS)
    {
        uint16_t AddressValue = (*(__vo uint16_t*)Address);
        if (AddressValue != ERASED) {
            ReadStatus = 0;
            break;
        }
        Address += 4;
    }
    return ReadStatus;
}

uint16_t FEE_ReadVariable(uint16_t VirtualAddress, uint16_t* Data)
{
    uint16_t Valid_Page = FEE_FindValidPage(READ_OPERATION);
    uint32_t Page_Start_Address, Page_End_Address;
    uint16_t Read_Status = 1;
    if (Valid_Page == N0_VALID_PAGE)
        return N0_VALID_PAGE;
    Page_Start_Address = PAGE0_BASE_ADDRESS + (uint32_t)(Valid_Page * PAGE_SIZE) + 2;
    Page_End_Address = PAGE0_BASE_ADDRESS + (uint32_t)(1 + Valid_Page) * PAGE_SIZE - 2;
    for (uint32_t Address = Page_End_Address; Address > Page_Start_Address; Address -= 4)
    {
        uint16_t Variable_Virtual_Address = *(__vo uint16_t*)Address;
        if (Variable_Virtual_Address == VirtualAddress)
        {
            *Data = *(__vo uint16_t*)(Address - 2);
            Read_Status = 0;
            break;
        }
    }
    return Read_Status;
    
}

uint16_t FEE_VerifyPageFullWriteVariable(uint16_t VirtualAddress, uint16_t Data)
{
    uint8_t Page_Full_flg = 1;
    uint16_t Valid_Page = FEE_FindValidPage(WRITE_OPERATION);
    uint16_t Flash_Status;
    uint32_t Start_Address, End_Address;
    Start_Address = PAGE0_BASE_ADDRESS + (uint32_t)(Valid_Page) * PAGE_SIZE;
    End_Address = PAGE0_BASE_ADDRESS + (1 + Valid_Page) * PAGE_SIZE ;
    while (Start_Address < End_Address)
    {
        if (*((__vo uint32_t*)Start_Address) == 0xFFFFFFFF)
        {
            Page_Full_flg = 0;
            Flash_Status = Flash_Program(PROGRAM_HALFWORD, Start_Address, Data);
            if (Flash_Status != FLASH_OK)
                return Flash_Status;
            Flash_Status = Flash_Program(PROGRAM_HALFWORD, Start_Address + 2, VirtualAddress);
            if (Flash_Status != FLASH_OK)
                return Flash_Status;
            break;
        }
        Start_Address += 4;
    }
    if (Page_Full_flg == 1)
        return PAGE_FULL;
    return FLASH_OK;
}

uint16_t FEE_Format(void)
{
    uint16_t Flash_Status;
    Flash_Status = Sector_Erase(PAGE0_ID);
    if (Flash_Status != FLASH_OK)
        return Flash_Status;
    Flash_Status = Sector_Erase(PAGE1_ID);
    if (Flash_Status != FLASH_OK)
        return Flash_Status;

    Flash_Status = Flash_Program(PROGRAM_HALFWORD, PAGE0_BASE_ADDRESS, VALID_PAGE);
    if (Flash_Status != FLASH_OK)
        return Flash_Status;
    return FLASH_OK;
}

uint16_t FEE_WriteVariable(uint16_t VirtualAddress, uint16_t Data)
{
    uint16_t Flash_Status;
    Flash_Status = FEE_VerifyPageFullWriteVariable(VirtualAddress, Data);
    if (Flash_Status == PAGE_FULL)
    {
        Flash_Status = FEE_PageTransfer(VirtualAddress, Data);
        if (Flash_Status != FLASH_OK)
            return Flash_Status;
    }
    return FLASH_OK;

}

