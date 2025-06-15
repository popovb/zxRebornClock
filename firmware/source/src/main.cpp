//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

#include "Configurator.hpp"
#include "RedLed.hpp"
#include "BlueLed.hpp"
#include "Esp12f.hpp"
#include "EspCommand.hpp"
#include "core/Mcu.hpp"
#include "core/DelayerNop.hpp"
#include "debug.h"

int main() {
     using namespace gric;
     Mcu mcu;

     PrintConf pc(115200);
     mcu.init(pc);

     Configurator cnf(mcu);
     McuNetConfig mnc;
     cnf.init(mnc);

     Esp12f esp(mcu, mnc);
     EspReceiveBuffer erb;
     RedLed rl(mcu, mnc);
     BlueLed bl(mcu, mnc);
     rl.on();

     using Delayer = DelayerNop<4'000'000>;
     Delayer dl;

     dl.ms(500);
     rl.off();
     dl.ms(500);

     for (int i = 0; i < 3; i++) {
	  ///////////////////////////////////////////////
	  bl.on();
	  //dl.ms(1000);
	  esp.on();
	  dl.ms(300);
	  esp.uart_enable();

	  // esp.send(EspCommand::echo_off);
	  // dl.ms(100);

	  esp.send(EspCommand::at);
	  esp.receive(erb);
	  printf("%s\r\n", erb.buffer);

	  esp.send(EspCommand::uart_def);
	  esp.receive(erb);
	  printf("%s\r\n", erb.buffer);
	  
	  // esp.enable();
	  // dl.ms(5000);
	  // rl.on();

	  // //esp.receive(erb);

	  // //printf("%s\r\n", erb.buffer);

	  
	  // esp.send(EspCommand::at);
	  // rl.off();
	  // dl.ms(3000);
	  // rl.on();
	  // esp.receive(erb);

	  // printf("%s\r\n", erb.buffer);

	  // rl.off();
	  // esp.disable();
	  esp.uart_disable();
	  esp.off();
	  bl.off();
	  dl.ms(1000);
	  ///////////////////////////////////////////////
	  }
     while (true) { ; };
}
/* work
#include "Configurator.hpp"
#include "McuNetConfig.hpp"
#include "Anodes.hpp"
#include "Cathodes.hpp"
#include "Tubes.hpp"
#include "Rtc.hpp"
#include "Time.hpp"
#include "TimeChecker.hpp"
#include "LedBlockControl.hpp"
#include "KeyBlock.hpp"
#include "KeyBlockReactor.hpp"
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

     DisplayTime dt = tb.get_times();
     u16 iters = dt.iters_per_second();

     Rtc rtc(mcu, mnc);
     // TIME SET EXAMPLE
     // Time tn(18, 30);
     // rtc.set(tn);


     LedBlock lb(mcu, mnc);
     LedBlockControl lbc(dt.iter_time(), lb);

     KeyBlock kb(mcu, mnc);
     KeyBlockReactor kbr(lbc, rtc);

     // LedTaskTime ltt_r(2000, 2000);
     // LedTaskTime ltt_y(1000, 1000);
     // LedTaskTime ltt_g(500, 500);
     // LedTaskTime ltt_b(250, 250);

     // LedTask lt0(LedTaskMode::Unlimit, ltt_r, 0);
     // LedTask lt1(LedTaskMode::Unlimit, ltt_y, 0);
     // LedTask lt2(LedTaskMode::Unlimit, ltt_g, 0);
     // LedTask lt3(LedTaskMode::Unlimit, ltt_b, 0);

     // lbc.set(LedColor::Red, lt0);
     // lbc.set(LedColor::Yellow, lt1);
     // lbc.set(LedColor::Green, lt2);
     // lbc.set(LedColor::Blue, lt3);
     
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

	  for (u16 i = 0; i < iters; i++) {
	       tb.display(v);
	       auto kbe = kb.poll();
	       kbr.handle(kbe, v);
	       lbc.poll();
	  }
     }
     return 0;
}
*/
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

     DisplayTime dt = tb.get_times();
     u16 iters = dt.iters_per_second();

     Rtc rtc(mcu, mnc);
     // TIME SET EXAMPLE
     // Time tn(18, 30);
     // rtc.set(tn);


     LedBlock lb(mcu, mnc);
     LedBlockControl lbc(dt.iter_time(), lb);

     LedTaskTime ltt_r(2000, 2000);
     LedTaskTime ltt_y(1000, 1000);
     LedTaskTime ltt_g(500, 500);
     LedTaskTime ltt_b(250, 250);

     LedTask lt0(LedTaskMode::Unlimit, ltt_r, 0);
     LedTask lt1(LedTaskMode::Unlimit, ltt_y, 0);
     LedTask lt2(LedTaskMode::Unlimit, ltt_g, 0);
     LedTask lt3(LedTaskMode::Unlimit, ltt_b, 0);

     lbc.set(LedColor::Red, lt0);
     lbc.set(LedColor::Yellow, lt1);
     lbc.set(LedColor::Green, lt2);
     lbc.set(LedColor::Blue, lt3);

     
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

	  for (u16 i = 0; i < iters; i++) {
	       tb.display(v);
	       lbc.poll();
	  }
     }
     return 0;
}

#include "debug.h"
int main() {
     //
     // TODO : need to test
     //
     using namespace gric;
     Mcu mcu;

     PrintConf pc(115200);
     mcu.init(pc);

     PinTxConf ptx1(PortName::A, 2);
     PinRxConf prx1(PortName::A, 3);
     UartConf uc1(UartName::Uart2, 115200, ptx1, prx1);

     PinTxConf ptx2(PortName::B, 3);
     PinRxConf prx2(PortName::B, 4);
     UartConf uc2(UartName::Uart3, 115200, ptx2, prx2);

     mcu.init(uc1);
     mcu.init(uc2);

     Uart uart2 = mcu.get(UartName::Uart2);
     Uart uart3 = mcu.get(UartName::Uart3);

     uart2.enable();
     uart3.enable();

     u8 txb[11] = "0123456789";
     u8 rxb[11] = { 0, };
     for (u8 i = 0; i < 10; i++) {
	  uart2.send(txb[i]);
	  while (! uart2.tx_empty()) { ; }
	  while (! uart2.rx_not_empty()) { ; }
	  rxb[i] = uart3.receive();
     }

     printf("txb: %s \r\n", txb);
     printf("rxb: %s \r\n", rxb);
     while (true) { ; }
}
*/
