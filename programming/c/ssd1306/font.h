uint8_t font[][8] = {
// Space
	{
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00
	},
// !
	{
		0x00,
		0x00,
		0x00,
		0x5E,
		0x5E,
		0x00,
		0x00,
		0x00
	},
// "
	{
		0x00,
		0x06,
		0x0E,
		0x00,
		0x06,
		0x0E,
		0x00,
		0x00
	},
// #
	{
		0x24,
		0x7E,
		0x7E,
		0x24,
		0x7E,
		0x7E,
		0x24,
		0x00
	},
// $
	{
		0x00,
		0x08,
		0x64,
		0x7E,
		0x7E,
		0x64,
		0x40,
		0x00
	},
// %
	{
		0x00,
		0x46,
		0x26,
		0x10,
		0x08,
		0x64,
		0x62,
		0x00
	},
// &
	{
		0x00,
		0x34,
		0x7E,
		0x4A,
		0x5A,
		0x6A,
		0x24,
		0x00
	},
// '
	{
		0x00,
		0x00,
		0x00,
		0x06,
		0x0E,
		0x00,
		0x00,
		0x00
	},
// (
	{
		0x00,
		0x00,
		0x18,
		0x3C,
		0x66,
		0x42,
		0x00,
		0x00
	},
// )
	{
		0x00,
		0x00,
		0x42,
		0x66,
		0x3C,
		0x18,
		0x00,
		0x00
	},
// *
	{
		0x00,
		0x00,
		0x00,
		0x14,
		0x0E,
		0x14,
		0x00,
		0x00
	},
// +
	{
		0x00,
		0x00,
		0x10,
		0x7C,
		0x7C,
		0x10,
		0x00,
		0x00
	},
// ,
	{
		0x00,
		0x00,
		0x00,
		0x60,
		0xE0,
		0x00,
		0x00,
		0x00
	},
// -
	{
		0x00,
		0x00,
		0x10,
		0x10,
		0x10,
		0x10,
		0x00,
		0x00
	},
// .
	{
		0x00,
		0x00,
		0x00,
		0x60,
		0x60,
		0x00,
		0x00,
		0x00
	},
// /
	{
		0x00,
		0x40,
		0x60,
		0x30,
		0x18,
		0x0C,
		0x04,
		0x00
	},
// 0
	{
		0x00,
		0x3C,
		0x7E,
		0x52,
		0x4A,
		0x7E,
		0x3C,
		0x00
	},
// 1
	{
		0x00,
		0x00,
		0x44,
		0x7E,
		0x7E,
		0x40,
		0x00,
		0x00
	},
// 2
	{
		0x00,
		0x44,
		0x66,
		0x72,
		0x52,
		0x5E,
		0x4C,
		0x00
	},
// 3
	{
		0x00,
		0x24,
		0x66,
		0x42,
		0x4A,
		0x7E,
		0x34,
		0x00
	},
// 4
	{
		0x00,
		0x30,
		0x38,
		0x2C,
		0x7E,
		0x7E,
		0x20,
		0x00
	},
// 5
	{
		0x00,
		0x2E,
		0x6E,
		0x4A,
		0x4A,
		0x7A,
		0x32,
		0x00
	},
// 6
	{
		0x00,
		0x3C,
		0x7E,
		0x4A,
		0x4A,
		0x7A,
		0x30,
		0x00
	},
// 7
	{
		0x00,
		0x02,
		0x62,
		0x72,
		0x1A,
		0x0E,
		0x06,
		0x00
	},
// 8
	{
		0x00,
		0x34,
		0x7E,
		0x4A,
		0x4A,
		0x7E,
		0x34,
		0x00
	},
// 9
	{
		0x00,
		0x24,
		0x6E,
		0x4A,
		0x4A,
		0x7E,
		0x3C,
		0x00
	},
// :
	{
		0x00,
		0x00,
		0x00,
		0x66,
		0x66,
		0x00,
		0x00,
		0x00
	},
// ;
	{
		0x00,
		0x00,
		0x00,
		0x66,
		0xE6,
		0x00,
		0x00,
		0x00
	},
// <
	{
		0x00,
		0x00,
		0x10,
		0x38,
		0x6C,
		0x44,
		0x00,
		0x00
	},
// =
	{
		0x00,
		0x00,
		0x28,
		0x28,
		0x28,
		0x28,
		0x00,
		0x00
	},
// >
	{
		0x00,
		0x00,
		0x44,
		0x6C,
		0x38,
		0x10,
		0x00,
		0x00
	},
// ?
	{
		0x00,
		0x04,
		0x06,
		0x52,
		0x5A,
		0x0E,
		0x04,
		0x00
	},
// @
	{
		0x00,
		0x3C,
		0x42,
		0x5A,
		0x5A,
		0x52,
		0x0C,
		0x00
	},
// A
	{
		0x00,
		0x7C,
		0x7E,
		0x0A,
		0x0A,
		0x7E,
		0x7C,
		0x00
	},
// B
	{
		0x00,
		0x7E,
		0x7E,
		0x4A,
		0x4A,
		0x7E,
		0x34,
		0x00
	},
// C
	{
		0x00,
		0x3C,
		0x7E,
		0x42,
		0x42,
		0x66,
		0x24,
		0x00
	},
// D
	{
		0x00,
		0x7E,
		0x7E,
		0x42,
		0x42,
		0x7E,
		0x3C,
		0x00
	},
// E
	{
		0x00,
		0x7E,
		0x7E,
		0x4A,
		0x4A,
		0x42,
		0x42,
		0x00
	},
// F
	{
		0x00,
		0x7E,
		0x7E,
		0x0A,
		0x0A,
		0x02,
		0x02,
		0x00
	},
// G
	{
		0x00,
		0x3C,
		0x7E,
		0x42,
		0x52,
		0x76,
		0x74,
		0x00
	},
// H
	{
		0x00,
		0x7E,
		0x7E,
		0x08,
		0x08,
		0x7E,
		0x7E,
		0x00
	},
// I
	{
		0x00,
		0x42,
		0x42,
		0x7E,
		0x7E,
		0x42,
		0x42,
		0x00
	},
// J
	{
		0x00,
		0x20,
		0x60,
		0x42,
		0x42,
		0x7E,
		0x3E,
		0x00
	},
// K
	{
		0x00,
		0x7E,
		0x7E,
		0x08,
		0x1C,
		0x76,
		0x62,
		0x00
	},
// L
	{
		0x00,
		0x7E,
		0x7E,
		0x40,
		0x40,
		0x40,
		0x40,
		0x00
	},
// M
	{
		0x00,
		0x7E,
		0x7E,
		0x0C,
		0x18,
		0x0C,
		0x7E,
		0x00
	},
// N
	{
		0x00,
		0x7E,
		0x7E,
		0x0C,
		0x18,
		0x7E,
		0x7E,
		0x00
	},
// O
	{
		0x00,
		0x3C,
		0x7E,
		0x42,
		0x42,
		0x7E,
		0x3C,
		0x00
	},
// P
	{
		0x00,
		0x7E,
		0x7E,
		0x0A,
		0x0A,
		0x0E,
		0x04,
		0x00
	},
// Q
	{
		0x00,
		0x3C,
		0x7E,
		0x42,
		0x62,
		0x7E,
		0x7C,
		0x00
	},
// R
	{
		0x00,
		0x7E,
		0x7E,
		0x0A,
		0x0A,
		0x7E,
		0x74,
		0x00
	},
// S
	{
		0x00,
		0x24,
		0x6E,
		0x4A,
		0x4A,
		0x7A,
		0x30,
		0x00
	},
// T
	{
		0x00,
		0x02,
		0x02,
		0x7E,
		0x7E,
		0x02,
		0x02,
		0x00
	},
// U
	{
		0x00,
		0x5E,
		0x7E,
		0x40,
		0x40,
		0x7E,
		0x7E,
		0x00
	},
// V
	{
		0x00,
		0x1E,
		0x3E,
		0x60,
		0x60,
		0x3E,
		0x1E,
		0x00
	},
// W
	{
		0x00,
		0x7E,
		0x7E,
		0x30,
		0x18,
		0x30,
		0x7E,
		0x00
	},
// X
	{
		0x00,
		0x62,
		0x76,
		0x1C,
		0x1C,
		0x76,
		0x62,
		0x00
	},
// Y
	{
		0x00,
		0x26,
		0x6E,
		0x48,
		0x48,
		0x7E,
		0x5E,
		0x00
	},
// Z
	{
		0x00,
		0x42,
		0x62,
		0x72,
		0x5A,
		0x4E,
		0x46,
		0x00
	},
// [
	{
		0x00,
		0x00,
		0x7E,
		0x7E,
		0x42,
		0x42,
		0x00,
		0x00
	},
// 
	{
		0x00,
		0x04,
		0x0C,
		0x18,
		0x30,
		0x60,
		0x40,
		0x00
	},
// ]
	{
		0x00,
		0x00,
		0x42,
		0x42,
		0x7E,
		0x7E,
		0x00,
		0x00
	},
// ^
	{
		0x00,
		0x08,
		0x04,
		0x02,
		0x04,
		0x08,
		0x00,
		0x00
	},
// _
	{
		0x00,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,
		0x80,
		0x00
	},
// `
	{
		0x00,
		0x00,
		0x00,
		0x02,
		0x06,
		0x04,
		0x00,
		0x00
	},
// a
	{
		0x00,
		0x20,
		0x74,
		0x54,
		0x54,
		0x7C,
		0x78,
		0x00
	},
// b
	{
		0x00,
		0x7E,
		0x7E,
		0x48,
		0x48,
		0x78,
		0x30,
		0x00
	},
// c
	{
		0x00,
		0x30,
		0x78,
		0x48,
		0x48,
		0x48,
		0x48,
		0x00
	},
// d
	{
		0x00,
		0x30,
		0x78,
		0x48,
		0x48,
		0x7E,
		0x7E,
		0x00
	},
// e
	{
		0x00,
		0x38,
		0x7C,
		0x54,
		0x54,
		0x5C,
		0x18,
		0x00
	},
// f
	{
		0x00,
		0x7C,
		0x7E,
		0x0A,
		0x02,
		0x06,
		0x04,
		0x00
	},
// g
	{
		0x00,
		0x10,
		0xB8,
		0xA8,
		0xA8,
		0xF8,
		0x50,
		0x00
	},
// h
	{
		0x00,
		0x7E,
		0x7E,
		0x08,
		0x08,
		0x78,
		0x70,
		0x00
	},
// i
	{
		0x00,
		0x00,
		0x00,
		0x7A,
		0x7A,
		0x00,
		0x00,
		0x00
	},
// j
	{
		0x00,
		0x40,
		0xC0,
		0x80,
		0x80,
		0xFA,
		0x7A,
		0x00
	},
// k
	{
		0x00,
		0x7E,
		0x7E,
		0x08,
		0x1C,
		0x74,
		0x60,
		0x00
	},
// l
	{
		0x00,
		0x00,
		0x00,
		0x7E,
		0x7E,
		0x00,
		0x00,
		0x00
	},
// m
	{
		0x00,
		0x70,
		0x78,
		0x08,
		0x10,
		0x08,
		0x70,
		0x00
	},
// n
	{
		0x00,
		0x78,
		0x78,
		0x08,
		0x08,
		0x78,
		0x70,
		0x00
	},
// o
	{
		0x00,
		0x30,
		0x78,
		0x48,
		0x48,
		0x78,
		0x30,
		0x00
	},
// p
	{
		0x00,
		0xF8,
		0xF8,
		0x28,
		0x28,
		0x38,
		0x10,
		0x00
	},
// q
	{
		0x00,
		0x10,
		0x38,
		0x28,
		0x28,
		0xf8,
		0xf8,
		0x80
	},
// r
	{
		0x00,
		0x78,
		0x78,
		0x08,
		0x08,
		0x18,
		0x20,
		0x00
	},
// s
	{
		0x00,
		0x08,
		0x5C,
		0x54,
		0x54,
		0x74,
		0x20,
		0x00
	},
// t
	{
		0x00,
		0x3E,
		0x7E,
		0x48,
		0x48,
		0x60,
		0x20,
		0x00
	},
// u
	{
		0x00,
		0x38,
		0x78,
		0x40,
		0x40,
		0x78,
		0x78,
		0x00
	},
// v
	{
		0x00,
		0x18,
		0x38,
		0x60,
		0x60,
		0x38,
		0x18,
		0x00
	},
// w
	{
		0x00,
		0x38,
		0x78,
		0x40,
		0x20,
		0x40,
		0x38,
		0x00
	},
// x
	{
		0x00,
		0x48,
		0x58,
		0x30,
		0x30,
		0x68,
		0x48,
		0x00
	},
// y
	{
		0x00,
		0x18,
		0xB8,
		0xA0,
		0xA0,
		0xF8,
		0x78,
		0x00
	},
// z
	{
		0x00,
		0x48,
		0x68,
		0x68,
		0x58,
		0x58,
		0x48,
		0x00
	},
// {
	{
		0x00,
		0x00,
		0x10,
		0x6C,
		0x82,
		0x82,
		0x00,
		0x00
	},
// |
	{
		0x00,
		0x00,
		0x00,
		0x7E,
		0x00,
		0x00,
		0x00,
		0x00
	},
// }
	{
		0x00,
		0x00,
		0x82,
		0x82,
		0x6C,
		0x10,
		0x00,
		0x00
	},
// ~
	{
		0x00,
		0x00,
		0x04,
		0x02,
		0x04,
		0x02,
		0x00,
		0x00
	}
};
