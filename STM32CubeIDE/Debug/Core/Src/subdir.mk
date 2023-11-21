################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/CameraWithErrorCorrection.c \
../Core/Src/bsp_ov7725.c \
../Core/Src/bsp_sccb.c \
../Core/Src/fsmc.c \
../Core/Src/gpio.c \
../Core/Src/lcd.c \
../Core/Src/main.c \
../Core/Src/movement.c \
../Core/Src/servo.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tim.c \
../Core/Src/usart.c \
../Core/Src/xpt2046.c 

OBJS += \
./Core/Src/CameraWithErrorCorrection.o \
./Core/Src/bsp_ov7725.o \
./Core/Src/bsp_sccb.o \
./Core/Src/fsmc.o \
./Core/Src/gpio.o \
./Core/Src/lcd.o \
./Core/Src/main.o \
./Core/Src/movement.o \
./Core/Src/servo.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tim.o \
./Core/Src/usart.o \
./Core/Src/xpt2046.o 

C_DEPS += \
./Core/Src/CameraWithErrorCorrection.d \
./Core/Src/bsp_ov7725.d \
./Core/Src/bsp_sccb.d \
./Core/Src/fsmc.d \
./Core/Src/gpio.d \
./Core/Src/lcd.d \
./Core/Src/main.d \
./Core/Src/movement.d \
./Core/Src/servo.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tim.d \
./Core/Src/usart.d \
./Core/Src/xpt2046.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/CameraWithErrorCorrection.cyclo ./Core/Src/CameraWithErrorCorrection.d ./Core/Src/CameraWithErrorCorrection.o ./Core/Src/CameraWithErrorCorrection.su ./Core/Src/bsp_ov7725.cyclo ./Core/Src/bsp_ov7725.d ./Core/Src/bsp_ov7725.o ./Core/Src/bsp_ov7725.su ./Core/Src/bsp_sccb.cyclo ./Core/Src/bsp_sccb.d ./Core/Src/bsp_sccb.o ./Core/Src/bsp_sccb.su ./Core/Src/fsmc.cyclo ./Core/Src/fsmc.d ./Core/Src/fsmc.o ./Core/Src/fsmc.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/lcd.cyclo ./Core/Src/lcd.d ./Core/Src/lcd.o ./Core/Src/lcd.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/movement.cyclo ./Core/Src/movement.d ./Core/Src/movement.o ./Core/Src/movement.su ./Core/Src/servo.cyclo ./Core/Src/servo.d ./Core/Src/servo.o ./Core/Src/servo.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su ./Core/Src/xpt2046.cyclo ./Core/Src/xpt2046.d ./Core/Src/xpt2046.o ./Core/Src/xpt2046.su

.PHONY: clean-Core-2f-Src

