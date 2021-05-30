
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
                /* Disactivates the bullet */
                game_map->object_manager.bullets[i].speed_x = 0;
                game_map->object_manager.bullets[i].speed_y = 0;
                game_map->object_manager.bullets[i].is_active = false;
            }
            check_collision_with_cactuses(&(game_map->object_manager.bullets[i]), game_map->object_manager.cactuses, game_map->object_manager.cactuses_length, game_map);
            check_collision_with_stones(&(game_map->object_manager.bullets[i]), game_map->object_manager.stones, game_map->object_manager.stones_length, game_map);
            check_collision_with_barrels(&(game_map->object_manager.bullets[i]), game_map->object_manager.barrels, game_map->object_manager.barrels_length, game_map);
            check_collision_with_cowboys(&(game_map->object_manager.bullets[i]), game_map);
        }
    }
}

bool isBulletOnMap(bullet_t *bullet)
{
    return (bullet->x >= 0 && bullet->x + BULLET_WIDTH * SCALE < 480 && bullet->y >= 0 && bullet->y + BULLET_HEIGHT * SCALE < 320);
}

void check_collision_with_cactuses(bullet_t *bullet, cactus_t *cactuses, unsigned char length, game_map_t *game_map)
{
    for (int i = 0; i < length; i++)
    {
        /* Checks whether current cactus is active and whether the bullet is "inside" the cactus */
        if (cactuses[i].is_active && (bullet->x + bullet->width * SCALE > cactuses[i].x && bullet->x < cactuses[i].x + cactuses[i].width * SCALE) && (bullet->y + bullet->height * SCALE > cactuses[i].y && bullet->y < cactuses[i].y + cactuses[i].height * SCALE))
        {
            cactuses[i].is_active = false;
            bullet->speed_x = -bullet->speed_x;
            bullet->speed_y = -bullet->speed_y;
            game_map->amount_of_active_objects--;
            game_map->array_of_free_places[cactuses[i].index] = 0;
        }
    }
}

void check_collision_with_stones(bullet_t *bullet, stone_t *stones, unsigned char length, game_map_t *game_map)
{
    for (int i = 0; i < length; i++)
    {   
        /* Checks whether current stone is active and whether the bullet is "inside" the stone */
        if (stones[i].is_active && (bullet->x + bullet->width * SCALE > stones[i].x && bullet->x < stones[i].x + stones[i].width * SCALE) && (bullet->y + bullet->height * SCALE > stones[i].y && bullet->y < stones[i].y + stones[i].height * SCALE))
        {
            bullet->speed_y = 2;
            generate_bullet_after_collision_with_stone(game_map, bullet);
            stones[i].is_active = false;
            game_map->amount_of_active_objects--;
            game_map->array_of_free_places[stones[i].index] = 0;
        }
    }
}

void check_collision_with_barrels(bullet_t *bullet, barrel_t *barrels, unsigned char length, game_map_t *game_map)
{
    for (int i = 0; i < length; i++)
    {   
        /* Checks whether current barel is active and whether the bullet is "inside" the barrel */
        if (barrels[i].is_active && (bullet->x + bullet->width * SCALE > barrels[i].x && bullet->x < barrels[i].x + barrels[i].width * SCALE) && (bullet->y + bullet->height * SCALE > barrels[i].y && bullet->y < barrels[i].y + barrels[i].height * SCALE))
        {
            barrels[i].is_active = false;
            if (bullet->speed_x >= 10)
                bullet->speed_x /= 5;
            game_map->amount_of_active_objects--;
            game_map->array_of_free_places[barrels[i].index] = 0;
        }
    }
}

void generate_bullet_after_collision_with_stone(game_map_t *game_map, bullet_t *mother_bullet)
{
    for (int i = 0; i < game_map->object_manager.bullets_length; i++)
    {   
        /* Finds not actove bullet and activates it with new parameters*/
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

void check_collision_with_cowboys(bullet_t *bullet, game_map_t *game_map)
{
    /* Checks if the bullet "inside" of the left cowboy */
    if ((bullet->x + bullet->width * SCALE > game_map->cowboy_left.x && bullet->x < game_map->cowboy_left.x + game_map->cowboy_left.width * SCALE - game_map->cowboy_left.width * 2 / 3 * SCALE) && (bullet->y + bullet->height * SCALE > game_map->cowboy_left.y && bullet->y < game_map->cowboy_left.y + game_map->cowboy_left.height * SCALE))
    {   
        /* Disactivates the bullet */
        bullet->is_active = false;
        bullet->speed_x = 0;
        bullet->speed_y = 0;

        /* Decreases health */
        if (game_map->cowboy_left.health >= BULLET_FIRE_POWER)
        {
            game_map->cowboy_left.health -= BULLET_FIRE_POWER;
        }
        else
        {
            game_map->cowboy_left.health = 0;
        }

        /* Hit animation */
        game_map->cowboy_left.animation = ANIMATION_TIME;
        printf("\n--------------------\n");
        printf("\n|   LEFT WAS HIT   |\n");
        printf("\n--------------------\n");

        /* Checks whether left cowboy died */
        if (game_map->cowboy_left.health == 0)
        {
            game_map->cowboy_left.state = DEAD;
            game_map->cowboy_left.width = COWBOY_DEAD_WIDTH;
            game_map->cowboy_left.height = COWBOY_DEAD_HEIGHT;

            printf("\n--------------------\n");
            printf("\n|     LEFT DIED    |\n");
            printf("\n--------------------\n");
        }
    }

    /* Checks if the bullet "inside" of the right cowboy */
    if ((bullet->x + bullet->width * SCALE > game_map->cowboy_right.x + game_map->cowboy_right.width * 2 / 3 * SCALE && bullet->x < game_map->cowboy_right.x + game_map->cowboy_right.width * SCALE) && (bullet->y + bullet->height * SCALE > game_map->cowboy_right.y && bullet->y < game_map->cowboy_right.y + game_map->cowboy_right.height * SCALE))
    {   
        /* Disactivates the bullet */
        bullet->is_active = false;
        bullet->speed_x = 0;
        bullet->speed_y = 0;

        /* Decreases health */
        if (game_map->cowboy_right.health >= BULLET_FIRE_POWER)
        {
            game_map->cowboy_right.health -= BULLET_FIRE_POWER;
        }
        else
        {
            game_map->cowboy_right.health = 0;
        }

        /* Hit animation */
        game_map->cowboy_right.animation = ANIMATION_TIME;
        printf("\n--------------------\n");
        printf("\n|   RIGHT WAS HIT  |\n");
        printf("\n--------------------\n");

        /* Checks whether right cowboy died */
        if (game_map->cowboy_right.health == 0)
        {
            game_map->cowboy_right.state = DEAD;
            game_map->cowboy_right.width = COWBOY_DEAD_WIDTH;
            game_map->cowboy_right.height = COWBOY_DEAD_HEIGHT;

            printf("\n--------------------\n");
            printf("\n|    RIGHT DIED    |\n");
            printf("\n--------------------\n");
        }
    }
}
