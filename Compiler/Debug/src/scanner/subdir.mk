################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/scanner/scanner.cpp 

OBJS += \
./src/scanner/scanner.o 

CPP_DEPS += \
./src/scanner/scanner.d 


# Each subdirectory must supply rules for building sources it contributes
src/scanner/%.o: ../src/scanner/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


