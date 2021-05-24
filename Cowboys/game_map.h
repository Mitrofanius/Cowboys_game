#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "cowboy.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    cowboy_t cowboy_left;
    cowboy_t cowboy_right;
    //objects_t objects;
    //unsigned short bullet_color;
} game_map_t; 

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*GAME_MAP_H*/