################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Usart/src/subdir.mk
-include MCAL/Timer/src/subdir.mk
-include MCAL/Spi/src/subdir.mk
-include MCAL/Ext_Interrupt/src/subdir.mk
-include MCAL/Dio/src/subdir.mk
-include Libraries/LIBRARIES_SRC/subdir.mk
-include HAL/Ultrasonic/src/subdir.mk
-include HAL/SwPwm/src/subdir.mk
-include HAL/SevenSegment/src/subdir.mk
-include HAL/PushButton/src/subdir.mk
-include HAL/Led/src/subdir.mk
-include HAL/Icu/src/subdir.mk
-include HAL/Dc_Motor/src/subdir.mk
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
ComAppMcu1.lss \

FLASH_IMAGE += \
ComAppMcu1.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: ComAppMcu1.elf secondary-outputs

# Tool invocations
ComAppMcu1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ComAppMcu1.map -mmcu=atmega32 -o "ComAppMcu1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ComAppMcu1.lss: ComAppMcu1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ComAppMcu1.elf  >"ComAppMcu1.lss"
	@echo 'Finished building: $@'
	@echo ' '

ComAppMcu1.hex: ComAppMcu1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ComAppMcu1.elf  "ComAppMcu1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ComAppMcu1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ComAppMcu1.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: ComAppMcu1.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:ComAppMcu1.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ComAppMcu1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
