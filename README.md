# STM32F446RE_Driver_From_Scratch

## Boards available
* STM32F4
    * [STM32446RE](https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html)


In this repository which contain two folder, the folder structure as shown in below

- Src
-- All file in this folder is to test the function capability with STM32 CubeIDE
- Drivers
-- This folder contain the major drvier souces file and header file

## Cuurent  module

* GPIO
    * Basic Init configuration
    * External Interupt
* Flash
    * Program Flash(Bytes, Half Word, Word)
    * Erase Sector
* CAN Bus (CAN Standard)
    * Init Configuration
    * Fileter Configuration
    * Send Message
    * Reveice Message
* Flash Emulate EEPROM
    * Simple wear leveling algorithm
* SPI
    * Init Configuration
    * Send data
    * Receive data
    * Interupt
