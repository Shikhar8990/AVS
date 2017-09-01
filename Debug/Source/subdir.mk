################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/ADC.c \
../Source/BoardInit.c \
../Source/DSP2833x_DefaultIsr.c \
../Source/DSP2833x_PieCtrl.c \
../Source/DSP2833x_PieVect.c \
../Source/DSP2833x_SysCtrl.c \
../Source/Debug.c \
../Source/Gpio.c \
../Source/ISRs.c \
../Source/MainProg.c \
../Source/PWM.c \
../Source/Serial.c \
../Source/Timers.c \
../Source/Variables.c 

ASM_SRCS += \
../Source/DSP2833x_ADC_cal.asm \
../Source/DSP2833x_usDelay.asm 

ASM_DEPS += \
./Source/DSP2833x_ADC_cal.pp \
./Source/DSP2833x_usDelay.pp 

OBJS += \
./Source/ADC.obj \
./Source/BoardInit.obj \
./Source/DSP2833x_ADC_cal.obj \
./Source/DSP2833x_DefaultIsr.obj \
./Source/DSP2833x_PieCtrl.obj \
./Source/DSP2833x_PieVect.obj \
./Source/DSP2833x_SysCtrl.obj \
./Source/DSP2833x_usDelay.obj \
./Source/Debug.obj \
./Source/Gpio.obj \
./Source/ISRs.obj \
./Source/MainProg.obj \
./Source/PWM.obj \
./Source/Serial.obj \
./Source/Timers.obj \
./Source/Variables.obj 

C_DEPS += \
./Source/ADC.pp \
./Source/BoardInit.pp \
./Source/DSP2833x_DefaultIsr.pp \
./Source/DSP2833x_PieCtrl.pp \
./Source/DSP2833x_PieVect.pp \
./Source/DSP2833x_SysCtrl.pp \
./Source/Debug.pp \
./Source/Gpio.pp \
./Source/ISRs.pp \
./Source/MainProg.pp \
./Source/PWM.pp \
./Source/Serial.pp \
./Source/Timers.pp \
./Source/Variables.pp 

OBJS__QTD += \
".\Source\ADC.obj" \
".\Source\BoardInit.obj" \
".\Source\DSP2833x_ADC_cal.obj" \
".\Source\DSP2833x_DefaultIsr.obj" \
".\Source\DSP2833x_PieCtrl.obj" \
".\Source\DSP2833x_PieVect.obj" \
".\Source\DSP2833x_SysCtrl.obj" \
".\Source\DSP2833x_usDelay.obj" \
".\Source\Debug.obj" \
".\Source\Gpio.obj" \
".\Source\ISRs.obj" \
".\Source\MainProg.obj" \
".\Source\PWM.obj" \
".\Source\Serial.obj" \
".\Source\Timers.obj" \
".\Source\Variables.obj" 

ASM_DEPS__QTD += \
".\Source\DSP2833x_ADC_cal.pp" \
".\Source\DSP2833x_usDelay.pp" 

C_DEPS__QTD += \
".\Source\ADC.pp" \
".\Source\BoardInit.pp" \
".\Source\DSP2833x_DefaultIsr.pp" \
".\Source\DSP2833x_PieCtrl.pp" \
".\Source\DSP2833x_PieVect.pp" \
".\Source\DSP2833x_SysCtrl.pp" \
".\Source\Debug.pp" \
".\Source\Gpio.pp" \
".\Source\ISRs.pp" \
".\Source\MainProg.pp" \
".\Source\PWM.pp" \
".\Source\Serial.pp" \
".\Source\Timers.pp" \
".\Source\Variables.pp" 

C_SRCS_QUOTED += \
"../Source/ADC.c" \
"../Source/BoardInit.c" \
"../Source/DSP2833x_DefaultIsr.c" \
"../Source/DSP2833x_PieCtrl.c" \
"../Source/DSP2833x_PieVect.c" \
"../Source/DSP2833x_SysCtrl.c" \
"../Source/Debug.c" \
"../Source/Gpio.c" \
"../Source/ISRs.c" \
"../Source/MainProg.c" \
"../Source/PWM.c" \
"../Source/Serial.c" \
"../Source/Timers.c" \
"../Source/Variables.c" 

ASM_SRCS_QUOTED += \
"../Source/DSP2833x_ADC_cal.asm" \
"../Source/DSP2833x_usDelay.asm" 


# Each subdirectory must supply rules for building sources it contributes
Source/ADC.obj: ../Source/ADC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/ADC.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/BoardInit.obj: ../Source/BoardInit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/BoardInit.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_ADC_cal.obj: ../Source/DSP2833x_ADC_cal.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/DSP2833x_ADC_cal.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_DefaultIsr.obj: ../Source/DSP2833x_DefaultIsr.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/DSP2833x_DefaultIsr.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_PieCtrl.obj: ../Source/DSP2833x_PieCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/DSP2833x_PieCtrl.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_PieVect.obj: ../Source/DSP2833x_PieVect.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/DSP2833x_PieVect.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_SysCtrl.obj: ../Source/DSP2833x_SysCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/DSP2833x_SysCtrl.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_usDelay.obj: ../Source/DSP2833x_usDelay.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/DSP2833x_usDelay.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/Debug.obj: ../Source/Debug.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/Debug.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/Gpio.obj: ../Source/Gpio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/Gpio.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/ISRs.obj: ../Source/ISRs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/ISRs.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/MainProg.obj: ../Source/MainProg.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/MainProg.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/PWM.obj: ../Source/PWM.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/PWM.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/Serial.obj: ../Source/Serial.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/Serial.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/Timers.obj: ../Source/Timers.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/Timers.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

Source/Variables.obj: ../Source/Variables.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/Shailesh_Notani/workspace/AVSS/Include" --include_path="C:/Shailesh_Notani/workspace/AVSS/DSP_Headers" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="Source/Variables.pp" --obj_directory="Source" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


