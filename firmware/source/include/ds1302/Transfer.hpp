//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Command.hpp"
#include "Data.hpp"

#ifndef _DS1302_TRANSFER_HPP_
#define _DS1302_TRANSFER_HPP_

namespace ds1302 {
////////////////////////////////////////////////////////////////
     template<class PIN,
	      class DELAY>
     class Transfer {

     public:
	  Transfer(PIN&, PIN&, PIN&, DELAY&);

	  void read(const Command&, Data&) const;
	  void write(const Command&, const Data&) const;

     private:
	  PIN& ce;
	  PIN& sclk;
	  PIN& io;
	  DELAY& delay;

     private:
	  void write_byte(u8) const;
	  void write_bit(bool) const;
	  u8 read_bit(u8) const;
	  u8 read_byte() const;
     };
}
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
template<class C, class D>
ds1302::Transfer<C, D>::
Transfer(C& c, C& s, C& i, D& d):
     ce(c),
     sclk(s),
     io(i),
     delay(d)
{
     return;
}

template<class C, class D>
void ds1302::Transfer<C, D>::
read(const Command& c, Data& d) const {
     sclk.write(false);

     ce.write(true);
     delay.us(5);

     io.init_out();
     write_byte(c.get_byte());

     io.init_in();
     u8 bb = read_byte();
     d.set_byte(bb);

     ce.write(false);
}

template<class C, class D>
void ds1302::Transfer<C, D>::
write(const Command& c, const Data& d) const {
     sclk.write(false);

     ce.write(true);
     delay.us(5);

     io.init_out();

     write_byte(c.get_byte());
     write_byte(d.get_byte());

     ce.write(false);
}

template<class C, class D>
void ds1302::Transfer<C, D>::write_bit(bool v) const {
     io.write(v);
     sclk.write(false);
     delay.us(1);
     sclk.write(true);
     delay.us(1);
}

template<class C, class D>
ds1302::u8 ds1302::Transfer<C, D>::read_bit(u8 n) const {
     sclk.write(false);
     delay.us(1);
     bool b = io.read();
     u8 bb = b << n;
     if (n == 7) return bb;
     sclk.write(true);
     delay.us(1);
     return bb;
}

template<class C, class D>
void ds1302::Transfer<C, D>::write_byte(u8 n) const {
     write_bit(n & 0x01);
     for (u8 i = 0; i < 7; i++) {
	  n = n >> 1;
	  write_bit(n & 0x01);
     }
}

template<class C, class D>
ds1302::u8 ds1302::Transfer<C, D>::read_byte() const {
     u8 result = 0;
     for (u8 i = 0; i < 8; i++) result |= read_bit(i);
     return result;
}
////////////////////////////////////////////////////////////////
#endif // _DS1302_TRANSFER_HPP_
