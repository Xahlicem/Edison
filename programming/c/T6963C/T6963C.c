#include "T6963C.h"

#include <string.h>

#include "mraa.h"

void nop(int x) {
	int i;
	for (i = 0; i < x * 100; i++);
}

mraa_gpio_context initPin(int num) {
	mraa_gpio_context ret = mraa_gpio_init(num);
	mraa_gpio_dir(ret, MRAA_GPIO_OUT);
	mraa_gpio_mode(ret, MRAA_GPIO_PULLUP);
	mraa_gpio_use_mmaped(ret, 1);
	return ret;
}

void initPins() {
	reset = initPin(10);
	wr = initPin(14);
	mraa_gpio_write(wr, 1);
	rd = initPin(15);
	mraa_gpio_write(rd, 1);
	dc = initPin(17);
	ce = initPin(16);
	pin0 = initPin(2);
	pin1 = initPin(3);
	pin2 = initPin(4);
	pin3 = initPin(5);
	pin4 = initPin(6);
	pin5 = initPin(7);
	pin6 = initPin(8);
	pin7 = initPin(9);
}

void closePins() {
	mraa_gpio_close(pin0);
	mraa_gpio_close(pin1);
	mraa_gpio_close(pin2);
	mraa_gpio_close(pin3);
	mraa_gpio_close(pin4);
	mraa_gpio_close(pin5);
	mraa_gpio_close(pin6);
	mraa_gpio_close(pin7);
	mraa_gpio_close(reset);
	mraa_gpio_close(wr);
	mraa_gpio_close(rd);
	mraa_gpio_close(dc);
	mraa_gpio_close(ce);
}

void setPins(char byte) {
        mraa_gpio_write(pin0, byte & 0x1);
	mraa_gpio_write(pin1, (byte >> 1) & 0x1);
	mraa_gpio_write(pin2, (byte >> 2) & 0x1);
	mraa_gpio_write(pin3, (byte >> 3) & 0x1);
	mraa_gpio_write(pin4, (byte >> 4) & 0x1);
	mraa_gpio_write(pin5, (byte >> 5) & 0x1);
	mraa_gpio_write(pin6, (byte >> 6) & 0x1);
	mraa_gpio_write(pin7, (byte >> 7) & 0x1);
}

void send() {
	mraa_gpio_write(ce, 0);
	nop(WAIT_SHORT);
	mraa_gpio_write(ce, 1);
}

void sendData(char byte) {
	//while (!status(0));
	mraa_gpio_write(dc, 0);
	mraa_gpio_write(wr, 0);
	setPins(byte);
	send();
	mraa_gpio_write(wr, 1);
	nop(WAIT_SHORT);
}

void sendCommand(char byte) {
	//while (!status(1));
	mraa_gpio_write(dc, 1);
	mraa_gpio_write(wr, 0);
	setPins(byte);
	send();
	mraa_gpio_write(wr, 1);
	nop(WAIT_LONG);
}

void sendCommand1(char data, char command) {
	sendData(data);
	sendCommand(command);
	nop(WAIT_LONG * 2);
}

void sendCommand2(char data0, char data1, char command) {
	sendData(data0);
	sendData(data1);
	sendCommand(command);
	nop(WAIT_LONG * 2);
}

int status(int print) {
	mraa_gpio_write(dc, 1);
	mraa_gpio_write(wr, 1);
	mraa_gpio_write(ce, 0);
	mraa_gpio_write(rd, 0);

	mraa_gpio_dir(pin0, MRAA_GPIO_IN);
	mraa_gpio_dir(pin1, MRAA_GPIO_IN);
	mraa_gpio_dir(pin2, MRAA_GPIO_IN);
	mraa_gpio_dir(pin3, MRAA_GPIO_IN);
	mraa_gpio_dir(pin4, MRAA_GPIO_IN);
	mraa_gpio_dir(pin5, MRAA_GPIO_IN);
	mraa_gpio_dir(pin6, MRAA_GPIO_IN);
	mraa_gpio_dir(pin7, MRAA_GPIO_IN);

	int sta0, sta1, sta2, sta3, sta4, sta5, sta6, sta7;

	sta0 = mraa_gpio_read(pin0);
	sta1 = mraa_gpio_read(pin1);
	sta2 = mraa_gpio_read(pin2);
	sta3 = mraa_gpio_read(pin3);
	sta4 = mraa_gpio_read(pin4);
	sta5 = mraa_gpio_read(pin5);
	sta6 = mraa_gpio_read(pin6);
	sta7 = mraa_gpio_read(pin7);

	if (print == 1) fprintf(stdout, "sta0=%d sta1=%d sta2=%d sta3=%d sta4=%d sta5=%d sta6=%d sta7=%d ready=%d\n", sta0, sta1, sta2, sta3, sta4, sta5, sta6, sta7, sta0 & sta1);

	mraa_gpio_dir(pin0, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin0, MRAA_GPIO_PULLUP);
	mraa_gpio_dir(pin1, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin1, MRAA_GPIO_PULLUP);
	mraa_gpio_dir(pin2, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin2, MRAA_GPIO_PULLUP);
	mraa_gpio_dir(pin3, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin3, MRAA_GPIO_PULLUP);
	mraa_gpio_dir(pin4, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin4, MRAA_GPIO_PULLUP);
	mraa_gpio_dir(pin5, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin5, MRAA_GPIO_PULLUP);
	mraa_gpio_dir(pin6, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin6, MRAA_GPIO_PULLUP);
	mraa_gpio_dir(pin7, MRAA_GPIO_OUT);
	mraa_gpio_mode(pin7, MRAA_GPIO_PULLUP);

	return (sta0 & sta1);
}

