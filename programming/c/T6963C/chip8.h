#ifndef CHIP8
#define CHIP8

unsigned char memory[4096]; //4kb of ram

unsigned int stack[16];

unsigned char v[16]; //Vx

unsigned int keys[16]; //Key checks

unsigned int display[32 * 64]; //1 = pixel, 2 = no
unsigned int drawFlag; // 0 don't draw, 1 draw

unsigned int pc;
unsigned int I;
unsigned int sp; //Stack pointer
unsigned int keyPress;
unsigned int dt, st;
unsigned int opcode;

void loadGame(char *);
void emu();
void draw();

#endif
