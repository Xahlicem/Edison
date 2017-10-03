#include <stdio.h>	// printf(), malloc()
#include <string.h>	// strlen()
#include <fcntl.h>	// open(), close()
#include <glib.h>

#include "mraa.h"	// Edison lib
#include "mraa/i2c.h"	// Edison I2C lib
#include "ssd1306.h"	// Oled lib
#include "font.h"	// Font lib
#include "font_small.h"	// Font lib
#include "icon.h"	// Font lib

#define MAX_BUFFER_LENGTH 18

#define PIN_10_VAL "/sys/class/gpio/gpio41/value"
#define PIN_11_VAL "/sys/class/gpio/gpio43/value"
#define PIN_12_VAL "/sys/class/gpio/gpio42/value"

#define CHAR_BUFFER_LENGTH 5

//Global Variables
mraa_i2c_context i2c;
uint8_t device;
uint8_t buffer[MAX_BUFFER_LENGTH];
char logFile[] = "/programming/bin/log";
char tempFile[] = "/programming/bin/temp";

GMainLoop *loop;
char charBuffer[CHAR_BUFFER_LENGTH];

int fontSize = 8;

// Functions
void initI2c();
void closeI2c();
void setDevice(uint8_t deviceAddress);
void sendCommand(uint8_t com);
void sendCommands(data_t *commands);
void printChar(int, uint8_t ch[]);
void print(char *str);
void logLine(char *str);
void clearLine(int y);
void clearAll();
char * getIp();
char * getSignal();
void printSignal();
void printSprite(int xPos, int yPos, int width, int height, uint8_t sprite[][8]);
void startLoop();
static gboolean onButtonEvent(GIOChannel *channel, GIOCondition condition, gpointer user_data);

int main(int argc, char **argv) {
	initI2c();
	setDevice(SSD1306_ADDR);
	int i;
	if (argc > 1) switch (argv[1][0]) {
			case '0':
				initI2c();
				setDevice(SSD1306_ADDR);
				sendCommands(&ssd1306_init);
				sendCommands(&ssd1306_flip);
				sendCommands(&ssd1306_setHorMode);
				clearAll();
				sendCommand(ON);
				printSprite(6, 2, 4, 4, logo);
				sendCommands(ssd1306_setCursor(0, 6));
				for (i = 2; i < argc; i++)
					print(argv[i]);
				break;
			case '7':
				sendCommands(ssd1306_setCursor(0, 6));
                                for (i = 2; i < argc; i++)
                                        print(argv[i]);
                                break;
			case '9':
				clearLine(0);
				sendCommands(ssd1306_setCursor(0, 0));
				char *ip = getIp();
				if (ip[0] == '1') {
					print(ip);
					printSignal();
				}
				sendCommands(ssd1306_setCursor(0, 1));
				for (i = 2; i < argc; i++)
					logLine(argv[i]);
				break;
			case '1':
				for (i = 2; i < argc; i++)
					logLine(argv[i]);
				break;
			case '8':
				startLoop();
				break;
			case '6':
				initI2c();
				setDevice(SSD1306_ADDR);
				sendCommands(&ssd1306_init);
				sendCommands(&ssd1306_flip);
				sendCommands(&ssd1306_setHorMode);
				clearAll();
				sendCommand(ON);
				sendCommands(ssd1306_setCursor(0, 0));
				for (i = 0; i < 8*32; i++)
					printChar(4, font_small[i]);
				break;
		}
	else printf("Usage: ssd1306 (option) (string)\n");

	closeI2c();
	return 0;
}

void initI2c() {
        mraa_init();
        i2c = mraa_i2c_init(6);
}

void closeI2c() {
	mraa_i2c_stop(i2c);
}

void setDevice(uint8_t deviceAddress) {
	device = deviceAddress;
	mraa_i2c_address(i2c, device);
}

void sendCommand(uint8_t com) {
	buffer[0] = COMMAND;
	buffer[1] = com;
	mraa_i2c_write(i2c, buffer, 2);
}

void sendCommands(data_t *commands) {
	int i;
	for (i = 0; i < commands->length; i++) {
		buffer[i] = commands->data[i];
	}
	mraa_i2c_write(i2c, buffer, commands->length);
}

void printChar(int size, uint8_t ch[]) {
	buffer[0] = DATA;
	int i;
	for (i = 0; i < size; i++)
		buffer[i + 1] = ch[i];
	mraa_i2c_write(i2c, buffer, size + 1);
}

void print(char *str) {
	int i, length = strlen(str);
	if (fontSize == 8) {
		for (i = 0; i < length; i++)
			if (str[i] > 127 || str[i] < 32) return;
			else printChar(8, font[str[i] - 32]);
	} else {
		for (i = 0; i < length; i++)
			if (str[i] > 255 || str[i] < 0) return;
			else printChar(4, font_small[str[i]]);
	}
}

