################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Inc/Filters/AllPass.c \
../Core/Inc/Filters/CombFeedback.c \
../Core/Inc/Filters/CombFeedforward.c \
../Core/Inc/Filters/FilterUtility.c \
../Core/Inc/Filters/Reverb.c 

OBJS += \
./Core/Inc/Filters/AllPass.o \
./Core/Inc/Filters/CombFeedback.o \
./Core/Inc/Filters/CombFeedforward.o \
./Core/Inc/Filters/FilterUtility.o \
./Core/Inc/Filters/Reverb.o 

C_DEPS += \
./Core/Inc/Filters/AllPass.d \
./Core/Inc/Filters/CombFeedback.d \
./Core/Inc/Filters/CombFeedforward.d \
./Core/Inc/Filters/FilterUtility.d \
./Core/Inc/Filters/Reverb.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/Filters/%.o Core/Inc/Filters/%.su Core/Inc/Filters/%.cyclo: ../Core/Inc/Filters/%.c Core/Inc/Filters/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F722xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-Filters

clean-Core-2f-Inc-2f-Filters:
	-$(RM) ./Core/Inc/Filters/AllPass.cyclo ./Core/Inc/Filters/AllPass.d ./Core/Inc/Filters/AllPass.o ./Core/Inc/Filters/AllPass.su ./Core/Inc/Filters/CombFeedback.cyclo ./Core/Inc/Filters/CombFeedback.d ./Core/Inc/Filters/CombFeedback.o ./Core/Inc/Filters/CombFeedback.su ./Core/Inc/Filters/CombFeedforward.cyclo ./Core/Inc/Filters/CombFeedforward.d ./Core/Inc/Filters/CombFeedforward.o ./Core/Inc/Filters/CombFeedforward.su ./Core/Inc/Filters/FilterUtility.cyclo ./Core/Inc/Filters/FilterUtility.d ./Core/Inc/Filters/FilterUtility.o ./Core/Inc/Filters/FilterUtility.su ./Core/Inc/Filters/Reverb.cyclo ./Core/Inc/Filters/Reverb.d ./Core/Inc/Filters/Reverb.o ./Core/Inc/Filters/Reverb.su

.PHONY: clean-Core-2f-Inc-2f-Filters

