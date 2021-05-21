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

unsigned int hsv2rgb_lcd(int hue, int saturation, int value);

int main(int argc, char *argv[])
{
    unsigned char *parlcd_mem_base;
    printf("Hello\n");
    parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);

    if (parlcd_mem_base == NULL)
        exit(1);

    parlcd_hx8357_init(parlcd_mem_base);
    parlcd_write_cmd(parlcd_mem_base, 0x2c);

    for (int i = 0; i < 320; i++)
    {
        for (int j = 0; j < 480; j++)
        {
            parlcd_write_data(parlcd_mem_base, hsv2rgb_lcd(j, 255, (i * 255) / 320));
        }
    }
    printf("Goodbye");
}

unsigned int hsv2rgb_lcd(int hue, int saturation, int value)
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

    r >>= 3;
    g >>= 2;
    b >>= 3;

    return (((r & 0x1f) << 11) | ((g & 0x3f) << 5) | (b & 0x1f));
}