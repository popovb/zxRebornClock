#include "Configurator.hpp"
#include "McuNetConfig.hpp"
#include "core/Mcu.hpp"
// // #include "core/Delayer.hpp"
// #include "core/DelayerNop.hpp"

int main() {
     using namespace gric;
     Mcu mcu;

     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);
     //
     // TODO
     //
}
/*
int main() {
     using namespace gric;
     Mcu mcu;
     DelayerNop<3'000'000> dln;
     PortPinConf pp(PortName::A, 0);
     PinConf pc(PinDir::Out, PinMode::PushPull);
     mcu.init(pp, pc);
     auto pin = mcu.get(pp);

     bool v = pin.read();
     while (true) {
	  dln.ms(1000);
	  pin.write(!v);
	  v = pin.read();
     }
}

int main() {
     using namespace gric;
     Mcu mcu;
     Delayer dl;
     DelayerNop<3'000'000> dln;
     PrintConf pc(115200);
     mcu.init(pc);
     LedConf lc(PortName::A, 0);
     mcu.init(lc);
     auto led = mcu.get(lc);

     while (true) {
	  dln.ms(1000);
	  led.toggle();
     }
}
*/
