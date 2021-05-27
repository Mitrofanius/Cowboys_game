
#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include <stdbool.h>
#include <termios.h>

#include "font_types.h"
#include "game_map.h"
#include "colors.h"
#include "mzapo_parlcd.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define SCALE 3

#define REGTANGL_LEFT_UP_X 57
#define REGTANGLE_FRAME_HEIGHT 5
#define REGTANGLE_WIDTH 368
#define REGTANGLE_HEIGHT 54
#define CHAR_SCALE 3

#define AIMING 0
#define RUNNING 1
#define DEAD 2

#define COWBOY_LEFT_X 15
#define COWBOY_LEFT_Y 130
#define COWBOY_RIGHT_X 405
#define COWBOY_RIGHT_Y 130

#define COWBOY_DEAD_WIDTH 18
#define COWBOY_DEAD_HEIGHT 15
#define COWBOY_RUNNING_WIDTH 14
#define COWBOY_RUNNING_HEIGHT 17
#define COWBOY_AIMING_WIDTH 20
#define COWBOY_AIMING_HEIGHT 17

#define BARREL_WIDTH 11
#define BARREL_HEIGHT 13
#define STONE_WIDTH 10
#define STONE_HEIGHT 9
#define CACTUS_WIDTH 10
#define CACTUS_HEIGHT 13
#define BULLET_WIDTH 4
#define BULLET_HEIGHT 4

#define LEFT 0
#define RIGHT 1

#define FIRST_CHOICE 0
#define SECOND_CHOICE 1
#define THIRD_CHOICE 2
#define FOURTH_CHOICE 3
#define FIFTH_CHOICE 4
#define SIXTH_CHOICE 5

#define PLAYER_LEFT_COLOUR 0
#define PLAYER_RIGHT_COLOUR 1
#define BULLET_COLOR 2
#define BULLET_SPEED 3

    void draw_char(unsigned short *frame_buffer, font_descriptor_t *font_descriptor, int x, int y, char ch, unsigned char scale, unsigned short color);

    void draw_pixel(unsigned short *frame_buffer, int x, int y, unsigned short color);

    void draw_pixel_scale(unsigned short *frame_buffer, int x, int y, unsigned char scale, unsigned short color);

    unsigned int hsv2rgb_lcd(int hue, int saturation, int value);

    void draw_rectangle(unsigned short *frame_buffer, int x, int y, int width, int height, int frame_height, unsigned short frame_color, unsigned short fill_color);

    void draw_loading_scene(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);

    void draw_closing_scene(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);

    void draw_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *const choice);

    void draw_pause_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *const choice);

    void draw_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer,
                            font_descriptor_t *font_descriptor, cowboy_t *cowboy_left,
                            cowboy_t *cowboy_right, bullet_t *bullet, unsigned char choice_button,
                            unsigned char choice_left_player_color, unsigned char choice_right_player_color, 
                            unsigned char choice_bullet_color, int choice_bullet_speed);

    void draw_one_player_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer);

    void draw_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, game_map_t *game_map);

    void draw_cowboy(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, cowboy_t *cowboy, unsigned short scale);

    void draw_objects(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, object_manager_t *object_manager, int scale);

    void draw_cactus(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, cactus_t *cactus, int scale);

    void draw_bullet(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, bullet_t *bullet, int scale);

    void draw_stone(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, stone_t *stone, int scale);

    void draw_barrel(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, barrel_t *barrel, int scale);

    void draw_game_map(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, game_map_t *game_map, int scale);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*DRAW_H*/
