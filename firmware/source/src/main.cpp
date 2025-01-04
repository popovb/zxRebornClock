#include "Configurator.hpp"
#include "McuNetConfig.hpp"
#include "Anodes.hpp"
#include "Cathodes.hpp"
#include "Tubes.hpp"
#include "Rtc.hpp"
#include "Time.hpp"
#include "TimeChecker.hpp"
#include "core/Mcu.hpp"
/*
int main() {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Anodes as(mcu, mnc);
     Cathodes cs(mcu, mnc);
     Tubes tb(as, cs);

     // const auto& ppc = mnc.get(McuNet::WL);
     // LedConf lc(ppc.port, ppc.pin);
     // Led led = mcu.get(lc);

     Rtc rtc(mcu, mnc);
     Time tm = rtc.pull();
     TimeChecker tc;
     tc.put(tm);
     u8 v[4];
     while (true) {
	  tm = rtc.pull();
	  tc.put(tm);
	  if (tc)
	       tc.fill(v);
	  else
	       tc.fill_prev(v);

	  for (u8 i = 0; i < 51; i++) tb.display(v);
	  // led.toggle();
     }
     return 0;
}
*/
#include "DigitExtractor.hpp"
#include "Counter.hpp"
int main() {
     using namespace gric;
     Mcu mcu;
     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Anodes as(mcu, mnc);
     Cathodes cs(mcu, mnc);
     Tubes tb(as, cs);

     const auto& ppc = mnc.get(McuNet::WL);
     LedConf lc(ppc.port, ppc.pin);
     Led led = mcu.get(lc);

     Counter cnt(989);
     DigitExtractor<4> de;
     u8 v[4];
     de.extract(v, cnt.get());

     while (true) {
       for (u8 i = 0; i < 51; i++) tb.display(v);
       cnt.tick();
       de.extract(v, cnt.get());
       led.toggle();
     }
     return 0;
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

#include "core/DelayerNop.hpp"

int main() {
     using namespace gric;
     Mcu mcu;
     //Delayer dl;
     DelayerNop<4'000'000> dln;
     //PrintConf pc(115200);
     //mcu.init(pc);
     LedConf lc(PortName::A, 0);
     mcu.init(lc);
     auto led = mcu.get(lc);

     while (true) {
	  dln.ms(1000);
	  led.toggle();
     }
}
*/
