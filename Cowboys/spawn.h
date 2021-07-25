#ifndef SPAWN_H
#define SPAWN_H

#include "game_map.h"
#include <stdlib.h>
#include <time.h>

#define TYPE_CACTUS 1
#define TYPE_BARREL 2
#define TYPE_STONE 3

#ifdef __cplusplus
extern "C"
{
#endif

    void fill_greed(game_map_t *game_map);
    void generate_objects_on_greed(game_map_t *game_map);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*SPAWN_H*/