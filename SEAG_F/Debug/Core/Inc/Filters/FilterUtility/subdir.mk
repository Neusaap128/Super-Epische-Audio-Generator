################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Filters/FilterUtility/CircularBuffer.c \
../Core/Inc/Filters/FilterUtility/FilterUtility.c 

OBJS += \
./Core/Inc/Filters/FilterUtility/CircularBuffer.o \
./Core/Inc/Filters/FilterUtility/FilterUtility.o 

C_DEPS += \
./Core/Inc/Filters/FilterUtility/CircularBuffer.d \
./Core/Inc/Filters/FilterUtility/FilterUtility.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Filters/FilterUtility/%.o Core/Inc/Filters/FilterUtility/%.su Core/Inc/Filters/FilterUtility/%.cyclo: ../Core/Inc/Filters/FilterUtility/%.c Core/Inc/Filters/FilterUtility/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Filters-2f-FilterUtility

clean-Core-2f-Inc-2f-Filters-2f-FilterUtility:
	-$(RM) ./Core/Inc/Filters/FilterUtility/CircularBuffer.cyclo ./Core/Inc/Filters/FilterUtility/CircularBuffer.d ./Core/Inc/Filters/FilterUtility/CircularBuffer.o ./Core/Inc/Filters/FilterUtility/CircularBuffer.su ./Core/Inc/Filters/FilterUtility/FilterUtility.cyclo ./Core/Inc/Filters/FilterUtility/FilterUtility.d ./Core/Inc/Filters/FilterUtility/FilterUtility.o ./Core/Inc/Filters/FilterUtility/FilterUtility.su

.PHONY: clean-Core-2f-Inc-2f-Filters-2f-FilterUtility

