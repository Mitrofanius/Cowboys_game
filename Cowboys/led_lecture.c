#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include <time.h>

unsigned int hsv2rgb(int hue, int saturation, int value);

// main to light
// int main()
// {
//     unsigned char *mem_base; // dolu - zacatek sdilene fyzicke pameti
//     mem_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
//     // if mapping fails exit eith error code
//     if (mem_base == NULL)
//         exit(1);

//     // dolu - offset rgb1 ledky uvnitr bloku sdilene pameti
//     *(volatile uint32_t *)(mem_base + SPILED_REG_LED_RGB1_o) = 0xff00ff;
//     *(volatile uint32_t *)(mem_base + SPILED_REG_LED_RGB2_o) = 0x00ff00;

//     return 0;
// }

// main to blink
int main()
{
    unsigned char *mem_base; // dolu - zacatek sdilene fyzicke pameti
    mem_base = map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);
    // if mapping fails exit eith error code
    if (mem_base == NULL)
        exit(1);

    struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = 20 * 1000 * 1000};
    int hue, sat = 256, val = 10;
    for (hue = 0; hue < 360; hue += 15)
    {
        for (val = 90; val >= 0; val -= 3)
        {
            uint32_t col = hsv2rgb(hue, sat, val);
            *(volatile uint32_t *)(mem_base + SPILED_REG_LED_RGB1_o) = col;
            clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
        }
    }

    return 0;
}

unsigned int hsv2rgb(int hue, int saturation, int value)
{
    hue = (hue % 360);
    float f = ((hue % 60) / 60.0);
    int p = (value * (255 - saturation)) / 255;
    int q = (value * (255 - (saturation * f))) / 255;
    int t = (value * (255 - (saturation * (1.0 - f)))) / 255;

    unsigned int r, g, b;

    if (hue < 60)
    {
        r = value;
        g = t;
        b = p;
    }
    else if (hue < 120)
    {
        r = q;
        g = value;
        b = p;
    }
    else if (hue < 180)
    {
        r = p;
        g = value;
        b = t;
    }
    else if (hue < 240)
    {
        r = p;
        g = q;
        b = value;
    }
    else if (hue < 300)
    {
        r = t;
        g = p;
        b = value;
    }
    else
    {
        r = value;
        g = p;
        b = q;
    }

    return ((r << 16) | (g << 8) | b);
}