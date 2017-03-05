all: clean build
	./mxt-gen-firmware
	echo "Copy the generated firmware to /lib/firmware/maxtouch.fw"

clean:
	rm -f mxt-gen-firmware maxtouch.fw

build:
	gcc -Wall -o mxt-gen-firmware src/mxt-gen-firmware.c
