
#include "cowboy.h"

void fire_cowboy_left(game_map_t *game_map)
{
    if (game_map->cowboy_left.bullets > 0)
    {
        for (int i = 0; i < game_map->object_manager.bullets_length; i++)
        {
            if (!(game_map->object_manager.bullets[i].is_active))
            {
                game_map->object_manager.bullets[i].x = game_map->cowboy_left.x + COWBOY_AIMING_WIDTH * SCALE;
                game_map->object_manager.bullets[i].y = game_map->cowboy_left.y + 7 * SCALE;
                game_map->object_manager.bullets[i].width = BULLET_WIDTH;
                game_map->object_manager.bullets[i].height = BULLET_HEIGHT;
                game_map->object_manager.bullets[i].color = game_map->bullet_color;
                game_map->object_manager.bullets[i].speed_x = game_map->bullet_speed;
                game_map->cowboy_left.bullets--;
                game_map->object_manager.bullets[i].is_active = true;

                if (game_map->cowboy_left.bullets == 0)
                {
                    game_map->cowboy_left.state = RUNNING;
                    game_map->cowboy_left.width = COWBOY_RUNNING_WIDTH;
                    game_map->cowboy_left.height = COWBOY_RUNNING_HEIGHT;
                }
                break;
            }
        }
    }
}

void fire_cowboy_right(game_map_t *game_map)
{
    if (game_map->cowboy_right.bullets > 0)
    {
        for (int i = 0; i < game_map->object_manager.bullets_length; i++)
        {
            if (!(game_map->object_manager.bullets[i].is_active))
            {
                game_map->object_manager.bullets[i].x = game_map->cowboy_right.x - BULLET_WIDTH * SCALE;
                game_map->object_manager.bullets[i].y = game_map->cowboy_right.y + 7 * SCALE;
                game_map->object_manager.bullets[i].width = BULLET_WIDTH;
                game_map->object_manager.bullets[i].height = BULLET_HEIGHT;
                game_map->object_manager.bullets[i].color = game_map->bullet_color;
                game_map->object_manager.bullets[i].speed_x = -game_map->bullet_speed;
                game_map->cowboy_right.bullets--;
                game_map->object_manager.bullets[i].is_active = true;

                if (game_map->cowboy_right.bullets == 0)
                {
                    game_map->cowboy_right.x += (COWBOY_AIMING_WIDTH - COWBOY_RUNNING_WIDTH) * SCALE;
                    game_map->cowboy_right.state = RUNNING;
                    game_map->cowboy_right.width = COWBOY_RUNNING_WIDTH;
                    game_map->cowboy_right.height = COWBOY_RUNNING_HEIGHT;
                }
                break;
            }
        }
    }
}