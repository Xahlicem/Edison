#include <stdarg.h>

#define SSD1306_ADDR 0x3C

// Addresses
#define COMMAND 0x00
#define COMMAND_SINGLE 0x80
#define DATA 0x40

//========================COMMANDS==========================
// Charge Pump Commands
#define SET_CHARGE_PUMP 0x8D	// Must be enabled by 0x8D,0x14,0xAF
 #define CHARGE_PUMP_ON 0x14	// Enable Charge Pump
 #define CHARGE_PUMP_OFF 0x00	// Disable Charge Pump
// Fundamental Commands
#define SET_CONTRAST 0x81		// Followed by 0x00~0xff
#define ON_RESUME 0xA4		// Output follows RAM content
#define ON_IGNORE 0xA5		// Output ignores RAM content
#define DISPLAY_NORMAL 0xA6	// Normal display
#define DISPLAY_INVERSE 0xA7	// Inverse display
#define SLEEP 0xAE		// Display off (sleep)
#define ON 0xAF			// Display on
// Scrolling Commands
#define CONT_H_SCROLL_R 0x26	// Followed by 6 commands
#define CONT_H_SCROLL_L 0x27	// Followed by 6 commands
// 1: 0x00			   Dummy byte
// 2: 0x00~0x07			   Start page address
// 3: 0x00~0x07			   Time interval [5, 64, 128, 256, 3, 4, 25, 2]
// 4: 0x00~0x07			   End page address (>=Start)
// 5: 0x00			   Dummy byte
// 6: 0xff			   Dummy byte
#define CONT_VH_SCROLL_R 0x29	// Followed by 5 commands
#define CONT_VH_SCROLL_L 0x2A	// Followed by 5 commands
// 1: 0x00			   Dummy byte
// 2: 0x00~0x07			   Start page address
// 3: 0x00~0x07			   Time interval [5, 64, 128, 256, 3, 4, 25, 2]
// 4: 0x00~0x07			   End page address (>=Start)
// 5: 0x01~0x3f			   Vertical scrolling offest (1~63)
 #define SCROLL_INT_5 0x00
 #define SCROLL_INT_64 0x01
 #define SCROLL_INT_128 0x02
 #define SCROLL_INT_256 0x03
 #define SCROLL_INT_3 0x04
 #define SCROLL_INT_4 0x05
 #define SCROLL_INT_25 0x06
 #define SCROLL_INT_2 0x07
#define SCROLL_STOP 0x2E	// Deactivate scrolling
#define SCROLL_START 0x2F	// Activate scrolling
#define SET_V_SCROLL 0xA3	// Set vertical scroll area
// 1:
// 2:
// Address Setting Commands
// For column lower nibble (page address mode)
 #define SET_L_COL_ADDR_0 0x00
 #define SET_L_COL_ADDR_1 0x01
 #define SET_L_COL_ADDR_2 0x02
 #define SET_L_COL_ADDR_3 0x03
 #define SET_L_COL_ADDR_4 0x04
 #define SET_L_COL_ADDR_5 0x05
 #define SET_L_COL_ADDR_6 0x06
 #define SET_L_COL_ADDR_7 0x07
 #define SET_L_COL_ADDR_8 0x08
 #define SET_L_COL_ADDR_9 0x09
 #define SET_L_COL_ADDR_A 0x0A
 #define SET_L_COL_ADDR_B 0x0B
 #define SET_L_COL_ADDR_C 0x0C
 #define SET_L_COL_ADDR_D 0x0D
 #define SET_L_COL_ADDR_E 0x0E
 #define SET_L_COL_ADDR_F 0x0F
// Set column higher nibble (page address mode)
 #define SET_H_COL_ADDR_0 0x10
 #define SET_H_COL_ADDR_1 0x11
 #define SET_H_COL_ADDR_2 0x12
 #define SET_H_COL_ADDR_3 0x13
 #define SET_H_COL_ADDR_4 0x14
 #define SET_H_COL_ADDR_5 0x15
 #define SET_H_COL_ADDR_6 0x16
 #define SET_H_COL_ADDR_7 0x17
 #define SET_H_COL_ADDR_8 0x18
 #define SET_H_COL_ADDR_9 0x19
 #define SET_H_COL_ADDR_A 0x1A
 #define SET_H_COL_ADDR_B 0x1B
 #define SET_H_COL_ADDR_C 0x1C
 #define SET_H_COL_ADDR_D 0x1D
 #define SET_H_COL_ADDR_E 0x1E
 #define SET_H_COL_ADDR_F 0x1F
#define SET_MEM_MODE 0x20	// Followed by a MEM_MODE
 #define MEM_MODE_HOR 0x00	// Horizontal address mode
 #define MEM_MODE_VER 0x01	// Vertical address mode
 #define MEM_MODE_PAGE 0x02	// Page address mode
#define SET_COL_ADDR 0x21	// Followed by 2 commands
// 1: 0x00~0x7F			   Column start address
// 2: 0x00~0x7F			   Column end address
#define SET_PAGE_ADDR 0x22	// Followed by 2 commands
// 1: 0x00~0x07			   Page start address
// 2: 0x00~0x07			   Page end address
// Set Page start address (page address mode)
 #define SET_START_PAGE_0 0xB0
 #define SET_START_PAGE_1 0xB1
 #define SET_START_PAGE_2 0xB2
 #define SET_START_PAGE_3 0xB3
 #define SET_START_PAGE_4 0xB4
 #define SET_START_PAGE_5 0xB5
 #define SET_START_PAGE_6 0xB6
 #define SET_START_PAGE_7 0xB7
