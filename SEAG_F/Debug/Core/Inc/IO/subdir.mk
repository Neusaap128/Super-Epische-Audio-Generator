################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/IO/IO.c \
../Core/Inc/IO/RotaryEncoder.c \
../Core/Inc/IO/ShiftRegister.c 

OBJS += \
./Core/Inc/IO/IO.o \
./Core/Inc/IO/RotaryEncoder.o \
./Core/Inc/IO/ShiftRegister.o 

C_DEPS += \
./Core/Inc/IO/IO.d \
./Core/Inc/IO/RotaryEncoder.d \
./Core/Inc/IO/ShiftRegister.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/IO/%.o Core/Inc/IO/%.su Core/Inc/IO/%.cyclo: ../Core/Inc/IO/%.c Core/Inc/IO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-IO

clean-Core-2f-Inc-2f-IO:
	-$(RM) ./Core/Inc/IO/IO.cyclo ./Core/Inc/IO/IO.d ./Core/Inc/IO/IO.o ./Core/Inc/IO/IO.su ./Core/Inc/IO/RotaryEncoder.cyclo ./Core/Inc/IO/RotaryEncoder.d ./Core/Inc/IO/RotaryEncoder.o ./Core/Inc/IO/RotaryEncoder.su ./Core/Inc/IO/ShiftRegister.cyclo ./Core/Inc/IO/ShiftRegister.d ./Core/Inc/IO/ShiftRegister.o ./Core/Inc/IO/ShiftRegister.su

.PHONY: clean-Core-2f-Inc-2f-IO

