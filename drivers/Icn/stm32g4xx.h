/*
 * stm32g4xx.h
 *
 *  Created on: May 2, 2020
 *      Author: AJAY
 */

#ifndef ICN_STM32G4XX_H_
#define ICN_STM32G4XX_H_

#include "stdint.h"

/*
 * Address of Flash, SRAM and ROM
 *
 */

#define FLASH_BASEADDR								0x08000000U
#define SRAM1_BASEADDR								0x20000000U
#define SRAM2_BASEADDR								SRAM1_BASEADDR + 0x00014000U
#define ROM_BASEADDR								0x1FFF0000
#define SRAM										SRAM1_BASEADDR

/*
 * Base Address of APB1, APB2, AHB1, AHB2 Buses
 *
 */

#define APB1PERIPH_BASE								0x40000000U
#define APB2PERIPH_BASE								0x40010000U
#define AHB1PERIPH_BASE								0x40020000U
#define AHB2PERIPH_BASE								0x48000000U


/*
 * Base Address of peripherals hanging on AHB1 Bus
 *
 */
#define RCC_BASEADDRESS								(AHB1PERIPH_BASE+ 0x1000)





/*
 * Base Address of peripherals hanging on AHB2 Bus
 *
 */


#define GPIOA_BASEADDR								(AHB2PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR								(AHB2PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR								(AHB2PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR								(AHB2PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR								(AHB2PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR								(AHB2PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR								(AHB2PERIPH_BASE + 0x1800)


/************************** peripheral register definition structures *********************************/

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
	volatile uint32_t BRR;

}GPIO_RegDef_t;


typedef struct
{
  volatile uint32_t CR;          /*!< RCC clock control register,                                              Address offset: 0x00 */
  volatile uint32_t ICSCR;       /*!< RCC internal clock sources calibration register,                         Address offset: 0x04 */
  volatile uint32_t CFGR;        /*!< RCC clock configuration register,                                        Address offset: 0x08 */
  volatile uint32_t PLLCFGR;     /*!< RCC system PLL configuration register,                                   Address offset: 0x0C */
  uint32_t      RESERVED0;   /*!< Reserved,                                                                Address offset: 0x10 */
  uint32_t      RESERVED1;   /*!< Reserved,                                                                Address offset: 0x14 */
  volatile uint32_t CIER;        /*!< RCC clock interrupt enable register,                                     Address offset: 0x18 */
  volatile uint32_t CIFR;        /*!< RCC clock interrupt flag register,                                       Address offset: 0x1C */
  volatile uint32_t CICR;        /*!< RCC clock interrupt clear register,                                      Address offset: 0x20 */
  uint32_t      RESERVED2;   /*!< Reserved,                                                                Address offset: 0x24 */
  volatile uint32_t AHB1RSTR;    /*!< RCC AHB1 peripheral reset register,                                      Address offset: 0x28 */
  volatile uint32_t AHB2RSTR;    /*!< RCC AHB2 peripheral reset register,                                      Address offset: 0x2C */
  volatile uint32_t AHB3RSTR;    /*!< RCC AHB3 peripheral reset register,                                      Address offset: 0x30 */
  uint32_t      RESERVED3;   /*!< Reserved,                                                                Address offset: 0x34 */
  volatile uint32_t APB1RSTR1;   /*!< RCC APB1 peripheral reset register 1,                                    Address offset: 0x38 */
  volatile uint32_t APB1RSTR2;   /*!< RCC APB1 peripheral reset register 2,                                    Address offset: 0x3C */
  volatile uint32_t APB2RSTR;    /*!< RCC APB2 peripheral reset register,                                      Address offset: 0x40 */
  uint32_t      RESERVED4;   /*!< Reserved,                                                                Address offset: 0x44 */
  volatile uint32_t AHB1ENR;     /*!< RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
  volatile uint32_t AHB2ENR;     /*!< RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
  volatile uint32_t AHB3ENR;     /*!< RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
  uint32_t      RESERVED5;   /*!< Reserved,                                                                Address offset: 0x54 */
  volatile uint32_t APB1ENR1;    /*!< RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */
  volatile uint32_t APB1ENR2;    /*!< RCC APB1 peripheral clocks enable register 2,                            Address offset: 0x5C */
  volatile uint32_t APB2ENR;     /*!< RCC APB2 peripheral clocks enable register,                              Address offset: 0x60 */
  uint32_t      RESERVED6;   /*!< Reserved,                                                                Address offset: 0x64 */
  volatile uint32_t AHB1SMENR;   /*!< RCC AHB1 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x68 */
  volatile uint32_t AHB2SMENR;   /*!< RCC AHB2 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x6C */
  volatile uint32_t AHB3SMENR;   /*!< RCC AHB3 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x70 */
  uint32_t      RESERVED7;   /*!< Reserved,                                                                Address offset: 0x74 */
  volatile uint32_t APB1SMENR1;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1, Address offset: 0x78 */
  volatile uint32_t APB1SMENR2;  /*!< RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2, Address offset: 0x7C */
  volatile uint32_t APB2SMENR;   /*!< RCC APB2 peripheral clocks enable in sleep mode and stop modes register, Address offset: 0x80 */
  uint32_t      RESERVED8;   /*!< Reserved,                                                                Address offset: 0x84 */
  volatile uint32_t CCIPR;       /*!< RCC peripherals independent clock configuration register,                Address offset: 0x88 */
  uint32_t      RESERVED9;   /*!< Reserved,                                                                Address offset: 0x8C */
  volatile uint32_t BDCR;        /*!< RCC backup domain control register,                                      Address offset: 0x90 */
  volatile uint32_t CSR;         /*!< RCC clock control & status register,                                     Address offset: 0x94 */
  volatile uint32_t CRRCR;       /*!< RCC clock recovery RC register,                                          Address offset: 0x98 */
  volatile uint32_t CCIPR2;      /*!< RCC peripherals independent clock configuration register 2,              Address offset: 0x9C */
} RCC_RegDef;


