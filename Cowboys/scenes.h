#ifndef SCENES_H
#define SCENES_H

#include "draw.h"
#include "input_catcher.h"
#include "settings.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Main menu */
#define ONE_PLAYER_GAME 0
#define TWO_PLAYERS_GAME 1
#define SETTINGS 2
#define EXIT 3

/* Pause menu */
#define RESUME 0
#define MAIN_MENU 1

void start_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice);

void start_one_player_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);

void start_pause_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice);

void start_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);

void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);

game_map_t load_default_game();

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*SCENES_H*/