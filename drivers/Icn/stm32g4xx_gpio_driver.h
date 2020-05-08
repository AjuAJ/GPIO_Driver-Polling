

#include "stm32g4xx.h"

/*
 * This is configuration structure for GPIO PIN
 */



typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPDControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;




/*
 * This is GPIO handle structure
 */


typedef struct
{
	GPIO_RegDef_t *pGPIOx; 					//Pointer to hold the base address of GPIO
	GPIO_PinConfig_t GPIO_PinConfig; 		//Variable to hold pin configuration
}GPIO_Handel_t;


#define GPIO_INPUT_MODE						0
#define GPIO_OUTPUT_MODE					1
#define GPIO_ALTERNATEFUNC_MODE				2
#define GPIO_ANALOG_MODE					3

#define GPIO_LOW_SPEED						0
#define GPIO_MED_SPEED						1
#define GPIO_HIGH_SPEED						2
#define GPIO_VHIGH_SPEED					3


#define GPIO_OP_TYPE_PP						0
#define GPIO_OP_TYPE_OD						1


#define GPIO_NOPUPD							0
#define GPIO_PU	     						1
#define GPIO_PD 							2

#define GPIO_PIN_NO_1						1
#define GPIO_PIN_NO_2						2
#define GPIO_PIN_NO_3						3
#define GPIO_PIN_NO_4						4
#define GPIO_PIN_NO_5						5
#define GPIO_PIN_NO_6						6
#define GPIO_PIN_NO_7						7
#define GPIO_PIN_NO_8						8
#define GPIO_PIN_NO_9						9
#define GPIO_PIN_NO_10						10
#define GPIO_PIN_NO_11						11
#define GPIO_PIN_NO_12						12
#define GPIO_PIN_NO_13						13
#define GPIO_PIN_NO_14						14
#define GPIO_PIN_NO_15						15


/*************************************************************************************
 *
 * 							API's supported by this driver
 *
 *************************************************************************************/

void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDB);

/*
 * Init and Deint
 */

void GPIO_Init(GPIO_Handel_t *pGPIO_Handel);
void GPIO_Deinit(GPIO_RegDef_t *pGPIOx);

/*
 * Read and Write config
 */
uint8_t GPIO_ReadPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WritePIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value);

/*
 * IRQ config and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDB);
void GPIO_IRQHangling(uint8_t PinNumber);