/*
 * peripheral definitions (peripheral addresses type casted to GPIO RegDef)
 *
 */
#define GPIOA 										((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB 										((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC 										((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD 										((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE 										((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF 										((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG 										((GPIO_RegDef_t *)GPIOG_BASEADDR)

#define RCC 										((RCC_RegDef *)RCC_BASEADDRESS)

/*
 * Clock enable for GPIOx peripherals
 */

#define RCC_GPIOA_CLK_ENABLE()						(RCC->AHB2ENR |= 1 << 0)
#define RCC_GPIOB_CLK_ENABLE()						(RCC->AHB2ENR |= 1 << 1)
#define RCC_GPIOC_CLK_ENABLE()						(RCC->AHB2ENR |= 1 << 2)
#define RCC_GPIOD_CLK_ENABLE()						(RCC->AHB2ENR |= 1 << 3)
#define RCC_GPIOE_CLK_ENABLE()						(RCC->AHB2ENR |= 1 << 4)
#define RCC_GPIOF_CLK_ENABLE()						(RCC->AHB2ENR |= 1 << 5)
#define RCC_GPIOG_CLK_ENABLE()						(RCC->AHB2ENR |= 1 << 6)

/*
 * Clock disable for GPIOx peripherals
 */

#define RCC_GPIOA_CLK_DISABLE()						(RCC->AHB2RSTR |= 1 << 0)
#define RCC_GPIOB_CLK_DISABLE()						(RCC->AHB2RSTR |= 1 << 1)
#define RCC_GPIOC_CLK_DISABLE()						(RCC->AHB2RSTR |= 1 << 2)
#define RCC_GPIOD_CLK_DISABLE()						(RCC->AHB2RSTR |= 1 << 3)
#define RCC_GPIOE_CLK_DISABLE()						(RCC->AHB2RSTR |= 1 << 4)
#define RCC_GPIOF_CLK_DISABLE()						(RCC->AHB2RSTR |= 1 << 5)
#define RCC_GPIOG_CLK_DISABLE()						(RCC->AHB2RSTR |= 1 << 6)

/*
 * Reset for GPIOx peripherals
 */

#define RCC_GPIOA_REG_RST()							do{ RCC->AHB1RSTR |= (1 << 0); (RCC->AHB1RSTR &= ~(1 << 0));} while(0)
#define RCC_GPIOB_REG_RST()							do{ RCC->AHB1RSTR |= (1 << 1); (RCC->AHB1RSTR &= ~(1 << 1));} while(0)
#define RCC_GPIOC_REG_RST()							do{ RCC->AHB1RSTR |= (1 << 2); (RCC->AHB1RSTR &= ~(1 << 2));} while(0)
#define RCC_GPIOD_REG_RST()							do{ RCC->AHB1RSTR |= (1 << 3); (RCC->AHB1RSTR &= ~(1 << 3));} while(0)
#define RCC_GPIOE_REG_RST()							do{ RCC->AHB1RSTR |= (1 << 4); (RCC->AHB1RSTR &= ~(1 << 4));} while(0)
#define RCC_GPIOF_REG_RST()							do{ RCC->AHB1RSTR |= (1 << 5); (RCC->AHB1RSTR &= ~(1 << 5));} while(0)
#define RCC_GPIOG_REG_RST()							do{ RCC->AHB1RSTR |= (1 << 6); (RCC->AHB1RSTR &= ~(1 << 6));} while(0)



#define ENABLE						1
#define DISBLE						0
#define SET							ENABLE
#define RESET						DISBLE
#define GPIO_PIN_SET				ENABLE
#define GPIO_PIN_RESET				DISBLE
#define BTN_PRESSED					ENABLE
#define BTN_NOTPRESSED				DISBLE


#endif /* ICN_STM32G4XX_H_ */
