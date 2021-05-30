#ifndef SCENES_H
#define SCENES_H

#include <math.h>
#include <time.h>

#include "draw.h"
#include "input_catcher.h"
#include "collision.h"
#include "spawn.h"
#include "settings.h"
#include "cowboy.h"

#include "mzapo_regs.h"

#ifdef __cplusplus
extern "C"
{
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

    void start_game_loop(unsigned char *parlcd_mem_base, unsigned char *led_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings, bool bot);

    void start_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);

    void start_pause_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice);

    void start_ending_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, game_map_t *game_map);

    game_map_t load_default_game();

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*SCENES_H*/