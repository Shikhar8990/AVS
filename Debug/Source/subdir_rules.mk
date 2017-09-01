################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Source/ADC.obj: ../Source/ADC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/ADC.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/BoardInit.obj: ../Source/BoardInit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/BoardInit.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_ADC_cal.obj: ../Source/DSP2833x_ADC_cal.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/DSP2833x_ADC_cal.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_DefaultIsr.obj: ../Source/DSP2833x_DefaultIsr.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/DSP2833x_DefaultIsr.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_PieCtrl.obj: ../Source/DSP2833x_PieCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/DSP2833x_PieCtrl.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_PieVect.obj: ../Source/DSP2833x_PieVect.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/DSP2833x_PieVect.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_SysCtrl.obj: ../Source/DSP2833x_SysCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/DSP2833x_SysCtrl.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/DSP2833x_usDelay.obj: ../Source/DSP2833x_usDelay.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/DSP2833x_usDelay.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Debug.obj: ../Source/Debug.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/Debug.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Gpio.obj: ../Source/Gpio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/Gpio.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/ISRs.obj: ../Source/ISRs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/ISRs.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/MainProg.obj: ../Source/MainProg.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/MainProg.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/PWM.obj: ../Source/PWM.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/PWM.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Serial.obj: ../Source/Serial.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/Serial.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Timers.obj: ../Source/Timers.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/Timers.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/Variables.obj: ../Source/Variables.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/Variables.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/central_control.obj: ../Source/central_control.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/central_control.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/fbcm_control.obj: ../Source/fbcm_control.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/fbcm_control.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/fbcm_state_machine.obj: ../Source/fbcm_state_machine.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/fbcm_state_machine.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/mppt.obj: ../Source/mppt.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/mppt.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/pid_control.obj: ../Source/pid_control.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv5/tools/compiler/c2000_6.1.3/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --include_path="C:/ti/ccsv5/tools/compiler/c2000_6.1.3/include" --include_path="C:/Users/ssingh14/Desktop/AVSS/Include" --include_path="C:/Users/ssingh14/Desktop/AVSS/DSP_Headers" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="Source/pid_control.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


