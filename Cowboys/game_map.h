#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "objects.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    cowboy_t cowboy_left;
    cowboy_t cowboy_right;
    object_manager_t object_manager;
    unsigned short bullet_color;
    int bullet_speed;
} game_map_t; 

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*GAME_MAP_H*/