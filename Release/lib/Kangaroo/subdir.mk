################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/Kangaroo/KangarooCRC.cpp \
../lib/Kangaroo/KangarooChannel.cpp \
../lib/Kangaroo/KangarooCommandWriter.cpp \
../lib/Kangaroo/KangarooMonitor.cpp \
../lib/Kangaroo/KangarooReplyReader.cpp \
../lib/Kangaroo/KangarooReplyReceiver.cpp \
../lib/Kangaroo/KangarooSerial.cpp \
../lib/Kangaroo/KangarooStatus.cpp \
../lib/Kangaroo/KangarooTimeout.cpp 

CPP_DEPS += \
./lib/Kangaroo/KangarooCRC.cpp.d \
./lib/Kangaroo/KangarooChannel.cpp.d \
./lib/Kangaroo/KangarooCommandWriter.cpp.d \
./lib/Kangaroo/KangarooMonitor.cpp.d \
./lib/Kangaroo/KangarooReplyReader.cpp.d \
./lib/Kangaroo/KangarooReplyReceiver.cpp.d \
./lib/Kangaroo/KangarooSerial.cpp.d \
./lib/Kangaroo/KangarooStatus.cpp.d \
./lib/Kangaroo/KangarooTimeout.cpp.d 

LINK_OBJ += \
./lib/Kangaroo/KangarooCRC.cpp.o \
./lib/Kangaroo/KangarooChannel.cpp.o \
./lib/Kangaroo/KangarooCommandWriter.cpp.o \
./lib/Kangaroo/KangarooMonitor.cpp.o \
./lib/Kangaroo/KangarooReplyReader.cpp.o \
./lib/Kangaroo/KangarooReplyReceiver.cpp.o \
./lib/Kangaroo/KangarooSerial.cpp.o \
./lib/Kangaroo/KangarooStatus.cpp.o \
./lib/Kangaroo/KangarooTimeout.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
lib/Kangaroo/KangarooCRC.cpp.o: ../lib/Kangaroo/KangarooCRC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooChannel.cpp.o: ../lib/Kangaroo/KangarooChannel.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooCommandWriter.cpp.o: ../lib/Kangaroo/KangarooCommandWriter.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooMonitor.cpp.o: ../lib/Kangaroo/KangarooMonitor.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooReplyReader.cpp.o: ../lib/Kangaroo/KangarooReplyReader.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooReplyReceiver.cpp.o: ../lib/Kangaroo/KangarooReplyReceiver.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooSerial.cpp.o: ../lib/Kangaroo/KangarooSerial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooStatus.cpp.o: ../lib/Kangaroo/KangarooStatus.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

lib/Kangaroo/KangarooTimeout.cpp.o: ../lib/Kangaroo/KangarooTimeout.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/home/robert/dev/arduino-1.5.2/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=cortex-m3 -DF_CPU=84000000L -DARDUINO=152 -D__SAM3X8E__ -mthumb -DUSB_PID=0x003e -DUSB_VID=0x2341 -DUSBCON "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/libsam" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/CMSIS/Include/" "-I/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/system/CMSIS/Device/ATMEL/"   -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/cores/arduino" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/variants/arduino_due_x" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/DueTimer" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/Kangaroo" -I"/home/robert/dev/arduino-1.5.2/hardware/arduino/sam/libraries/SPI" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/MultiSerial" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/JsonStream" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/NMEA" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PString" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/AverageList" -I"/home/robert/devSpace/dueWorkspace/freeboardDue/lib/PID_v1" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


