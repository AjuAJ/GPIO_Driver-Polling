################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/stm32g4xx_gpio_driver.c 

OBJS += \
./drivers/Src/stm32g4xx_gpio_driver.o 

C_DEPS += \
./drivers/Src/stm32g4xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/stm32g4xx_gpio_driver.o: ../drivers/Src/stm32g4xx_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32G431CBUx -DSTM32G4 -DDEBUG -c -I../Inc -I"C:/Users/AJAY/STM32CubeIDE/workspace_1.3.0/stm32g4_driver_dev/drivers/Icn" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/stm32g4xx_gpio_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

