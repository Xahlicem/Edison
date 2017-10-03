#include "chip8.h"
#include "T6963C.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char chip8_fontset[80] =
{
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void loadGame(char *name) {
	FILE *f = fopen(name, "rb");
	fseek(f, 0, SEEK_END);
	long pos = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *bytes = malloc(pos);
	fread(bytes, pos, 1, f);
	fclose(f);
	int i;

	for (i = 0; i < 80; i++) memory[i] = chip8_fontset[i];
	for (i = 0; i < pos; i++) memory[i + 512] = bytes[i];

	free(bytes);
	pc = 0x200;
	sp = 0;
}

void emu() {
	opcode = memory[pc] << 8 | memory[pc + 1];
	//printf("0x%04X - 0x%04X\n", pc, opcode);

	short x, y, height, pixel;

	//int keypress;
	int i;

	switch(opcode & 0xf000) {
		case 0x0000:
			switch(opcode & 0x000F) {
				case 0x0000: // 00E0 Clear
					for (i = 0; i < 32*64; i++) {
						display[i] = 0;
						drawFlag = 1;
					}
					pc += 2;
					break;
				case 0x000E: // 00EE return from sub routine
					pc = stack[--sp];
					pc += 2;
					break;
			}
			break;
		case 0x1000: // Jump to nnn
			pc = opcode & 0x0FFF;
			break;
		case 0x2000: // call sub routine at nnn
			stack[sp++] = pc;
			//sp++;
			pc = opcode & 0x0FFF;
			break;
		case 0x3000: // 3xKK if Vx == KK then skip
			if (v[(opcode & 0x0F00) >> 8] == (opcode & 0x00FF)) pc += 4;
			else pc += 2;
			break;
		case 0x4000: // 4xKK if Vx != KK the skip
			if (v[(opcode & 0x0F00) >> 8] != (opcode & 0x00FF)) pc += 4;
			else pc += 2;
			break;
		case 0x5000: // 5xy0 if Vx == Vy then skip
			if (v[(opcode & 0x0F00) >> 8] == v[(opcode & 0x00F0) >> 4]) pc += 4;
			else pc += 2;
			break;
		case 0x6000: // 6xKK insert KK into Vx
			v[(opcode & 0x0F00) >> 8] = (opcode & 0x00FF);
			pc += 2;
			break;
		case 0x7000: // 7xKK Vx = Vx + KK
			v[(opcode & 0x0F00) >> 8] += (opcode & 0x00FF);
			pc += 2;
			break;
		case 0x8000:
			switch(opcode & 0x000F) {
				case 0x0000:
v[(opcode & 0x0F00) >> 8] = v[(opcode & 0x00F0) >> 4];
pc += 2;
break;

//8xy1 VX = VX OR VY
case 0x0001:
v[(opcode & 0x0F00) >> 8] |= v[(opcode & 0x00F0) >> 4];
pc += 2;
break;

//8xy2 Vx = Vx AND Vy
case 0x0002:
v[(opcode & 0x0F00) >> 8] &= v[(opcode & 0x00F0) >> 4];
pc += 2;
break;

//8xy3 Vx = Vx XOR Vy
case 0x0003:
v[(opcode & 0x0F00) >> 8] ^= v[(opcode & 0x00F0) >> 4];
pc += 2;
break;

//8xy4 Vx = Vx + Vy
case 0x0004:
v[(opcode & 0x0F00) >> 8] += v[(opcode & 0x00F0) >> 4];
if(v[(opcode & 0x00F0) >> 4] > (0xFF - v[(opcode & 0x0F00) >> 8]))
{
v[0xF] = 1;
}
else 
{
v[0xF] = 0;
}
pc += 2;
break;

//8xy5 Vx = Vx - Vy
case 0x0005:
v[(opcode & 0x0F00) >> 8] -= v[(opcode & 0x00F0) >> 4];
if(v[(opcode & 0x00F0) >> 4] > (0xFF - v[(opcode & 0x0F00) >> 8]))
{
v[0xF] = 0;
}
else 
{
v[0xF] = 1;
}
pc += 2;
break;

//8xy6
case 0x0006:
	v[0xF] = v[(opcode & 0x0F00) >> 8] & 0x1;
	v[(opcode & 0x0F00) >> 8] >>= 1;

	pc += 2;
	break;

//8xy7 Vx = Vy - Vx
case 0x0007:
if(v[(opcode & 0x00F0) >> 4] < v[(opcode & 0x0F00) >> 8])
{
v[0xF] = 0;
}
else
{
v[0xF] = 1;
}
v[(opcode & 0x0F00) >> 8] = v[(opcode & 0x00F0) >> 4] - v[(opcode & 0x0F00) >> 8];

pc += 2;
break;

//8xyE Vx = Vx SHL 1
case 0x000E:
v[0xF] = v[(opcode & 0x0F00) >> 8] >> 7;
v[(opcode & 0x0F00) >> 8] <<= 1;
pc += 2;
break;
}
break;

//9xy0 if Vx != Vy program counter increases by 2
case 0x9000:
if(v[(opcode & 0x0F00) >> 8] != v[(opcode & 0x00F0) >> 4])
{
pc += 4;
}
else
{
pc += 2;
}
break;

//Annn Register I = nnn
case 0xA000:
I = opcode & 0x0FFF;
pc += 2;
break;

//Bnnn jump to location nnn + v0
case 0xB000:
pc = (opcode & 0x0FFF) + v[0];
break;

//Cxkk Vx = random byte and kk
case 0xC000:
v[(opcode & 0x0F00) >> 8] = (rand() % 0xFF) & (opcode & 0x00FF);
pc += 2;
break;

//Dxyn draws a sprite at Vx, Vy
case 0xD000:
x = v[(opcode & 0x0F00) >> 8];
y = v[(opcode & 0x00F0) >> 4];
height = opcode & 0x000F;

v[0xF] = 0;
for (int a = 0; a < height; a++)
{
pixel = memory[I + a];
for(int b = 0; b < 8; b++)
{
if((pixel & (0x80 >> b)) != 0)
{
if(display[(x + b + ((y + a) * 64))] == 1)
{
v[0xF] = 1; 
}
display[x + b + ((y + a) * 64)] ^= 1;
}
}
}

drawFlag = 1;
pc += 2;
break;


case 0xE000:
switch(opcode & 0x00FF)
{
//Ex9E Skip next instruction if key with Vx is pressed
case 0x009E:
if(keys[v[(opcode & 0x0F00) >> 8]] != 0)
{
pc += 4;
}
else
{
pc += 2;
}
break;

//ExA1 Skip next instruction if key with Vx is not pressed
case 0x00A1:
if(keys[v[(opcode & 0x0F00) >> 8]] == 0)
{
pc += 4;
}
else
{
pc += 2;
}
break;
}
break;

case 0xF000:
switch(opcode & 0x00FF)
{

//Fx07 Value of DT is placed on Vx
case 0x0007:
v[(opcode & 0x0F00) >> 8] = dt;
pc += 2;
break;

//Fx0A Wait for key then store in Vx
case 0x000A:
keyPress = 0;

for(int a = 0; a < 16; a++)
{
if(keys[a] != 0)
{
v[(opcode & 0x0F00) >> 8] = a;
keyPress = 1;
}
}
break;


//Fx15 DT set equal to Vx
case 0x0015:
dt = v[(opcode & 0x0F00) >> 8];
pc += 2;
break;

//Fx18 ST set equal to Vx
case 0x0018:
st = v[(opcode & 0x0F00) >> 8];
pc += 2;
break;

//Fx1E I = I + Vx
case 0x001E:
I += v[(opcode & 0x0F00) >> 8];
if(I > 0xFFF)
{
v[0xF] = 1;
}
else
{
v[0xF] = 0;
}
pc += 2;
break;

//Fx29 set I = sprite location Vx
case 0x0029:
I = v[(opcode & 0x0F00) >> 8] * 0x5;
pc += 2;
break;

//Fx33 Store BCD representations of Vx in memory
case 0x0033:
memory[I] = v[(opcode & 0x0F00) >> 8] / 100;
memory[I + 1] = (v[(opcode & 0x0F00) >> 8] / 10) % 10;
memory[I + 2] = (v[(opcode & 0x0F00) >> 8] % 100) % 10;
pc += 2;
break;

//Fx55 Stores V0 to VX in memory starting at address I
case 0x0055: 
for (int a = 0; a <= ((opcode & 0x0F00) >> 8); a++)
{
memory[I + a] = v[a];
}
I += ((opcode & 0x0F00) >> 8) + 1;
pc += 2;
break;

// Fx65 Fills V0 to VX with values from memory starting at address I
case 0x0065: 
for (int a = 0; a <= ((opcode & 0x0F00) >> 8); a++)
{
v[a] = memory[I + a];
}
I += ((opcode & 0x0F00) >> 8) + 1;
pc += 2;
break;
}
break;
}

	if(dt > 0) dt--;

	if(st > 0) st--;

	if (drawFlag) draw();
	drawFlag = 0;
}

void draw() {
	int x, y;

	if (0 == 1) {
	for (y = 0; y < 32; y++) {
		for (x = 0; x < 64; x += 8) {
			//printf("%d %d\n", x, y);
			int i = 0;
			i |= display[x + y * 64] << 7;
			i |= display[(x + 1) + y * 64] << 6;
			i |= display[(x + 2) + y * 64] << 5;
			i |= display[(x + 3) + y * 64] << 4;
			i |= display[(x + 4) + y * 64] << 3;
			i |= display[(x + 5) + y * 64] << 2;
			i |= display[(x + 6) + y * 64] << 1;
			i |= display[(x + 7) + y * 64];

			pixels[(x / 8) + y * (240 / 8)] = i;
		}
	}
	//printPixels();
	printPixelArea(0, 0, 64, 32);
	} else {
	for (y = 0; y < 32 * 2; y++) {
		for (x = 0; x < 64; x += 4) {
			//printf("%d %d\n", x, y);
			int i = 0;
			i |= display[x + (y / 2) * 64] << 7;
			i |= display[(x) + (y / 2) * 64] << 6;
			i |= display[(x + 1) + (y / 2) * 64] << 5;
			i |= display[(x + 1) + (y / 2) * 64] << 4;
			i |= display[(x + 2) + (y / 2) * 64] << 3;
			i |= display[(x + 2) + (y / 2) * 64] << 2;
			i |= display[(x + 3) + (y / 2) * 64] << 1;
			i |= display[(x + 3) + (y / 2) * 64];

			pixels[((x * 2) / 8) + y * (240 / 8)] = i;
		}
	}
	//printPixels();
	printPixelArea(0, 0, 128, 64);
	}
}
