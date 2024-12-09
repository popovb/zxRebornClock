#include "ch32x035.h"

#define SYSCLK_FREQ_48MHz_HSI  HSI_VALUE

uint32_t SystemCoreClock = HSI_VALUE;

__I uint8_t AHBPrescTable[16] = {
     1, 2, 3, 4, 5, 6, 7, 8,
     1, 2, 3, 4, 5, 6, 7, 8 };

static void SetSysClockTo48_HSI();

void SystemInit() {
     RCC->CTLR |= (uint32_t)0x00000001;
     RCC->CFGR0 |= (uint32_t)0x00000050;
     RCC->CFGR0 &= (uint32_t)0xF8FFFF5F;
     SetSysClockTo48_HSI();
}

void SystemCoreClockUpdate() {
     uint32_t tmp = 0;

     SystemCoreClock = HSI_VALUE;
     tmp = AHBPrescTable[((RCC->CFGR0 & RCC_HPRE) >> 4)];

     if(((RCC->CFGR0 & RCC_HPRE) >> 4) < 8) {
	  SystemCoreClock /= tmp;

     } else {
	  SystemCoreClock >>= tmp;
     }
}

static void SetSysClockTo48_HSI() {
     /* Flash 2 wait state */
     FLASH->ACTLR &= (uint32_t)((uint32_t)~FLASH_ACTLR_LATENCY);
     FLASH->ACTLR |= (uint32_t)FLASH_ACTLR_LATENCY_2;

     /* HCLK = SYSCLK = APB1 */
     RCC->CFGR0 &= (uint32_t)0xFFFFFF0F;
     RCC->CFGR0 |= (uint32_t)RCC_HPRE_DIV1;
}
