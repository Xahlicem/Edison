#ifndef T6963C
#define T6963C

#include "mraa.h"

#define WAIT_SHORT 2
#define WAIT_LONG 10

#define WIDTH 240
#define HEIGHT 128
#define PIXEL_COUNT WIDTH * HEIGHT
#define PIXEL_MEMORY_COUNT PIXEL_COUNT / 8

mraa_gpio_context reset;
mraa_gpio_context wr, rd, ce, dc;
mraa_gpio_context pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7;

char pixels[PIXEL_MEMORY_COUNT];

void nop(int);
void initPins();
void closePins();
void setPins(char);
void send();
void sendData(char);
void sendCommand(char);
void sendCommand1(char, char);
void sendCommand2(char, char, char);
int status(int);
void init();
void clear();
void clearPixels();
void setTAddress(int, int);
void setGAddress(int, int);
void printChar(char);
void printString(char *);
void printPixels();
void printPixelArea(int, int, int, int);

#endif
