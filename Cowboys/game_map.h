#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "objects.h"

#define SCALE 3
#define GREED_WIDTH (int)((480 - (2 * (COWBOY_LEFT_X + 25)) - (COWBOY_AIMING_WIDTH * SCALE * 2)) / (13 * SCALE))
#define GREED_HEIGHT (int)((320 - (2 * 10)) / (13 * SCALE))
#define START_X (int)(COWBOY_LEFT_X + COWBOY_AIMING_WIDTH * SCALE + 25)
#define START_Y 10

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        cowboy_t cowboy_left;
        cowboy_t cowboy_right;
        object_manager_t object_manager;
        unsigned short bullet_color;
        int bullet_speed;
        unsigned char amount_of_active_objects;
        int objects_coordinates[GREED_WIDTH * GREED_HEIGHT * 2];
        int array_of_free_places[GREED_WIDTH * GREED_HEIGHT];
    } game_map_t;


#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*GAME_MAP_H*/