################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 4-APP/subdir.mk
-include 2-HAL/SevenSegment/subdir.mk
-include 2-HAL/LCD/subdir.mk
-include 2-HAL/Keypad/subdir.mk
-include 1-MCAL/Timers/subdir.mk
-include 1-MCAL/GI/subdir.mk
-include 1-MCAL/EXTI/subdir.mk
-include 1-MCAL/DIO/subdir.mk
-include 1-MCAL/ADC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Timer1_Test.lss \

FLASH_IMAGE += \
Timer1_Test.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Timer1_Test.elf secondary-outputs

# Tool invocations
Timer1_Test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Timer1_Test.map -mmcu=atmega32 -o "Timer1_Test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Timer1_Test.lss: Timer1_Test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Timer1_Test.elf  >"Timer1_Test.lss"
	@echo 'Finished building: $@'
	@echo ' '

Timer1_Test.hex: Timer1_Test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Timer1_Test.elf  "Timer1_Test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Timer1_Test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Timer1_Test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Timer1_Test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
