.POSIX:

TARGET_PROFILE = release
TARGET_DIR     = target/release

SRC = Robot.cpp RobotContainer.cpp \
				commands/Autos.cpp commands/ExampleCommand.cpp \
				subsystems/ExampleSubsystem.cpp

all: cpp

rust: cbindgen
	cargo b --profile ${TARGET_PROFILE}
	cp ${TARGET_DIR}/libchalkydri.a .

cbindgen:
	cbindgen -o src/cpp/__generated.hpp

cpp: ${SRC}
	clang++ -flto ${SRC:=.o} libchalkydri.a -o chalkydri
	llvm-strip -s chalkydri

${SRC}:
	clang++ -c -O3 src/cpp/$@ -o $@.o

clean:
	rm chalkydri libchalkydri.a *.cpp.o \
		src/cpp/__generated.hpp

.PHONY: all rust cbindgen cpp clean
