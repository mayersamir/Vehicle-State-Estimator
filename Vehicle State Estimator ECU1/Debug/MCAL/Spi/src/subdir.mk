################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Spi/src/Spi.c \
../MCAL/Spi/src/SpiLcfg.c 

OBJS += \
./MCAL/Spi/src/Spi.o \
./MCAL/Spi/src/SpiLcfg.o 

C_DEPS += \
./MCAL/Spi/src/Spi.d \
./MCAL/Spi/src/SpiLcfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Spi/src/%.o: ../MCAL/Spi/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\projects\ComAppMcu1\MCAL\Spi\inc" -I"D:\projects\ComAppMcu1\Libraries\LIBRARIES_INCLUDES" -I"D:\projects\ComAppMcu1" -I"D:\projects\ComAppMcu1\MCAL\Usart\inc" -I"D:\projects\ComAppMcu1\HAL\SwPwm\inc" -I"D:\projects\ComAppMcu1\HAL\Ultrasonic\inc" -I"D:\projects\ComAppMcu1\HAL\Dc_Motor\inc" -I"D:\projects\ComAppMcu1\HAL\Icu\inc" -I"D:\projects\ComAppMcu1\HAL\SevenSegment\inc" -I"D:\projects\ComAppMcu1\HAL\Led\inc" -I"D:\projects\ComAppMcu1\HAL\PushButton\inc" -I"D:\projects\ComAppMcu1\MCAL\Dio\inc" -I"D:\projects\ComAppMcu1\MCAL\Ext_Interrupt\inc" -I"D:\projects\ComAppMcu1\MCAL\Timer\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


