{"filter":false,"title":"icon.h","tooltip":"/c/ssd1306/icon.h","undoManager":{"mark":0,"position":0,"stack":[[{"start":{"row":0,"column":0},"end":{"row":1047,"column":0},"action":"remove","lines":["uint8_t font[][8] = {","// Space","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// !","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x5E,","\t\t0x5E,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// \"","\t{","\t\t0x00,","\t\t0x06,","\t\t0x0E,","\t\t0x00,","\t\t0x06,","\t\t0x0E,","\t\t0x00,","\t\t0x00","\t},","// #","\t{","\t\t0x24,","\t\t0x7E,","\t\t0x7E,","\t\t0x24,","\t\t0x7E,","\t\t0x7E,","\t\t0x24,","\t\t0x00","\t},","// $","\t{","\t\t0x00,","\t\t0x08,","\t\t0x64,","\t\t0x7E,","\t\t0x7E,","\t\t0x64,","\t\t0x40,","\t\t0x00","\t},","// %","\t{","\t\t0x00,","\t\t0x46,","\t\t0x26,","\t\t0x10,","\t\t0x08,","\t\t0x64,","\t\t0x62,","\t\t0x00","\t},","// &","\t{","\t\t0x00,","\t\t0x34,","\t\t0x7E,","\t\t0x4A,","\t\t0x5A,","\t\t0x6A,","\t\t0x24,","\t\t0x00","\t},","// '","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x06,","\t\t0x0E,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// (","\t{","\t\t0x00,","\t\t0x00,","\t\t0x18,","\t\t0x3C,","\t\t0x66,","\t\t0x42,","\t\t0x00,","\t\t0x00","\t},","// )","\t{","\t\t0x00,","\t\t0x00,","\t\t0x42,","\t\t0x66,","\t\t0x3C,","\t\t0x18,","\t\t0x00,","\t\t0x00","\t},","// *","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x14,","\t\t0x0E,","\t\t0x14,","\t\t0x00,","\t\t0x00","\t},","// +","\t{","\t\t0x00,","\t\t0x00,","\t\t0x10,","\t\t0x7C,","\t\t0x7C,","\t\t0x10,","\t\t0x00,","\t\t0x00","\t},","// ,","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x60,","\t\t0xE0,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// -","\t{","\t\t0x00,","\t\t0x00,","\t\t0x10,","\t\t0x10,","\t\t0x10,","\t\t0x10,","\t\t0x00,","\t\t0x00","\t},","// .","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x60,","\t\t0x60,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// /","\t{","\t\t0x00,","\t\t0x40,","\t\t0x60,","\t\t0x30,","\t\t0x18,","\t\t0x0C,","\t\t0x04,","\t\t0x00","\t},","// 0","\t{","\t\t0x00,","\t\t0x3C,","\t\t0x7E,","\t\t0x52,","\t\t0x4A,","\t\t0x7E,","\t\t0x3C,","\t\t0x00","\t},","// 1","\t{","\t\t0x00,","\t\t0x00,","\t\t0x44,","\t\t0x7E,","\t\t0x7E,","\t\t0x40,","\t\t0x00,","\t\t0x00","\t},","// 2","\t{","\t\t0x00,","\t\t0x44,","\t\t0x66,","\t\t0x72,","\t\t0x52,","\t\t0x5E,","\t\t0x4C,","\t\t0x00","\t},","// 3","\t{","\t\t0x00,","\t\t0x24,","\t\t0x66,","\t\t0x42,","\t\t0x4A,","\t\t0x7E,","\t\t0x34,","\t\t0x00","\t},","// 4","\t{","\t\t0x00,","\t\t0x30,","\t\t0x38,","\t\t0x2C,","\t\t0x7E,","\t\t0x7E,","\t\t0x20,","\t\t0x00","\t},","// 5","\t{","\t\t0x00,","\t\t0x2E,","\t\t0x6E,","\t\t0x4A,","\t\t0x4A,","\t\t0x7A,","\t\t0x32,","\t\t0x00","\t},","// 6","\t{","\t\t0x00,","\t\t0x3C,","\t\t0x7E,","\t\t0x4A,","\t\t0x4A,","\t\t0x7A,","\t\t0x30,","\t\t0x00","\t},","// 7","\t{","\t\t0x00,","\t\t0x02,","\t\t0x62,","\t\t0x72,","\t\t0x1A,","\t\t0x0E,","\t\t0x06,","\t\t0x00","\t},","// 8","\t{","\t\t0x00,","\t\t0x34,","\t\t0x7E,","\t\t0x4A,","\t\t0x4A,","\t\t0x7E,","\t\t0x34,","\t\t0x00","\t},","// 9","\t{","\t\t0x00,","\t\t0x24,","\t\t0x6E,","\t\t0x4A,","\t\t0x4A,","\t\t0x7E,","\t\t0x3C,","\t\t0x00","\t},","// :","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x66,","\t\t0x66,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// ;","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x66,","\t\t0xE6,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// <","\t{","\t\t0x00,","\t\t0x00,","\t\t0x10,","\t\t0x38,","\t\t0x6C,","\t\t0x44,","\t\t0x00,","\t\t0x00","\t},","// =","\t{","\t\t0x00,","\t\t0x00,","\t\t0x28,","\t\t0x28,","\t\t0x28,","\t\t0x28,","\t\t0x00,","\t\t0x00","\t},","// >","\t{","\t\t0x00,","\t\t0x00,","\t\t0x44,","\t\t0x6C,","\t\t0x38,","\t\t0x10,","\t\t0x00,","\t\t0x00","\t},","// ?","\t{","\t\t0x00,","\t\t0x04,","\t\t0x06,","\t\t0x52,","\t\t0x5A,","\t\t0x0E,","\t\t0x04,","\t\t0x00","\t},","// @","\t{","\t\t0x00,","\t\t0x3C,","\t\t0x42,","\t\t0x5A,","\t\t0x5A,","\t\t0x52,","\t\t0x0C,","\t\t0x00","\t},","// A","\t{","\t\t0x00,","\t\t0x7C,","\t\t0x7E,","\t\t0x0A,","\t\t0x0A,","\t\t0x7E,","\t\t0x7C,","\t\t0x00","\t},","// B","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x4A,","\t\t0x4A,","\t\t0x7E,","\t\t0x34,","\t\t0x00","\t},","// C","\t{","\t\t0x00,","\t\t0x3C,","\t\t0x7E,","\t\t0x42,","\t\t0x42,","\t\t0x66,","\t\t0x24,","\t\t0x00","\t},","// D","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x42,","\t\t0x42,","\t\t0x7E,","\t\t0x3C,","\t\t0x00","\t},","// E","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x4A,","\t\t0x4A,","\t\t0x42,","\t\t0x42,","\t\t0x00","\t},","// F","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x0A,","\t\t0x0A,","\t\t0x02,","\t\t0x02,","\t\t0x00","\t},","// G","\t{","\t\t0x00,","\t\t0x3C,","\t\t0x7E,","\t\t0x42,","\t\t0x52,","\t\t0x76,","\t\t0x74,","\t\t0x00","\t},","// H","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x08,","\t\t0x08,","\t\t0x7E,","\t\t0x7E,","\t\t0x00","\t},","// I","\t{","\t\t0x00,","\t\t0x42,","\t\t0x42,","\t\t0x7E,","\t\t0x7E,","\t\t0x42,","\t\t0x42,","\t\t0x00","\t},","// J","\t{","\t\t0x00,","\t\t0x20,","\t\t0x60,","\t\t0x42,","\t\t0x42,","\t\t0x7E,","\t\t0x3E,","\t\t0x00","\t},","// K","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x08,","\t\t0x1C,","\t\t0x76,","\t\t0x62,","\t\t0x00","\t},","// L","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x40,","\t\t0x40,","\t\t0x40,","\t\t0x40,","\t\t0x00","\t},","// M","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x0C,","\t\t0x18,","\t\t0x0C,","\t\t0x7E,","\t\t0x00","\t},","// N","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x0C,","\t\t0x18,","\t\t0x7E,","\t\t0x7E,","\t\t0x00","\t},","// O","\t{","\t\t0x00,","\t\t0x3C,","\t\t0x7E,","\t\t0x42,","\t\t0x42,","\t\t0x7E,","\t\t0x3C,","\t\t0x00","\t},","// P","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x0A,","\t\t0x0A,","\t\t0x0E,","\t\t0x04,","\t\t0x00","\t},","// Q","\t{","\t\t0x00,","\t\t0x3C,","\t\t0x7E,","\t\t0x42,","\t\t0x62,","\t\t0x7E,","\t\t0x7C,","\t\t0x00","\t},","// R","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x0A,","\t\t0x0A,","\t\t0x7E,","\t\t0x74,","\t\t0x00","\t},","// S","\t{","\t\t0x00,","\t\t0x24,","\t\t0x6E,","\t\t0x4A,","\t\t0x4A,","\t\t0x7A,","\t\t0x30,","\t\t0x00","\t},","// T","\t{","\t\t0x00,","\t\t0x02,","\t\t0x02,","\t\t0x7E,","\t\t0x7E,","\t\t0x02,","\t\t0x02,","\t\t0x00","\t},","// U","\t{","\t\t0x00,","\t\t0x5E,","\t\t0x7E,","\t\t0x40,","\t\t0x40,","\t\t0x7E,","\t\t0x7E,","\t\t0x00","\t},","// V","\t{","\t\t0x00,","\t\t0x1E,","\t\t0x3E,","\t\t0x60,","\t\t0x60,","\t\t0x3E,","\t\t0x1E,","\t\t0x00","\t},","// W","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x30,","\t\t0x18,","\t\t0x30,","\t\t0x7E,","\t\t0x00","\t},","// X","\t{","\t\t0x00,","\t\t0x62,","\t\t0x76,","\t\t0x1C,","\t\t0x1C,","\t\t0x76,","\t\t0x62,","\t\t0x00","\t},","// Y","\t{","\t\t0x00,","\t\t0x26,","\t\t0x6E,","\t\t0x48,","\t\t0x48,","\t\t0x7E,","\t\t0x5E,","\t\t0x00","\t},","// Z","\t{","\t\t0x00,","\t\t0x42,","\t\t0x62,","\t\t0x72,","\t\t0x5A,","\t\t0x4E,","\t\t0x46,","\t\t0x00","\t},","// [","\t{","\t\t0x00,","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x42,","\t\t0x42,","\t\t0x00,","\t\t0x00","\t},","// ","\t{","\t\t0x00,","\t\t0x04,","\t\t0x0C,","\t\t0x18,","\t\t0x30,","\t\t0x60,","\t\t0x40,","\t\t0x00","\t},","// ]","\t{","\t\t0x00,","\t\t0x00,","\t\t0x42,","\t\t0x42,","\t\t0x7E,","\t\t0x7E,","\t\t0x00,","\t\t0x00","\t},","// ^","\t{","\t\t0x00,","\t\t0x08,","\t\t0x04,","\t\t0x02,","\t\t0x04,","\t\t0x08,","\t\t0x00,","\t\t0x00","\t},","// _","\t{","\t\t0x00,","\t\t0x80,","\t\t0x80,","\t\t0x80,","\t\t0x80,","\t\t0x80,","\t\t0x80,","\t\t0x00","\t},","// `","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x02,","\t\t0x06,","\t\t0x04,","\t\t0x00,","\t\t0x00","\t},","// a","\t{","\t\t0x00,","\t\t0x20,","\t\t0x74,","\t\t0x54,","\t\t0x54,","\t\t0x7C,","\t\t0x78,","\t\t0x00","\t},","// b","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x48,","\t\t0x48,","\t\t0x78,","\t\t0x30,","\t\t0x00","\t},","// c","\t{","\t\t0x00,","\t\t0x30,","\t\t0x78,","\t\t0x48,","\t\t0x48,","\t\t0x48,","\t\t0x48,","\t\t0x00","\t},","// d","\t{","\t\t0x00,","\t\t0x30,","\t\t0x78,","\t\t0x48,","\t\t0x48,","\t\t0x7E,","\t\t0x7E,","\t\t0x00","\t},","// e","\t{","\t\t0x00,","\t\t0x38,","\t\t0x7C,","\t\t0x54,","\t\t0x54,","\t\t0x5C,","\t\t0x18,","\t\t0x00","\t},","// f","\t{","\t\t0x00,","\t\t0x7C,","\t\t0x7E,","\t\t0x0A,","\t\t0x02,","\t\t0x06,","\t\t0x04,","\t\t0x00","\t},","// g","\t{","\t\t0x00,","\t\t0x10,","\t\t0xB8,","\t\t0xA8,","\t\t0xA8,","\t\t0xF8,","\t\t0x50,","\t\t0x00","\t},","// h","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x08,","\t\t0x08,","\t\t0x78,","\t\t0x70,","\t\t0x00","\t},","// i","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x7A,","\t\t0x7A,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// j","\t{","\t\t0x00,","\t\t0x40,","\t\t0xC0,","\t\t0x80,","\t\t0x80,","\t\t0xFA,","\t\t0x7A,","\t\t0x00","\t},","// k","\t{","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x08,","\t\t0x1C,","\t\t0x74,","\t\t0x60,","\t\t0x00","\t},","// l","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x7E,","\t\t0x7E,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// m","\t{","\t\t0x00,","\t\t0x70,","\t\t0x78,","\t\t0x08,","\t\t0x10,","\t\t0x08,","\t\t0x70,","\t\t0x00","\t},","// n","\t{","\t\t0x00,","\t\t0x78,","\t\t0x78,","\t\t0x08,","\t\t0x08,","\t\t0x78,","\t\t0x70,","\t\t0x00","\t},","// o","\t{","\t\t0x00,","\t\t0x30,","\t\t0x78,","\t\t0x48,","\t\t0x48,","\t\t0x78,","\t\t0x30,","\t\t0x00","\t},","// p","\t{","\t\t0x00,","\t\t0xF8,","\t\t0xF8,","\t\t0x28,","\t\t0x28,","\t\t0x38,","\t\t0x10,","\t\t0x00","\t},","// q","\t{","\t\t0x00,","\t\t0x10,","\t\t0x38,","\t\t0x28,","\t\t0x28,","\t\t0xf8,","\t\t0xf8,","\t\t0x80","\t},","// r","\t{","\t\t0x00,","\t\t0x78,","\t\t0x78,","\t\t0x08,","\t\t0x08,","\t\t0x18,","\t\t0x20,","\t\t0x00","\t},","// s","\t{","\t\t0x00,","\t\t0x08,","\t\t0x5C,","\t\t0x54,","\t\t0x54,","\t\t0x74,","\t\t0x20,","\t\t0x00","\t},","// t","\t{","\t\t0x00,","\t\t0x3E,","\t\t0x7E,","\t\t0x48,","\t\t0x48,","\t\t0x60,","\t\t0x20,","\t\t0x00","\t},","// u","\t{","\t\t0x00,","\t\t0x38,","\t\t0x78,","\t\t0x40,","\t\t0x40,","\t\t0x78,","\t\t0x78,","\t\t0x00","\t},","// v","\t{","\t\t0x00,","\t\t0x18,","\t\t0x38,","\t\t0x60,","\t\t0x60,","\t\t0x38,","\t\t0x18,","\t\t0x00","\t},","// w","\t{","\t\t0x00,","\t\t0x38,","\t\t0x78,","\t\t0x40,","\t\t0x20,","\t\t0x40,","\t\t0x38,","\t\t0x00","\t},","// x","\t{","\t\t0x00,","\t\t0x48,","\t\t0x58,","\t\t0x30,","\t\t0x30,","\t\t0x68,","\t\t0x48,","\t\t0x00","\t},","// y","\t{","\t\t0x00,","\t\t0x18,","\t\t0xB8,","\t\t0xA0,","\t\t0xA0,","\t\t0xF8,","\t\t0x78,","\t\t0x00","\t},","// z","\t{","\t\t0x00,","\t\t0x48,","\t\t0x68,","\t\t0x68,","\t\t0x58,","\t\t0x58,","\t\t0x48,","\t\t0x00","\t},","// {","\t{","\t\t0x00,","\t\t0x00,","\t\t0x10,","\t\t0x6C,","\t\t0x82,","\t\t0x82,","\t\t0x00,","\t\t0x00","\t},","// |","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x7E,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// }","\t{","\t\t0x00,","\t\t0x00,","\t\t0x82,","\t\t0x82,","\t\t0x6C,","\t\t0x10,","\t\t0x00,","\t\t0x00","\t},","// ~","\t{","\t\t0x00,","\t\t0x00,","\t\t0x04,","\t\t0x02,","\t\t0x04,","\t\t0x02,","\t\t0x00,","\t\t0x00","\t}","};",""]},{"start":{"row":0,"column":0},"end":{"row":208,"column":0},"action":"insert","lines":["uint8_t logo[][8] = {","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t}, {","\t\t0x00,","\t\t0x80,","\t\t0x80,","\t\t0xC0,","\t\t0xC0,","\t\t0xC0,","\t\t0xC0,","\t\t0xC0","\t}, {","\t\t0xE0,","\t\t0xE0,","\t\t0xE0,","\t\t0xE0,","\t\t0xE0,","\t\t0xE0,","\t\t0xE0,","\t\t0xE0","\t}, {","\t\t0xC0,","\t\t0xC0,","\t\t0xC0,","\t\t0x80,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","\t{","\t\t0x00,","\t\t0xE0,","\t\t0xF0,","\t\t0x10,","\t\t0x00,","\t\t0xEC,","\t\t0xEC,","\t\t0x00","\t}, {","\t\t0xE3,","\t\t0x61,","\t\t0x61,","\t\t0xC0,","\t\t0x00,","\t\t0xF0,","\t\t0xF0,","\t\t0x60","\t}, {","\t\t0x00,","\t\t0x80,","\t\t0xC0,","\t\t0x60,","\t\t0x60,","\t\t0xC0,","\t\t0x80,","\t\t0x00","\t}, {","\t\t0xF9,","\t\t0xF9,","\t\t0x03,","\t\t0x07,","\t\t0x07,","\t\t0x9E,","\t\t0xFC,","\t\t0xF0","\t},","\t{","\t\t0x0F,","\t\t0x7F,","\t\t0xFF,","\t\t0xE0,","\t\t0xC0,","\t\t0x8F,","\t\t0x8F,","\t\t0x80","\t}, {","\t\t0x0F,","\t\t0x00,","\t\t0x00,","\t\t0x0F,","\t\t0x00,","\t\t0x0F,","\t\t0x0F,","\t\t0x08","\t}, {","\t\t0x00,","\t\t0x07,","\t\t0x07,","\t\t0x07,","\t\t0x89,","\t\t0x89,","\t\t0x81,","\t\t0x80","\t}, {","\t\t0xCF,","\t\t0xCF,","\t\t0x00,","\t\t0x1C,","\t\t0x1E,","\t\t0x0F,","\t\t0x03,","\t\t0x01","\t},","\t{","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x01,","\t\t0x03,","\t\t0x03,","\t\t0x03","\t}, {","\t\t0x03,","\t\t0x07,","\t\t0x07,","\t\t0x07,","\t\t0x07,","\t\t0x07,","\t\t0x07,","\t\t0x07","\t}, {","\t\t0x07,","\t\t0x07,","\t\t0x07,","\t\t0x07,","\t\t0x03,","\t\t0x03,","\t\t0x03,","\t\t0x03","\t}, {","\t\t0x01,","\t\t0x01,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t}","};","","uint8_t signalIcon[][8] = {","// No Signal","\t{","\t\t0x00,","                0x00,","                0x00,","                0x00,","                0x00,","                0x00,","                0x00,","\t\t0x00","\t},","// Signal 1","\t{","\t\t0xC0,","\t\t0xC0,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00,","\t\t0x00","\t},","// Signal 2","\t{","                0xC0,","                0xD0,","                0x10,","                0x60,","                0x00,","                0x00,","                0x00,","                0x00","        },","// Signal 3","\t{","                0xC0,","                0xD4,","                0x14,","                0x64,","                0x0C,","                0x78,","                0x00,","                0x00","        },","// Signal 4","\t{","                0xC0,","                0xD5,","                0x15,","                0x65,","                0x0D,","                0x79,","                0x03,","                0x7E","        }","};",""]}]]},"ace":{"folds":[{"start":{"row":0,"column":21},"end":{"row":149,"column":0},"placeholder":"..."},{"start":{"row":151,"column":27},"end":{"row":207,"column":0},"placeholder":"..."}],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":208,"column":0},"end":{"row":208,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1476999476610,"hash":"35e80f6ecb222a4621ae4166c0288068cb338316"}