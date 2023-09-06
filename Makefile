.POSIX:

FRC_YEAR = 2023

WPILIB_PATH    = /home/lincoln/chalkydri
TOOLCHAIN_PATH = /home/lincoln/chalkydri/roborio
SYSROOT_PATH   = /home/lincoln/chalkydri/roborio/arm-nilrt-linux-gnueabi/sysroot

CC    = ${TOOLCHAIN_PATH}/bin/arm-frc${FRC_YEAR}-linux-gnueabi-gcc
CXX   = ${TOOLCHAIN_PATH}/bin/arm-frc${FRC_YEAR}-linux-gnueabi-g++
STRIP = ${TOOLCHAIN_PATH}/bin/arm-frc${FRC_YEAR}-linux-gnueabi-strip

TARGET_PROFILE = release
TARGET_DIR     = target/arm-unknown-linux-gnueabi/release

CXXFLAGS  = -O3 -fpermissive -std=c++20 -D__GLIBC_USE\(...\)=0 \
							--sysroot=${TOOLCHAIN_PATH}/arm-nilrt-linux-gnueabi/sysroot \
							-I${WPILIB_PATH}/usr/include/frc -I${SYSROOT_PATH}/usr/include -I${SYSROOT_PATH}/usr/include/c++/12 \
							-L${WPILIB_PATH}/usr/lib -L${SYSROOT_PATH}/lib -L${SYSROOT_PATH}/usr/lib \
							-lwpilibc -lwpilibNewCommands -lwpimath -lwpiutil -lwpinet -lwpiHal -lpthread -lntcore -lFRC_NetworkCommunication -lvisa -lembcanshim -lfpgalvshim -lRoboRIO_FRC_ChipObject
RUSTFLAGS = -C linker=${CC} \
							-C target-cpu=cortex-a9

SRC = Robot.cpp RobotContainer.cpp \
				commands/Autos.cpp \
				subsystems/ExampleSubsystem.cpp

all: cpp

rust: cbindgen
	export COMPILER_PATH="${TOOLCHAIN_PATH}/arm-nilrt-linux-gnueabi/bin"
	CARGO_TARGET_ARM_UNKNOWN_LINUX_GNUEABI_RUSTFLAGS="${RUSTFLAGS}" cargo b -vv --target arm-unknown-linux-gnueabi --profile ${TARGET_PROFILE}
	cp ${TARGET_DIR}/libchalkydri.a .

cbindgen:
	cbindgen -o src/cpp/__generated.hpp

# Build C++ code
cpp: _cpp ${SRC}
	${CXX} ${CXXFLAGS} ${SRC:=.o} libchalkydri.a -o chalkydri
	${STRIP} -s chalkydri

_cpp:
	export COMPILER_PATH="${TOOLCHAIN_PATH}/arm-nilrt-linux-gnueabi/bin"
	mkdir -p ./build/commands/ ./build/subsystems/

${SRC}:
	${CXX} -c ${CXXFLAGS} src/cpp/$@ -o $@.o

# Generate clangd (the LLVM project's C++ LSP) configuration
clangd:
	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" ./scripts/genClangdConfig.sh

clean:
	rm -f ./chalkydri ./libchalkydri.a ./src/cpp/__generated.hpp
	rm -rf ./target/ ./build/

.PHONY: all rust cbindgen cpp _cpp clangd clean
