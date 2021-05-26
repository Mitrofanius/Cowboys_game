#include "draw.h"

unsigned short cowboy_aiming_left[] = {
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_BLACK, C_BLACK, C_SKIN, C_SKIN, C_BLACK, C_BLACK, C_SKIN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_GRAY, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_GRAY, C_GRAY, C_GRAY,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_RED, C_RED, C_SKIN, C_SKIN, C_SKIN, C_GRAY, C_GRAY, C_GRAY, C_GRAY, C_BLACK, C_BLACK, C_BLACK, C_BLACK,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_GRAY, C_BLACK, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_BLACK, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BLACK, C_BLACK, __NO__, C_BLACK, C_BLACK, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__
};

unsigned short cowboy_aiming_right[] = {
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,__NO__,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,__NO__,__NO__,
    __NO__,C_GRAY,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_SKIN,C_BLACK,C_BLACK,C_SKIN,C_SKIN,C_BLACK,C_BLACK,C_SKIN,C_SKIN,C_SKIN,__NO__,__NO__,
    C_GRAY,C_GRAY,C_GRAY,C_LIGHT_GRAY,C_LIGHT_GRAY,C_LIGHT_GRAY,C_LIGHT_GRAY,C_GRAY,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,__NO__,__NO__,
    C_BLACK,C_BLACK,C_BLACK,C_BLACK,C_GRAY,C_GRAY,C_GRAY,C_GRAY,C_SKIN,C_SKIN,C_SKIN,C_RED,C_RED,C_SKIN,C_SKIN,C_SKIN,C_SKIN,C_SKIN,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,C_BLACK,C_GRAY,C_SKIN,C_SKIN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_WHITE,C_WHITE,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,C_BLACK,C_SKIN,C_SKIN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_WHITE,C_WHITE,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_WHITE,C_WHITE,C_BROWN,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,NOT_SPECIFIED,C_SKIN,C_SKIN,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_BROWN,C_SKIN,C_SKIN,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BROWN,C_BROWN,__NO__,C_BROWN,C_BROWN,__NO__,__NO__,__NO__,__NO__,
    __NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,__NO__,C_BLACK,C_BLACK,__NO__,C_BLACK,C_BLACK,__NO__,__NO__,__NO__,__NO__
};


void draw_cowboy(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, cowboy_t *cowboy, unsigned short scale)
{
    int i, j;

    for (i = 0; i < cowboy->height; i++)
    {
        for (j = 0; j < cowboy->width; j++)
        {
            if (cowboy->side == LEFT && cowboy->state == AIMING)
            {
                if (cowboy_aiming_left[i * cowboy->width + j] == NOT_SPECIFIED)
                {
                    draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, scale, cowboy->colour);
                }
                else if (cowboy_aiming_left[i * cowboy->width + j] != __NO__)
                {
                    draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, scale, cowboy_aiming_left[i * cowboy->width + j]);
                }
            }
            else if (cowboy->side == LEFT && cowboy->state == RUNNING)
            {

            }
            else if (cowboy->side == LEFT && cowboy->state == DEAD)
            {

            }
            else if (cowboy->side == RIGHT && cowboy->state == AIMING)
            {
                if (cowboy_aiming_right[i * cowboy->width + j] == NOT_SPECIFIED)
                {
                    draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, scale, cowboy->colour);
                }
                else if (cowboy_aiming_right[i * cowboy->width + j] != __NO__)
                {
                    draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, scale, cowboy_aiming_right[i * cowboy->width + j]);
                }
            }
            else if (cowboy->side == RIGHT && cowboy->state == RUNNING)
            {

            }
            else if (cowboy->side == RIGHT && cowboy->state == DEAD)
            {

            }
        }
    }
}
