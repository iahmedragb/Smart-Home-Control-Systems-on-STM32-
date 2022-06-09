################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AC.c \
../Src/ADC.c \
../Src/Door.c \
../Src/EXTI.c \
../Src/GPIO.c \
../Src/HC05.c \
../Src/Keypad.c \
../Src/LCD.c \
../Src/LED.c \
../Src/LED_Config.c \
../Src/NVIC.c \
../Src/RCC.c \
../Src/SPI_program.c \
../Src/STK.c \
../Src/SYSCFG.c \
../Src/Switch.c \
../Src/Switch_Config.c \
../Src/TFT_program.c \
../Src/TIM.c \
../Src/UART.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AC.o \
./Src/ADC.o \
./Src/Door.o \
./Src/EXTI.o \
./Src/GPIO.o \
./Src/HC05.o \
./Src/Keypad.o \
./Src/LCD.o \
./Src/LED.o \
./Src/LED_Config.o \
./Src/NVIC.o \
./Src/RCC.o \
./Src/SPI_program.o \
./Src/STK.o \
./Src/SYSCFG.o \
./Src/Switch.o \
./Src/Switch_Config.o \
./Src/TFT_program.o \
./Src/TIM.o \
./Src/UART.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AC.d \
./Src/ADC.d \
./Src/Door.d \
./Src/EXTI.d \
./Src/GPIO.d \
./Src/HC05.d \
./Src/Keypad.d \
./Src/LCD.d \
./Src/LED.d \
./Src/LED_Config.d \
./Src/NVIC.d \
./Src/RCC.d \
./Src/SPI_program.d \
./Src/STK.d \
./Src/SYSCFG.d \
./Src/Switch.d \
./Src/Switch_Config.d \
./Src/TFT_program.d \
./Src/TIM.d \
./Src/UART.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AC.d ./Src/AC.o ./Src/AC.su ./Src/ADC.d ./Src/ADC.o ./Src/ADC.su ./Src/Door.d ./Src/Door.o ./Src/Door.su ./Src/EXTI.d ./Src/EXTI.o ./Src/EXTI.su ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/HC05.d ./Src/HC05.o ./Src/HC05.su ./Src/Keypad.d ./Src/Keypad.o ./Src/Keypad.su ./Src/LCD.d ./Src/LCD.o ./Src/LCD.su ./Src/LED.d ./Src/LED.o ./Src/LED.su ./Src/LED_Config.d ./Src/LED_Config.o ./Src/LED_Config.su ./Src/NVIC.d ./Src/NVIC.o ./Src/NVIC.su ./Src/RCC.d ./Src/RCC.o ./Src/RCC.su ./Src/SPI_program.d ./Src/SPI_program.o ./Src/SPI_program.su ./Src/STK.d ./Src/STK.o ./Src/STK.su ./Src/SYSCFG.d ./Src/SYSCFG.o ./Src/SYSCFG.su ./Src/Switch.d ./Src/Switch.o ./Src/Switch.su ./Src/Switch_Config.d ./Src/Switch_Config.o ./Src/Switch_Config.su ./Src/TFT_program.d ./Src/TFT_program.o ./Src/TFT_program.su ./Src/TIM.d ./Src/TIM.o ./Src/TIM.su ./Src/UART.d ./Src/UART.o ./Src/UART.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

