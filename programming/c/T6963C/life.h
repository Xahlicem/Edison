#ifndef LIFE
#define LIFE

#include "T6963C.h"

char old[PIXEL_MEMORY_COUNT];

void life();
void randomize();
char getOldPixelAt(int, int);

#endif
