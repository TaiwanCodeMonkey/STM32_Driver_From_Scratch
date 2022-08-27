#include "stm32f446re.h"
uint16_t Example_Virtual_Address[3] = {0x6666, 0x7777, 0x8888};
int main()
{
	Unlock_Flash();
	uint16_t Flash_Status;
//	Flash_Status = Sector_Erase(2);
//	Flash_Status = FEE_Init();
	for (int i = 0; i < 1333; i++)
	{
		for (int j = 0; j < 3; j++) {
			uint16_t rand_num = rand();
			Flash_Status = FEE_WriteVariable(Example_Virtual_Address[j], rand_num);
		}
	}
	while (1);
	return 1;
}

