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
    __NO__, __NO__, __NO__, __NO__, C_BLACK, C_BLACK, __NO__, C_BLACK, C_BLACK, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__};

unsigned short cowboy_running_left[] = {
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BLACK, C_SKIN, C_SKIN, C_BLACK, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_RED, C_RED, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, C_SKIN, C_SKIN, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BLACK, C_BLACK, __NO__, C_BLACK, C_BLACK, __NO__, __NO__, __NO__, __NO__, __NO__};

unsigned short cowboy_dead_left[] = {
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__, __NO__, C_SKIN, C_SKIN, __NO__, __NO__, __NO__,
    __NO__, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_BLACK, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, __NO__, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_RED, C_BROWN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BLACK, __NO__,
    C_BROWN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_RED, C_WHITE, C_WHITE, C_WHITE, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BLACK, __NO__,
    __NO__, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_BLACK, C_SKIN, C_SKIN, C_WHITE, C_RED, C_WHITE, NOT_SPECIFIED, C_BROWN, __NO__, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_RED, C_RED, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BLACK, __NO__,
    C_BROWN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_RED, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BLACK, __NO__,
    __NO__, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_RED, C_SKIN, C_SKIN, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__, C_RED, C_RED, C_SKIN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, __NO__};

unsigned short cowboy_aiming_right[] = {
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, C_GRAY, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_SKIN, C_BLACK, C_BLACK, C_SKIN, C_SKIN, C_BLACK, C_BLACK, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    C_GRAY, C_GRAY, C_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_GRAY, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_GRAY, C_GRAY, C_GRAY, C_GRAY, C_SKIN, C_SKIN, C_SKIN, C_RED, C_RED, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BLACK, C_GRAY, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, C_BLACK, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BLACK, C_BLACK, __NO__, C_BLACK, C_BLACK, __NO__, __NO__, __NO__, __NO__};

unsigned short cowboy_running_right[] = {
    __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__,
    __NO__, __NO__, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_BLACK, C_SKIN, C_SKIN, C_BLACK, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_RED, C_RED, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_SKIN, C_SKIN, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, C_BLACK, C_BLACK, __NO__, C_BLACK, C_BLACK, __NO__, __NO__, __NO__, __NO__};

unsigned short cowboy_dead_right[] = {
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_SKIN, C_SKIN, __NO__, __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_BLACK, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, __NO__,
    __NO__, C_BLACK, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BROWN, C_RED, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BROWN,
    __NO__, C_BLACK, C_BROWN, C_BROWN, NOT_SPECIFIED, C_WHITE, C_WHITE, C_WHITE, C_RED, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BROWN,
    __NO__, __NO__, __NO__, C_BROWN, NOT_SPECIFIED, C_WHITE, C_RED, C_WHITE, C_SKIN, C_SKIN, C_BLACK, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, __NO__,
    __NO__, C_BLACK, C_BROWN, C_BROWN, NOT_SPECIFIED, C_RED, C_RED, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BROWN,
    __NO__, C_BLACK, C_BROWN, C_BROWN, NOT_SPECIFIED, C_RED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, C_BROWN,
    __NO__, __NO__, __NO__, C_SKIN, C_SKIN, C_RED, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, C_BROWN, __NO__,
    __NO__, __NO__, __NO__, C_SKIN, C_RED, C_RED, __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_BROWN, C_BROWN, NOT_SPECIFIED, C_BROWN, __NO__, __NO__,
    __NO__, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__,
    __NO__, C_RED, C_RED, C_RED, C_RED, C_RED, C_RED, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__};

void draw_cowboy(unsigned short *frame_buffer, cowboy_t *cowboy, unsigned short scale)
{
    int i, j;

    for (i = 0; i < cowboy->height; i++)
    {
        for (j = 0; j < cowboy->width; j++)
        {
            if (cowboy->side == LEFT && cowboy->state == AIMING)
            {   
                draw_cowboy_helper_function(frame_buffer, cowboy, cowboy_aiming_left, i, j, scale);
            }
            else if (cowboy->side == LEFT && cowboy->state == RUNNING)
            {
                draw_cowboy_helper_function(frame_buffer, cowboy, cowboy_running_left, i, j, scale);
            }
            else if (cowboy->side == LEFT && cowboy->state == DEAD)
            {
                draw_cowboy_helper_function(frame_buffer, cowboy, cowboy_dead_left, i, j, scale);
            }
            else if (cowboy->side == RIGHT && cowboy->state == AIMING)
            {
                draw_cowboy_helper_function(frame_buffer, cowboy, cowboy_aiming_right, i, j, scale);
            }
            else if (cowboy->side == RIGHT && cowboy->state == RUNNING)
            {
                draw_cowboy_helper_function(frame_buffer, cowboy, cowboy_running_right, i, j, scale);
            }
            else if (cowboy->side == RIGHT && cowboy->state == DEAD)
            {
                draw_cowboy_helper_function(frame_buffer, cowboy, cowboy_dead_right, i, j, scale);
            }
        }
    }
}

void draw_cowboy_helper_function(unsigned short *frame_buffer, cowboy_t *cowboy, unsigned short *source_array, int i, int j, unsigned short scale)
{
    if (cowboy->animation % ANIMATION_FREQUENCY == 0)
    {
        if (source_array[i * cowboy->width + j] == NOT_SPECIFIED)
        {
            draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, scale, cowboy->color);
        }
        else if (source_array[i * cowboy->width + j] != __NO__)
        {
            draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, scale, source_array[i * cowboy->width + j]);
        }
    }
    else
    {
        if (source_array[i * cowboy->width + j] != __NO__)
        {
            draw_pixel_scale(frame_buffer, cowboy->x + scale * j, cowboy->y + scale * i, scale, C_WHITE);
        }
    }

    if (cowboy->animation > 0)
    {
        cowboy->animation--;
    }
}
