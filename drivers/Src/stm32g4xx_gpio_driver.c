


#include "stm32g4xx_gpio_driver.h"




void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDB)
{
	if(ENorDB == ENABLE)
	{
        if (pGPIOx == GPIOA)
        {
        	RCC_GPIOA_CLK_ENABLE();
        }
        if (pGPIOx == GPIOB)
        {
        	RCC_GPIOB_CLK_ENABLE();
        }
        if (pGPIOx == GPIOC)
        {
        	RCC_GPIOC_CLK_ENABLE();
        }
        if (pGPIOx == GPIOD)
        {
        	RCC_GPIOD_CLK_ENABLE();
        }
        if (pGPIOx == GPIOE)
        {
        	RCC_GPIOE_CLK_ENABLE();
        }
        if (pGPIOx == GPIOF)
        {
        	RCC_GPIOF_CLK_ENABLE();
        }
        if (pGPIOx == GPIOG)
        {
        	RCC_GPIOG_CLK_ENABLE();
        }
	}
	else
	{
        if (pGPIOx == GPIOA)
        {
        	RCC_GPIOA_CLK_DISABLE();
        }
        if (pGPIOx == GPIOB)
        {
        	RCC_GPIOB_CLK_DISABLE();
        }
        if (pGPIOx == GPIOC)
        {
        	RCC_GPIOC_CLK_DISABLE();
        }
        if (pGPIOx == GPIOD)
        {
        	RCC_GPIOD_CLK_DISABLE();
        }
        if (pGPIOx == GPIOE)
        {
        	RCC_GPIOE_CLK_DISABLE();
        }
        if (pGPIOx == GPIOF)
        {
        	RCC_GPIOF_CLK_DISABLE();
        }
        if (pGPIOx == GPIOG)
        {
        	RCC_GPIOG_CLK_DISABLE();
        }
	}

}


void GPIO_Init(GPIO_Handel_t *pGPIO_Handel)
{

	uint8_t temp;

	// Setting the mode
	temp = pGPIO_Handel -> GPIO_PinConfig.GPIO_PinMode << 2*(pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->MODER &= ~(0x03 << pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->MODER |= temp;
	temp = 0;

	// Setting the speed
	temp = pGPIO_Handel -> GPIO_PinConfig.GPIO_PinSpeed << 2*(pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->OSPEEDR &= ~(0x03 << pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->OSPEEDR |= temp;
	temp = 0;

	// Setting alternate functionality
	if(pGPIO_Handel -> GPIO_PinConfig.GPIO_PinMode == GPIO_ALTERNATEFUNC_MODE)
	{
		if(pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber < 8)
		{
			temp = (pGPIO_Handel -> GPIO_PinConfig.GPIO_PinAltFunMode) << 4*(pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
			pGPIO_Handel->pGPIOx->AFR[0] &= ~(0x0F << pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
			pGPIO_Handel->pGPIOx->AFR[0] |= temp;
			temp = 0;
		}
		else
		{
			temp = (pGPIO_Handel -> GPIO_PinConfig.GPIO_PinAltFunMode) << 4*(pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
			pGPIO_Handel->pGPIOx->AFR[1] &= ~(0x0F << pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
			pGPIO_Handel->pGPIOx->AFR[1] |= temp;
			temp = 0;
		}
	}


	// Setting output mode
	temp = (pGPIO_Handel -> GPIO_PinConfig.GPIO_PinOPType) << (pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->OTYPER &= ~(0x01 << pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->OTYPER |= temp;
	temp = 0;

	// Setting pull-up and pull-down mode
	temp = (pGPIO_Handel -> GPIO_PinConfig.GPIO_PinPuPDControl) << 2*(pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->PUPDR &= ~(0x03 << pGPIO_Handel -> GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handel->pGPIOx->PUPDR |= temp;
	temp = 0;

}

void GPIO_Deinit(GPIO_RegDef_t *pGPIOx)
{
    if (pGPIOx == GPIOA)
    {
    	RCC_GPIOA_REG_RST();
    }
    if (pGPIOx == GPIOB)
    {
    	RCC_GPIOB_REG_RST();
    }
    if (pGPIOx == GPIOC)
    {
    	RCC_GPIOC_REG_RST();
    }
    if (pGPIOx == GPIOD)
    {
    	RCC_GPIOD_REG_RST();
    }
    if (pGPIOx == GPIOE)
    {
    	RCC_GPIOE_REG_RST();
    }
    if (pGPIOx == GPIOF)
    {
    	RCC_GPIOF_REG_RST();
    }
    if (pGPIOx == GPIOG)
    {
    	RCC_GPIOG_REG_RST();
    }
}



uint8_t GPIO_ReadPIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);

	return value;
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t) pGPIOx->IDR;

	return value;
}

void GPIO_WritePIN(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}

}

void GPIO_WritePort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}