void logLine(char *str) {
	int i, c, length = strlen(str);
	int lines = length / 16;
	FILE *fOld, *fNew;
	char st[60];

	fOld = fopen(logFile, "r");
	fNew = fopen(tempFile, "w");

	if (!fOld || !fNew) return;

	for (i = lines; i >= 0; i--) {
		int flag = 0;
		for (c = 0; c < 16; c++) {
			if ((i * 16 + c) >= length) continue;
			fputc(str[i * 16 + c], fNew);
			flag++;
		}
		if (flag) fputs("\n", fNew);
	}

	i = lines;

	while (i < 8) {
		if ((fgets(st, 60, fOld)) == NULL) break;
		fputs(st, fNew);
		i++;
	}

	fclose(fNew);
	fclose(fOld);

	if (remove(logFile)) {printf("Error: removing old log\n"); return;}
	if (rename(tempFile, logFile)) {printf("Error: renaming\n"); return;}

	FILE *logP;
	logP = fopen(logFile, "r");
	for (i = 7; i > 0; i--) {
		if ((fgets(st, 60, logP)) == NULL) break;
		clearLine(i);
		sendCommands(ssd1306_setCursor(0, i));
		print(st);
	}
}

void clearLine(int y) {
	sendCommands(ssd1306_setCursor(0, y));
	print("                ");
	if (fontSize == 4) print("                ");
}

void clearAll() {
	int i;
	for (i = 0; i < 8; i++)
		clearLine(i);
}

char * getIp() {
	FILE *fp;
	char *ip = malloc(16);

	fp = popen("/sbin/get-ip wlan0", "r");
	if (fp == NULL)
		return "Error!";
	fgets(ip, 16, fp);
	pclose(fp);
	return ip;
}

char * getSignal() {
        FILE *fp;
        char *sig = malloc(5);

        fp = popen("/sbin/get-signal wlan0", "r");
        if (fp == NULL)
                return "Error!";
        fgets(sig, 5, fp);
        pclose(fp);
        return sig;
}

void printSignal() {
	int i, place = 0, value = 0;
	int val[3];
	char * sig = getSignal();
	for (i = strlen(sig); i > 0; i--) {
		if ((int)sig[i - 1] - 48 < 0 || (int)sig[i - 1] - 48 > 9) continue;
		val[place] = (int)sig[i - 1] - 48;
		place++;
	}
	for (i = 0; i < place; i++) {
		if (i == 0) value = val[i];
		else value = value + val[i] * (i * 10);
	}
	sendCommands(ssd1306_setCursor(15 * 8, 0));
	if (value > 75)
		printChar(8, signalIcon[1]);
        else if (value > 50)
                printChar(8, signalIcon[2]);
        else if (value > 25)
                printChar(8, signalIcon[3]);
        else if (value > 0)
                printChar(8, signalIcon[4]);
	else printChar(8, signalIcon[0]);
}

void printSprite(int xPos, int yPos, int width, int height, uint8_t sprite[][8]) {
	int x, y, i = 0;
	for (y = 0; y < height; y++) {
		sendCommands(ssd1306_setCursor(xPos * 8, yPos + y));
		for (x = 0; x < width; x++) {
			printChar(8, sprite[i++]);
		}
	}
}

void startLoop() {
	loop = g_main_loop_new(0, 0);

	//int pinRight = open(PIN_10_VAL, O_RDONLY | O_NONBLOCK);
        //int pinLeft = open(PIN_12_VAL, O_RDONLY | O_NONBLOCK);
        //int pinEnter = open(PIN_11_VAL, O_RDONLY | O_NONBLOCK);

        //GIOChannel *chRight = g_io_channel_unix_new(pinRight);
        //GIOChannel *chLeft = g_io_channel_unix_new(pinLeft);
        //GIOChannel *chEnter = g_io_channel_unix_new(pinEnter);

        //guint idRight = g_io_add_watch(chRight, G_IO_PRI, onButtonEvent, 0);
        //guint idLeft = g_io_add_watch(chLeft, G_IO_PRI, onButtonEvent, (gpointer *)1);
        //guint idEnter = g_io_add_watch(chEnter, G_IO_PRI, onButtonEvent, (gpointer *)2);

        g_main_loop_run(loop);
}

static gboolean onButtonEvent(GIOChannel *channel, GIOCondition condition, gpointer user_data) {
        GError *error = 0;
        gsize bytesRead = 0;

        g_io_channel_seek_position(channel, 0, G_SEEK_SET, 0);
        GIOStatus status = g_io_channel_read_chars(channel, charBuffer, CHAR_BUFFER_LENGTH - 1, &bytesRead, &error);

        if (charBuffer[0] == '1') return 1;

        switch ((int)user_data) {
                case 0:         //Right
			logLine("Right");
                        break;
                case 1:         //Left
                        logLine("Left");
                        break;
                case 2:         //Enter
                        logLine("Enter");
                        break;
        }

        return 1;
}

