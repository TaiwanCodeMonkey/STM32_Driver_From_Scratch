# STM32F446RE_Driver_From_Scratch

## Boards available
* STM32F4
    * [STM32446RE](https://www.st.com/en/microcontrollers-microprocessors/stm32f446re.html)
    * [![N|Solid](https://www.st.com/bin/ecommerce/api/image.PF262063.en.feature-description-include-personalized-no-cpn-large.jpg)](https://www.st.com/en/evaluation-tools/nucleo-f446re.html)

In this repository which contain two folder, the folder structure as shown in below

* Src
    * All file in this folder is to test the function capability with STM32 CubeIDE
- Drivers
    * This folder contain the major drvier souces file and header file

## Cuurent  module
Below illustrate each driver caplbility
* GPIO
    - Enables or disables peripheral clock for the given GPIO port
    - Initializes the GPIO peripheral according to the specified parameters in the GPIO_Handle_t structure
    - Read/Write Pin
    - IRQ Configuration
    - External Interrupt
* Flash
    - Unlock the FLASH control register access
    - Program byte, halfword, word at a specified address
    - Erase at specified sector
    - Erase all sector
* CAN Bus (CAN Standard)
    - Initializes the CAN peripheral according to the specified parameters in the CAN_Handle_t structure
    - Configures the CAN reception filter according to the specified  parameters in the CAN_FilterCon structure
    - Add a message to the first free Tx mailbox and activate the corresponding transmission request
    - Get an CAN frame from the Rx FIFO mailbox
* Flash Emulate EEPROM
    - Simple wear leveling algorithm which can extend flash lifetime
* SPI
    - Initializes the SPI peripheral according to the specified parameters in the SPI_Handle structure
    - Enables or disables peripheral clock for the given SPI port
    - Transmit data
    - Receive data
    - Transmit and Receive data with interrupt
