################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Filters/MovingAverage.c 

OBJS += \
./Core/Inc/Filters/MovingAverage.o 

C_DEPS += \
./Core/Inc/Filters/MovingAverage.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Filters/%.o Core/Inc/Filters/%.su Core/Inc/Filters/%.cyclo: ../Core/Inc/Filters/%.c Core/Inc/Filters/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Filters

clean-Core-2f-Inc-2f-Filters:
	-$(RM) ./Core/Inc/Filters/MovingAverage.cyclo ./Core/Inc/Filters/MovingAverage.d ./Core/Inc/Filters/MovingAverage.o ./Core/Inc/Filters/MovingAverage.su

.PHONY: clean-Core-2f-Inc-2f-Filters

