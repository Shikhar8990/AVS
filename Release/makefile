################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv5/tools/compiler/c2000_6.1.3

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./Source/pid_control.obj" \
"./Source/mppt.obj" \
"./Source/fbcm_control.obj" \
"./Source/central_control.obj" \
"./Source/Variables.obj" \
"./Source/Timers.obj" \
"./Source/Serial.obj" \
"./Source/PWM.obj" \
"./Source/MainProg.obj" \
"./Source/ISRs.obj" \
"./Source/Gpio.obj" \
"./Source/Debug.obj" \
"./Source/DSP2833x_usDelay.obj" \
"./Source/DSP2833x_SysCtrl.obj" \
"./Source/DSP2833x_PieVect.obj" \
"./Source/DSP2833x_PieCtrl.obj" \
"./Source/DSP2833x_DefaultIsr.obj" \
"./Source/DSP2833x_ADC_cal.obj" \
"./Source/BoardInit.obj" \
"./Source/ADC.obj" \
-l"rts2800_fpu32.lib" \
"../28335_RAM_lnk.cmd" \
"../DSP2833x_Headers_nonBIOS.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Source/subdir_vars.mk
-include subdir_rules.mk
-include Source/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: AVSS.out

# Tool invocations
AVSS.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" --silicon_version=28 -g -O2 --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 -z -m"AVSS.map" --stack_size=0x300 --warn_sections -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/lib" -i"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --reread_libs --rom_model -o "AVSS.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QUOTED) "AVSS.out"
	-$(RM) "Source\ADC.pp" "Source\BoardInit.pp" "Source\DSP2833x_DefaultIsr.pp" "Source\DSP2833x_PieCtrl.pp" "Source\DSP2833x_PieVect.pp" "Source\DSP2833x_SysCtrl.pp" "Source\Debug.pp" "Source\Gpio.pp" "Source\ISRs.pp" "Source\MainProg.pp" "Source\PWM.pp" "Source\Serial.pp" "Source\Timers.pp" "Source\Variables.pp" "Source\central_control.pp" "Source\fbcm_control.pp" "Source\mppt.pp" "Source\pid_control.pp" 
	-$(RM) "Source\ADC.obj" "Source\BoardInit.obj" "Source\DSP2833x_ADC_cal.obj" "Source\DSP2833x_DefaultIsr.obj" "Source\DSP2833x_PieCtrl.obj" "Source\DSP2833x_PieVect.obj" "Source\DSP2833x_SysCtrl.obj" "Source\DSP2833x_usDelay.obj" "Source\Debug.obj" "Source\Gpio.obj" "Source\ISRs.obj" "Source\MainProg.obj" "Source\PWM.obj" "Source\Serial.obj" "Source\Timers.obj" "Source\Variables.obj" "Source\central_control.obj" "Source\fbcm_control.obj" "Source\mppt.obj" "Source\pid_control.obj" 
	-$(RM) "Source\DSP2833x_ADC_cal.pp" "Source\DSP2833x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
