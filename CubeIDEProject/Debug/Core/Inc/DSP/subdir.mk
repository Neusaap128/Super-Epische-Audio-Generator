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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-DSP

clean-Core-2f-Inc-2f-DSP:
	-$(RM) ./Core/Inc/DSP/DSP.cyclo ./Core/Inc/DSP/DSP.d ./Core/Inc/DSP/DSP.o ./Core/Inc/DSP/DSP.su

.PHONY: clean-Core-2f-Inc-2f-DSP

