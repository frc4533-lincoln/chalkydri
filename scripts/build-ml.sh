#!/bin/sh

# Update and/or initialize submodules
git submodule update --init

pushd deps

__libusb() {
	pushd libusb

	# Run GNU autoconf
	./bootstrap.sh
	
	# -fPIC: Position Independent Code (tells the linker to not use specific locations)
	# --enable-{shared,static}: Enables building the library's statically- and dynamically-linked versions
	# --disable-udev: 
	CFLAGS="-fPIC" ./configure --enable-static --enable-shared --disable-udev --prefix="$(pwd)/build"

	make
	make install

	# Set the pkgconfig search path
	# pkgconfig is a common utility for finding and configuring libraries to link to on Linux
	export PKG_CONFIG_PATH="$(pwd)/build/lib/pkgconfig"
	
	popd #libusb
}
__libusb

__libedgetpu() {
	pushd libedgetpu

	# Build it
	make libedgetpu

	popd #libedgetpu
}
__libedgetpu

__tflite() {
	pushd tensorflow
	mkdir -p build
	pushd build

	cmake ../tensorflow/lite/c/
	make

	popd #build
	popd #tensorflow
}
__tflite

popd #deps
