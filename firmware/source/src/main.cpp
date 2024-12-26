#include "Configurator.hpp"
#include "McuNetConfig.hpp"
#include "Anodes.hpp"
#include "Cathodes.hpp"
#include "Tubes.hpp"
#include "Counter.hpp"
#include "DigitExtractor.hpp"
#include "core/Mcu.hpp"

int main() {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Anodes as(mcu, mnc);
     Cathodes cs(mcu, mnc);
     Tubes tb(as, cs);

     // TODO : Led led;

     Counter cn(989);
     DigitExtractor<4> de;
     u8 v[4];
     de.extract(v, cn.get());

     while (true) {
       for (u8 i = 0; i < 51; i++) tb.display(v);
	  cn.tick();
	  de.extract(v, cn.get());
	  // TODO : led.toggle();
     }
}

/*
// // #include "core/Delayer.hpp"
// #include "core/DelayerNop.hpp"

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
