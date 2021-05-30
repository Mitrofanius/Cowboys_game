#ifndef COWBOY_H
#define COWBOY_H

#include "game_map.h"

#ifdef __cplusplus
extern "C"
{
#endif

void fire_cowboy_left(game_map_t *game_map);
void fire_cowboy_right(game_map_t *game_map);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*COWBOY_H*/