// Hardware Commands
#define SET_START_LINE 0x40	// Set display ram start line 0x40~ox7F
#define SET_SEG_REMAP 0xA0	// Column address 0 is mapped to SEG0
#define SET_SEG_REMAP_ALT 0xA1	// Column address 127 is mapped to SEG0
#define SET_MUX_RATIO 0xA8	// Set MUX ratio N + 1 MUX
// N: 0x0F~0x3F
#define SET_COM_SCAN 0xC0	// Scan from COM0 to COM[N-1]
#define SET_COM_SCAN_ALT 0xC8	// Scan from COM[N-1] to COM0
#define SET_OFFSET 0xD3		// Set vertical shift
// 1: 0x00~0x3F
#define SET_COM_PIN_CONF 0xDA	// Set COM pins hardware configuration
 #define COM_PIN_SEQ 0x02	// Sequential pin configuration
 #define COM_PIN_SEQ_REMAP 0x22	// Sequential pin with left/right remap
 #define COM_PIN_ALT 0x12	// Alternating pin configuration
 #define COM_PIN_ALT_REMAP 0x32	// Alternating pin with left/right remap
// Timing/Driving Commands
#define SET_DIVRAT_OSCFREQ 0xD5	// Set display clock divide ratio/oscillator frequency
// 1: 0x00~0xFF	0x*0~0x*F=ratio 0x0*~0xF*=frequency
#define SET_PRECHARGE 0xD9	// Set Precharge Period phase 1/phase 2
// 1: 0x00~0xFF	0x*0~0x*F=phase 1 0x0*~0xF*=phase 2
#define SET_VCOM_D_LVL 0xDB	// Set Vcomh deslect level
 #define VCOM_D_LVL_65 0x00
 #define VCOM_D_LVL_77 0x20
 #define VCOM_D_LVL_83 0x30
#define NOP 0xE3		// No operation command

//==========================================================

uint8_t startPage[] = {
	SET_START_PAGE_0,
        SET_START_PAGE_1,
        SET_START_PAGE_2,
        SET_START_PAGE_3,
        SET_START_PAGE_4,
        SET_START_PAGE_5,
        SET_START_PAGE_6,
        SET_START_PAGE_7
};

uint8_t startLCol[] = {
	SET_L_COL_ADDR_0,
        SET_L_COL_ADDR_1,
        SET_L_COL_ADDR_2,
        SET_L_COL_ADDR_3,
        SET_L_COL_ADDR_4,
        SET_L_COL_ADDR_5,
        SET_L_COL_ADDR_6,
        SET_L_COL_ADDR_7,
        SET_L_COL_ADDR_8,
        SET_L_COL_ADDR_9,
        SET_L_COL_ADDR_A,
        SET_L_COL_ADDR_B,
        SET_L_COL_ADDR_C,
        SET_L_COL_ADDR_D,
        SET_L_COL_ADDR_E,
        SET_L_COL_ADDR_F
};

uint8_t startHCol[] = {
        SET_H_COL_ADDR_0,
        SET_H_COL_ADDR_1,
        SET_H_COL_ADDR_2,
        SET_H_COL_ADDR_3,
        SET_H_COL_ADDR_4,
        SET_H_COL_ADDR_5,
        SET_H_COL_ADDR_6,
        SET_H_COL_ADDR_7,
        SET_H_COL_ADDR_8,
        SET_H_COL_ADDR_9,
        SET_H_COL_ADDR_A,
        SET_H_COL_ADDR_B,
        SET_H_COL_ADDR_C,
        SET_H_COL_ADDR_D,
        SET_H_COL_ADDR_E,
        SET_H_COL_ADDR_F
};

typedef struct data_t {
	int length;
	uint8_t data[];
} data_t;

data_t ssd1306_init = {18, {
	COMMAND,
	SET_MUX_RATIO, 0x3F,
	SET_OFFSET, 0x00,
	SET_START_LINE,
	SET_SEG_REMAP,
	SET_COM_SCAN,
	SET_COM_PIN_CONF, COM_PIN_ALT,
	SET_CONTRAST, 0x20,
	ON_RESUME,
	DISPLAY_NORMAL,
	SET_DIVRAT_OSCFREQ, 0x80,
	SET_CHARGE_PUMP, CHARGE_PUMP_ON
}};

data_t ssd1306_setHorMode = {3, {
	COMMAND,
	SET_MEM_MODE,
	MEM_MODE_HOR
}};

data_t ssd1306_setVerMode = {3, {
	COMMAND,
	SET_MEM_MODE,
	MEM_MODE_VER
}};

data_t ssd1306_setPageMode = {3, {
	COMMAND,
	SET_MEM_MODE,
	MEM_MODE_PAGE
}};

data_t ssd1306_flip = {3, {
	COMMAND,
	SET_SEG_REMAP_ALT,
	SET_COM_SCAN_ALT
}};

data_t ssd1306_cursor_reset = {4, {
	COMMAND,
	SET_START_PAGE_0,
	SET_L_COL_ADDR_0,
	SET_H_COL_ADDR_0
}};

data_t * ssd1306_setCursor(int x, int y) {
	uint8_t commands[4];
	commands[0] = COMMAND;
	if (y > 7 || y < 0) commands[3] = startPage[0];
	else commands[3] = startPage[y];
	if (x > 127 || x < 0) {
		commands[1] = startLCol[0];
		commands[2] = startHCol[0];
	} else {
		int x1 = x & 0x0F;
		int x2 = (x & 0xF0) >> 4;
		commands[1] = startLCol[x1];
		commands[2] = startHCol[x2];
	}
	data_t *r;
	r = (data_t *) malloc(sizeof(data_t) + 1 * sizeof(int) + 4 * sizeof(uint8_t));
	if (r == NULL)
		return NULL;
	r->length = 4;
	int i;
	for (i = 0; i < 4; i++)
		r->data[i] = commands[i];
	return r;
}

