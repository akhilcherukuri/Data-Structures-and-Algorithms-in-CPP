################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/stock.cpp \
../src/stockDB.cpp \
../src/stockMain.cpp 

OBJS += \
./src/stock.o \
./src/stockDB.o \
./src/stockMain.o 

CPP_DEPS += \
./src/stock.d \
./src/stockDB.d \
./src/stockMain.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


