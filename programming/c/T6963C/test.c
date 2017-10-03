#include <math.h>
//#include "T6963C.h"
#include "life.h"
#include "chip8.h"

int main(int argc, char **argv) {
	printf("Starting\n");
	initPins();
	init();
	int i;

	if (argc  <= 1) {
		printf("LIFE!\n");
		randomize();
		printPixels();

		for (int i = 0; i < 10000; i++) {
			life();
			printPixels();
		}
	}

	//int x = 0;
	//setGAddress(0, 0);
	/*while (1) {
		x++;
		setTAddress(4, 4);
		printString("Number!");
		randomize();
		for (i = 0; i < 3000; i++) {
			life();
			printPixels();
		}
	}*/
	else {
		printString(argv[1]);
//		loadGame(argv[1]);
//		for (i = 0; i < 100000; i++) {
//			emu();
//		}
	}
	closePins();
	return 0;
}
