#ifndef COLLISION_H
#define COLLISION_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>

#include <stdbool.h>
#include "game_map.h"

    void check_collisions(game_map_t *game_map);
    bool isCowboyOnMap(cowboy_t *cowboy);
    bool isBulletOnMap(bullet_t *bullet);
    void check_collision_with_cactuses(bullet_t *bullet, cactus_t *cactuses, unsigned char length, game_map_t *game_map);
    void check_collision_with_stones(bullet_t *bullet, stone_t *stones, unsigned char length, game_map_t *game_map);
    void check_collision_with_barrels(bullet_t *bullet, barrel_t *barrels, unsigned char length, game_map_t *game_map);
    void generate_bullet_after_collision_with_stone(game_map_t *game_map, bullet_t *mother_bullet);
    void check_collision_with_cowboys(bullet_t *bullet, game_map_t *game_map);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*COLLISION_H*/