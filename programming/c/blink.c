#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "mraa/gpio.h"

int main(int argc, char** argv) {
    mraa_gpio_context gpio;
    int ledstate = 0;

    gpio = mraa_gpio_init(13);

    mraa_gpio_dir(gpio, MRAA_GPIO_OUT);

    for (;;) {
        ledstate = !ledstate;
        mraa_gpio_write(gpio, !ledstate);
        sleep(1);
    }

    return 0;
}
