#include "core/Mcu.hpp"
#include "core/Delayer.hpp"

int main() {
     using namespace gric;
     Mcu mcu;
     Delayer dl;
     PrintConf pc(115200);
     mcu.init(pc);
     // PortPin ppp(PortName::A, 0);
     // PinConf ppc(PinDir::Out, PinMode::PushPull);
     // mcu.init(ppp, ppc);
     Led led(PortName::A, 0);
     mcu.init(led);


     /*
     u8 i = 0;

     * NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
     * SystemCoreClockUpdate();
     * Delay_Init();
     * USART_Printf_Init(115200);
     * printf("SystemClk:%d\r\n", SystemCoreClock);
     * printf("ChipID:%08x\r\n", DBGMCU_GetCHIPID());
     * printf("GPIO Toggle TEST\r\n");
     * GPIO_Toggle_INIT();

     while (1) {
	  Delay_Ms(500);
	  GPIO_WriteBit(GPIOA,
			GPIO_Pin_0,
			(BitAction)((i == 0) ? (i = Bit_SET) : (i = Bit_RESET)));
     }
     */
}
