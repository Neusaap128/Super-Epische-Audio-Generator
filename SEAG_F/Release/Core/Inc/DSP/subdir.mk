################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/DSP/DSP.c 

OBJS += \
./Core/Inc/DSP/DSP.o 

C_DEPS += \
./Core/Inc/DSP/DSP.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/DSP/%.o Core/Inc/DSP/%.su Core/Inc/DSP/%.cyclo: ../Core/Inc/DSP/%.c Core/Inc/DSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-DSP

clean-Core-2f-Inc-2f-DSP:
	-$(RM) ./Core/Inc/DSP/DSP.cyclo ./Core/Inc/DSP/DSP.d ./Core/Inc/DSP/DSP.o ./Core/Inc/DSP/DSP.su

.PHONY: clean-Core-2f-Inc-2f-DSP

