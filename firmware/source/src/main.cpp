// #include "ch32x035.h"
// #include "debug.h"
#include "core/Mcu.hpp"
#include "core/Delayer.hpp"

/*
void GPIO_Toggle_INIT(void) {
     GPIO_InitTypeDef GPIO_InitStructure = { 0 };

     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
     GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
     GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
     GPIO_Init(GPIOA, &GPIO_InitStructure);
}
*/

int main() {
     gric::Mcu mcu;
     gric::Delayer dl;
     /*
     u8 i = 0;

     * NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
     * SystemCoreClockUpdate();
     * Delay_Init();
     USART_Printf_Init(115200);
     printf("SystemClk:%d\r\n", SystemCoreClock);
     printf("ChipID:%08x\r\n", DBGMCU_GetCHIPID());
     printf("GPIO Toggle TEST\r\n");
     GPIO_Toggle_INIT();

     while (1) {
	  Delay_Ms(500);
	  GPIO_WriteBit(GPIOA,
			GPIO_Pin_0,
			(BitAction)((i == 0) ? (i = Bit_SET) : (i = Bit_RESET)));
     }
     */
}
