
#ifndef ONE_PLAYER_GAME_H
#define ONE_PLAYER_GAME_H

#include "input_catcher.h"
#include "draw_one_player_game.h"
#include "pause_menu.h"

#ifdef __cplusplus
extern "C" {
#endif

void start_one_player_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*ONE_PLAYER_GAME_H*/