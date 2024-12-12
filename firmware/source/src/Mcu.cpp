//
// Copyright (c) 2024 Boris Popov <popov@whitekefir.ru>
//

#include "Mcu.hpp"

#ifndef UNITTEST
#include "ch32x035.h"
#endif

gric::Mcu::Mcu() {
     init();
}

void gric::Mcu::init() const {
     nvic_config();
     clock_update();
}

void gric::Mcu::init(const PortPin& pp, const PinConf& pc) {
     if (pct.is_off(pp.port)) pct.on(pp.port);
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
#ifdef    UNITTEST

void gric::Mcu::nvic_config() const {
     return;
}

void gric::Mcu::clock_update() const {
     return;
}

#else //  UNITTEST

void gric::Mcu::nvic_config() const {
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
}

void gric::Mcu::clock_update() const {
     SystemCoreClockUpdate();
}

#endif // UNITTEST
