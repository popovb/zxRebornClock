//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Gpio.hpp"

void gric::Gpio::init(const PortPin& pp, const PinConf& pc) {
     //
     // TODO
     //
}
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
