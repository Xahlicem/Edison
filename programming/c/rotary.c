#include <stdlib.h>
#include <string.h>
#include "mraa.h"

mraa_gpio_context gpio1;
mraa_gpio_context gpio2;
mraa_pwm_context led;

volatile float value = 0.0;
volatile int prev = 0;
volatile int ticks = 0;
float rpm = 0;

void exec(void*);

int main(int argc, char** argv) {
    const char* board_name = mraa_get_platform_name();
    fprintf(stdout, "hello mraa\n Version: %s\n Running on %s\n", mraa_get_version(), board_name);
    mraa_deinit();
    gpio1 = mraa_gpio_init(2);
    gpio2 = mraa_gpio_init(3);
    led = mraa_pwm_init(5);
    mraa_pwm_period_us(led, 2000);
    mraa_pwm_enable(led, 1);

    system("/home/root/programming/c/ssd1306/bin/ssd1306 0");

    mraa_gpio_dir(gpio1, MRAA_GPIO_IN);
    mraa_gpio_dir(gpio2, MRAA_GPIO_IN);
    mraa_gpio_isr(gpio1, MRAA_GPIO_EDGE_BOTH, &exec, NULL);
    for (;;) {
        sleep(15);
	rpm = (float) ticks / 5.0;
	fprintf(stdout, "RPM: %f\n", rpm);
	ticks = 0;
    }
    mraa_gpio_close(gpio1);
    mraa_gpio_close(gpio2);

    return MRAA_SUCCESS;
}

void exec(void* args) {
	ticks++;

	int state1 = mraa_gpio_read(gpio1);
	int state2 = mraa_gpio_read(gpio2);

	if (!state1 && prev) {
		if (state2 == 1) value += 0.005;
		else  value -= 0.005;

		if (value < 0.0) value = 0.0;
		if (value > 0.2) value = 0.2;

		fprintf(stdout, "Value is %f\n", value);
		mraa_pwm_write(led, value);
		{
			char output[50], string[50];
			snprintf(output, 50, "%f", value);
			snprintf(string, 50, "/home/root/programming/c/ssd1306/bin/ssd1306 7 ");
			strcat(string, output);
			system(string);
		}
	}
	prev = state1;
}