void init() {
	mraa_gpio_write(reset, 0);
	mraa_gpio_write(dc, 0);
	mraa_gpio_write(ce, 0);
	mraa_gpio_write(rd, 0);
	mraa_gpio_write(wr, 0);

	mraa_gpio_write(dc, 1);
	mraa_gpio_write(ce, 1);
	mraa_gpio_write(rd, 1);
	mraa_gpio_write(wr, 1);

	mraa_gpio_write(reset, 0);
	nop(WAIT_LONG * 2000);
	//usleep(5000);
	mraa_gpio_write(reset, 1);

	//		Mode
	//sendCommand(0x80);

	//		TH
	sendCommand2(0x00, 0x00, 0x40);

	//		TA
	sendCommand2(0x1E, 0x00, 0x41);

	//		GH
	sendCommand2(0x00, 0x03, 0x42);

	//		GA
	sendCommand2(0x1E, 0x00, 0x43);

	sendCommand(0b10000001);
	sendCommand(0b10011111);
	sendCommand(0xA7);

	clear();

	sendCommand2(0, 0, 0x24);
	sendCommand2(0, 0, 0x21);

	sendCommand(0x9C);
}

void clear() {
	setTAddress(0, 0);
	sendCommand(0xB0);
	nop(WAIT_LONG);
	//usleep(120);

	int i;
	for (i = 0; i < 16*30; i++) sendData(0x00);

	sendCommand(0xB2);
	nop(WAIT_LONG);
	//usleep(120);

	setGAddress(0, 0);
	sendCommand(0xB0);
	nop(WAIT_LONG);
	//usleep(120);

	for (i = 0; i < (240 * 128) / 8; i++) sendData(0x00);

	sendCommand(0xB2);
	nop(WAIT_LONG);
	//usleep(120);
	sendCommand2(0, 0, 0x21);

	setTAddress(0, 0);
	setGAddress(0, 0);
}

void clearPixels() {
	int i;
	for (i = 0; i < PIXEL_MEMORY_COUNT; i++) pixels[i] = 0;
}

void setTAddress(int x, int y) {
	unsigned int address = x + y * 30;
	sendCommand2(address & 0xff, address >> 8, 0x24);
}

void setGAddress(int x, int y) {
	unsigned int address = x + y * 30;
	address += 0x03 << 8;
	sendCommand2(address & 0xff, address >> 8, 0x24);
}

void printChar(char c) {
	sendCommand1(c - 32, 0xC0);
}

void printString(char *text) {
	int i;
	for (i = 0; i < strlen(text); i++) printChar(text[i]);
}

void printPixels() {
	setGAddress(0, 0);
	sendCommand(0xB0);

	int y, x;
	int i = 0;
	for (y = 0; y < HEIGHT; y++) {
		for (x = 0; x < WIDTH / 8; x++) sendData(pixels[i++]);
	}
	sendCommand(0xB2);
	//nop(WAIT_SHORT);
}

void printPixelArea(int startX, int startY, int width, int height) {

	int x, y;
	for (y = 0; y < height; y++) {
		setGAddress(startX / 8, startY + y);
		sendCommand(0xB0);
		for (x = 0; x < width / 8; x++) {
			sendData(pixels[(startX / 8 + x) + ((startY + y) * 240) / 8]);
		}
		sendCommand(0xB2);
		//nop(WAIT_SHORT);
	}
}
