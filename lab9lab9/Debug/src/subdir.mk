################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Infix2Postfix.cpp \
../src/Infix2Postfixmain.cpp 

OBJS += \
./src/Infix2Postfix.o \
./src/Infix2Postfixmain.o 

CPP_DEPS += \
./src/Infix2Postfix.d \
./src/Infix2Postfixmain.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


