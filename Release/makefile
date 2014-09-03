################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include lib/Wind/subdir.mk
-include lib/SignalK/subdir.mk
-include lib/Seatalk/subdir.mk
-include lib/PString/subdir.mk
-include lib/PID_v1/subdir.mk
-include lib/NMEA/subdir.mk
-include lib/MultiSerial/subdir.mk
-include lib/Levels/subdir.mk
-include lib/Kangaroo/subdir.mk
-include lib/Gps/subdir.mk
-include lib/DueTimer/subdir.mk
-include lib/Autopilot/subdir.mk
-include lib/Anchor/subdir.mk
-include lib/Alarms/subdir.mk
-include arduino/variant/subdir.mk
-include arduino/core/avr/subdir.mk
-include arduino/core/USB/subdir.mk
-include arduino/core/subdir.mk
-include Libraries/SPI/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.managedbuilder.core/subdir.mk
-include .metadata/.plugins/org.eclipse.cdt.make.core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/robert/gitrep/freeboardDue/Release/arduino.ar \

ELF += \
freeboardDue.elf \

EEP += \
freeboardDue.eep \

FLASH_IMAGE += \
freeboardDue.bin \


# All Target
all: freeboardDue

# Tool invocations
freeboardDue: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/home/robert/dev/arduino-1.5.7/hardware/tools/gcc-arm-none-eabi-4.8.3-2014q1/bin/arm-none-eabi-size" -A "/home/robert/gitrep/freeboardDue/Release/freeboardDue.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/robert/gitrep/freeboardDue/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/home/robert/dev/arduino-1.5.7/hardware/tools/gcc-arm-none-eabi-4.8.3-2014q1/bin/arm-none-eabi-ar" rcs  "/home/robert/gitrep/freeboardDue/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

freeboardDue.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/home/robert/dev/arduino-1.5.7/hardware/tools/gcc-arm-none-eabi-4.8.3-2014q1/bin/arm-none-eabi-g++" -Os -Wl,--gc-sections -mcpu=cortex-m3 "-T/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/variants/arduino_due_x/linker_scripts/gcc/flash.ld" "-Wl,-Map,/home/robert/gitrep/freeboardDue/Release/freeboardDue.map"  -o "/home/robert/gitrep/freeboardDue/Release/freeboardDue.elf" "-L/home/robert/gitrep/freeboardDue/Release" -lm -lgcc -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group "/home/robert/gitrep/freeboardDue/Release/arduino/syscalls_sam3.c.o"   $(LINK_OBJ) $(AR)  "/home/robert/dev/arduino-1.5.7/hardware/arduino/sam/variants/arduino_due_x/libsam_sam3x8e_gcc_rel.a" "/home/robert/gitrep/freeboardDue/Release/arduino.ar" -Wl,--end-group
	@echo 'Finished building: $@'
	@echo ' '

freeboardDue.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

freeboardDue.bin: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/home/robert/dev/arduino-1.5.7/hardware/tools/gcc-arm-none-eabi-4.8.3-2014q1/bin/arm-none-eabi-objcopy" -O binary  "/home/robert/gitrep/freeboardDue/Release/freeboardDue.elf" "/home/robert/gitrep/freeboardDue/Release/freeboardDue.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(ELF)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(INO_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) freeboardDue
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
