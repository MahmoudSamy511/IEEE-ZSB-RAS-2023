################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 4-APP/subdir.mk
-include 2-HAL/LCD/subdir.mk
-include 2-HAL/Keybad/subdir.mk
-include 1-MCAL/DIO/subdir.mk
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
Keybad_test.lss \

FLASH_IMAGE += \
Keybad_test.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Keybad_test.elf secondary-outputs

# Tool invocations
Keybad_test.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Keybad_test.map -mmcu=atmega32 -o "Keybad_test.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Keybad_test.lss: Keybad_test.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Keybad_test.elf  >"Keybad_test.lss"
	@echo 'Finished building: $@'
	@echo ' '

Keybad_test.hex: Keybad_test.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Keybad_test.elf  "Keybad_test.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Keybad_test.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Keybad_test.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Keybad_test.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
