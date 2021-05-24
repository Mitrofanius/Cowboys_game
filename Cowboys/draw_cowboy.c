#include "draw_cowboy.h"

static unsigned short cowboy_aiming_left[] = {
    __NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,__NO__,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,C_SKIN,C_SKIN,C_SKIN,C_BLACK,C_BLACK,C_SKIN,C_SKIN,C_BLACK,C_BLACK,C_SKIN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_GRAY,__NO__,
    __NO__,__NO__,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_GRAY,C_LIGHT_GRAY,C_LIGHT_GRAY,C_LIGHT_GRAY,C_LIGHT_GRAY,C_GRAY,C_GRAY,C_GRAY,
    __NO__,__NO__,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_RED,C_RED,C_SKIN,C_SKIN,C_SKIN,C_GRAY,C_GRAY,C_GRAY,C_GRAY,C_BLACK,C_BLACK,C_BLACK,C_BLACK,
    __NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_WHITE,C_WHITE,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_SKIN,C_SKIN,C_GRAY,C_BLACK,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_WHITE,C_WHITE,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_SKIN,C_SKIN,C_BLACK,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_WHITE,C_WHITE,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,C_SKIN,C_SKIN,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,C_LIGHT_BLUE,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,C_SKIN,C_SKIN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,__NO__,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,C_BLACK,C_BLACK,__NO__,C_BLACK,C_BLACK,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__
};

void draw_cowboy(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, cowboy_t *cowboy, unsigned short scale)
{
    int i, j;

    for (i = 0; i < cowboy->height; i++)
    {
        for (j = 0; j < cowboy->width; j++)
        {
            if (cowboy_aiming_left[i * cowboy->width + j] != __NO__)
            {
                draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, cowboy_aiming_left[i * cowboy->width + j], scale);
            }
        }
    }
}
