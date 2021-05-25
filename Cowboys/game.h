#ifndef GAME_H
#define GAME_H

#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdbool.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"

#include "main_menu.h"
#include "one_player_game.h"
#include "two_players_game.h"
#include "settings_menu.h"
#include "draw_scene_animation.h"

#ifdef __cplusplus
extern "C" {
#endif

void start_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);
void start_one_player_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);
void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);
void start_settings(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*GAME_H*/