#include "core/Mcu.hpp"
#include "core/Delayer.hpp"

int main() {
     using namespace gric;
     Mcu mcu;
     Delayer dl;
     PrintConf pc(115200);
     mcu.init(pc);
     LedConf lc(PortName::A, 0);
     mcu.init(lc);
     auto led = mcu.get(lc);

     while (true) {
	  dl.ms(500);
	  led.toggle();
     }
}
