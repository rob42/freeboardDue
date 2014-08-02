################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/NMEA/nmea.cpp 

CPP_DEPS += \
./lib/NMEA/nmea.cpp.d 

LINK_OBJ += \
./lib/NMEA/nmea.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
lib/NMEA/nmea.cpp.o: ../lib/NMEA/nmea.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


