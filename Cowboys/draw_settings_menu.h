#ifndef DRAW_SETTINGS_MENU_H
#define DRAW_SETTINGS_MENU_H

#include "draw.h"
#include "draw_cowboy.h"
#include "colours.h"

#define FIRST_CHOICE 0
#define SECOND_CHOICE 1
#define THIRD_CHOICE 2
#define FOURTH_CHOICE 3
#define FIFTH_CHOICE 4
#define SIXTH_CHOICE 5

#define PLAYER_LEFT_COLOUR 0
#define PLAYER_RIGHT_COLOUR 1
#define BULLET_SPEED 2
#define BACK 3

#ifdef __cplusplus
extern "C"
{
#endif

    void draw_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer,
                            font_descriptor_t *font_descriptor, cowboy_t *cowboy_left,
                            cowboy_t *cowboy_right, unsigned char choice_button,
                            unsigned char choice_left_player_color, unsigned char choice_right_player_color, int choice_bullet_speed);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*DRAW_SETTINGS_MENU_H*/
