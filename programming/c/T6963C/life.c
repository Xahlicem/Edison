#include "life.h"

#include <time.h>
#include <stdlib.h>
#include <math.h>

void life() {
	int i;
	//printf("copying:%d\n", PIXEL_MEMORY_COUNT);
	for (i = 0; i < PIXEL_MEMORY_COUNT; i++) {
		old[i] = pixels[i];
	}

	int x, y;
	for (y = 0; y < HEIGHT; y++)
		for (x = 0; x < WIDTH; x++) {
			int connected = 0;

      if (x > 0 && getOldPixelAt(x - 1, y)) connected++;
      if (x < WIDTH - 1 && getOldPixelAt(x + 1, y)) connected++;

      if (x > 0 && y > 0 && getOldPixelAt(x - 1, y - 1)) connected++;
      if (x < WIDTH - 1 && y > 0 && getOldPixelAt(x + 1, y - 1)) connected++;

      if (x > 0 && y < HEIGHT - 1 && getOldPixelAt(x - 1, y + 1)) connected++;
      if (x < WIDTH - 1 && y < HEIGHT - 1 && getOldPixelAt(x + 1, y + 1)) connected++;

      if (y > 0 && getOldPixelAt(x, y - 1)) connected++;
      if (y < HEIGHT - 1 && getOldPixelAt(x, y + 1)) connected++;

      switch (connected) {
      case 2:
        break;
      case 3:
	pixels[((x/8) + y * 30)] |= (1 << (7 - (x % 8)));
        break;
      default:
	pixels[((x/8) + y * 30)] &= ~(1 << (7 - (x % 8)));
        break;
      }
		}
}

void randomize() {
	srand(time(NULL));
	int i;
	for (i = 0; i < PIXEL_MEMORY_COUNT; i++) pixels[i] = rand() % 0xFF;
}

char getOldPixelAt(int x, int y) {
      return (old[(x / 8) + y * 30] >> (7 - (x % 8))) & 0x1;
}
