################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/PID_v1/PID_v1.cpp 

CPP_DEPS += \
./lib/PID_v1/PID_v1.cpp.d 

LINK_OBJ += \
./lib/PID_v1/PID_v1.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
lib/PID_v1/PID_v1.cpp.o: ../lib/PID_v1/PID_v1.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.7/hardware/tools/gcc-arm-none-eabi-4.8.3-2014q1/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=157 -DARDUINO_SAM_DUE -DARDUINO_ARCH_SAM  -D__SAM3X8E__ -mthumb -DUSB_VID=0x2341 -DUSB_PID=0x003e -DUSBCON '-DUSB_MANUFACTURER="Unknown"' '-DUSB_PRODUCT="Arduino Due"' "-I/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/gitrep/freeboardDue/lib/DueTimer" -I"/home/robert/gitrep/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/libraries/SPI" -I"/home/robert/gitrep/freeboardDue/lib/MultiSerial" -I"/home/robert/gitrep/freeboardDue/lib/NMEA" -I"/home/robert/gitrep/freeboardDue/lib/PString" -I"/home/robert/gitrep/freeboardDue/lib/AverageList" -I"/home/robert/gitrep/freeboardDue/lib/PID_v1" -I"/home/robert/gitrep/freeboardDue/lib/SignalK" -I"/home/robert/gitrep/freeboardDue/lib/Wind" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


