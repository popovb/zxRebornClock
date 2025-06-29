//
// Copyright (c) 2025 Boris Popov <popov@whitekefir.ru>
//

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
#include "Esp12f.hpp"
#include "InternetTime.hpp"
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

     Esp12f esp(mcu, mnc);
     InternetTime it(esp);
     it.test();

     LedBlock lb(mcu, mnc);
     LedBlockControl lbc(dt.iter_time(), lb);

     KeyBlock kb(mcu, mnc);
     KeyBlockReactor kbr(lbc, rtc, it);

     Time tm = rtc.pull();
     TimeChecker tc;
     tc.put(tm);
     u8 v[4];

     while (true) {
	  it.poll();
	  if (it.has_new_time()) {
	       Time tn(it.hour(),
		       it.minute(),
		       it.second());
	       rtc.set_w_second(tn);
	  }

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
