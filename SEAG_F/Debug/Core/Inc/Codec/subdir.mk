################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Codec/CodecDriver.c 

OBJS += \
./Core/Inc/Codec/CodecDriver.o 

C_DEPS += \
./Core/Inc/Codec/CodecDriver.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Codec/%.o Core/Inc/Codec/%.su Core/Inc/Codec/%.cyclo: ../Core/Inc/Codec/%.c Core/Inc/Codec/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Codec

clean-Core-2f-Inc-2f-Codec:
	-$(RM) ./Core/Inc/Codec/CodecDriver.cyclo ./Core/Inc/Codec/CodecDriver.d ./Core/Inc/Codec/CodecDriver.o ./Core/Inc/Codec/CodecDriver.su

.PHONY: clean-Core-2f-Inc-2f-Codec

