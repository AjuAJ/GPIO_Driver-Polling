################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include drivers/Src/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
stm32g4_driver_dev.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stm32g4_driver_dev.list \

OBJCOPY_BIN += \
stm32g4_driver_dev.bin \


# All Target
all: stm32g4_driver_dev.elf secondary-outputs

# Tool invocations
stm32g4_driver_dev.elf: $(OBJS) $(USER_OBJS) C:\Users\AJAY\STM32CubeIDE\workspace_1.3.0\stm32g4_driver_dev\STM32G431CBUX_FLASH.ld
	arm-none-eabi-gcc -o "stm32g4_driver_dev.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\AJAY\STM32CubeIDE\workspace_1.3.0\stm32g4_driver_dev\STM32G431CBUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stm32g4_driver_dev.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stm32g4_driver_dev.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stm32g4_driver_dev.list"
	@echo 'Finished building: $@'
	@echo ' '

stm32g4_driver_dev.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "stm32g4_driver_dev.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
