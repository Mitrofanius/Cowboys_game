
#ifndef DRAW_TWO_PLAYERS_GAME_H
#define DRAW_TWO_PLAYERS_GAME_H

#include "draw.h"
#include "draw_cowboy.h"

#ifdef __cplusplus
extern "C" {
#endif

void draw_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, game_map_t *game_map);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*DRAW_TWO_PLAYERS_GAME_H*/
