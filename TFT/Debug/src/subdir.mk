################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GPIO_Programe.c \
../src/MRCC_Program.c \
../src/STP_Program.c \
../src/SYSTICK_Program.c \
../src/TFT_Program.c \
../src/main.c 

OBJS += \
./src/GPIO_Programe.o \
./src/MRCC_Program.o \
./src/STP_Program.o \
./src/SYSTICK_Program.o \
./src/TFT_Program.o \
./src/main.o 

C_DEPS += \
./src/GPIO_Programe.d \
./src/MRCC_Program.d \
./src/STP_Program.d \
./src/SYSTICK_Program.d \
./src/TFT_Program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	echo -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=25000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


