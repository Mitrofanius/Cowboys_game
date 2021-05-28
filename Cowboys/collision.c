
#include "collision.h"

bool isCowboyOnMap(cowboy_t *cowboy)
{
    bool answer = true;

    if (cowboy->direction == UP)
    {
        if (cowboy->y - COWBOY_RELOCATION < 0)
        {
            answer = false;
        }
    }
    else if (cowboy->direction == DOWN)
    {
        if (cowboy->y + COWBOY_RELOCATION + cowboy->height * SCALE > 320)
        {
            answer = false;
        }
    }

    return answer;
}

void check_collisions(game_map_t *game_map)
{
    for (int i = 0; i < game_map->object_manager.bullets_length; i++)
    {
        if (game_map->object_manager.bullets[i].is_active)
        {
            if (!(isBulletOnMap(&(game_map->object_manager.bullets[i]))))
            {
                game_map->object_manager.bullets[i].speed_x = 0;
                game_map->object_manager.bullets[i].speed_y = 0;
                game_map->object_manager.bullets[i].is_active = false;
            }
            check_collision_with_cactuses(&(game_map->object_manager.bullets[i]), game_map->object_manager.cactuses, game_map->object_manager.cactuses_length);
            check_collision_with_stones(&(game_map->object_manager.bullets[i]), game_map->object_manager.stones, game_map->object_manager.stones_length, game_map);
            check_collision_with_barrels(&(game_map->object_manager.bullets[i]), game_map->object_manager.barrels, game_map->object_manager.barrels_length);
        }
    }
}

bool isBulletOnMap(bullet_t *bullet)
{
    return (bullet->x >= 0 && bullet->x + BULLET_WIDTH * SCALE < 480 && bullet->y >= 0 && bullet->y + BULLET_HEIGHT * SCALE < 320);
}

void check_collision_with_cactuses(bullet_t *bullet, cactus_t *cactuses, unsigned char length)
{
    for (int i = 0; i < length; i++)
    {
        if (cactuses[i].is_active && (bullet->x + bullet->width * SCALE > cactuses[i].x && bullet->x < cactuses[i].x + cactuses[i].width * SCALE) && (bullet->y + bullet->height * SCALE > cactuses[i].y && bullet->y < cactuses[i].y + cactuses[i].height * SCALE))
        {
            // bullet->is_active = false;
            cactuses[i].is_active = false;
            bullet->speed_x = -bullet->speed_x;
            bullet->speed_y = -bullet->speed_y;
        }
    }
}

void check_collision_with_stones(bullet_t *bullet, stone_t *stones, unsigned char length, game_map_t *game_map)
{
    for (int i = 0; i < length; i++)
    {
        if (stones[i].is_active && (bullet->x + bullet->width * SCALE > stones[i].x && bullet->x < stones[i].x + stones[i].width * SCALE) && (bullet->y + bullet->height * SCALE > stones[i].y && bullet->y < stones[i].y + stones[i].height * SCALE))
        {
            bullet->speed_y = 2;
            generate_bullet_after_collision_with_stone(game_map, bullet);
            stones[i].is_active = false;
            bullet->speed_x = 0;
        }
    }
}

void check_collision_with_barrels(bullet_t *bullet, barrel_t *barrels, unsigned char length)
{
    for (int i = 0; i < length; i++)
    {
        if (barrels[i].is_active && (bullet->x + bullet->width * SCALE > barrels[i].x && bullet->x < barrels[i].x + barrels[i].width * SCALE) && (bullet->y + bullet->height * SCALE > barrels[i].y && bullet->y < barrels[i].y + barrels[i].height * SCALE))
        {
            // bullet->is_active = false;
            barrels[i].is_active = false;
            bullet->speed_x /= 5;
        }
    }
}

void generate_bullet_after_collision_with_stone(game_map_t *game_map, bullet_t *mother_bullet)
{
    for (int i = 0; i < game_map->object_manager.bullets_length; i++)
    {
        if (!(game_map->object_manager.bullets[i].is_active))
        {
            game_map->object_manager.bullets[i].x = mother_bullet->x;
            game_map->object_manager.bullets[i].y = mother_bullet->y;
            game_map->object_manager.bullets[i].width = BULLET_WIDTH;
            game_map->object_manager.bullets[i].height = BULLET_HEIGHT;
            game_map->object_manager.bullets[i].color = game_map->bullet_color;
            game_map->object_manager.bullets[i].speed_x = mother_bullet->speed_x;
            game_map->object_manager.bullets[i].speed_y = -mother_bullet->speed_y;
            game_map->object_manager.bullets[i].is_active = true;
            break;
        }
    }
}