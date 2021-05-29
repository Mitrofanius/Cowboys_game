
#include "scenes.h"

game_map_t load_default_game()
{
    game_map_t game_map = {
        .cowboy_left = {
            .x = COWBOY_LEFT_X,
            .y = COWBOY_LEFT_Y,
            .width = COWBOY_AIMING_WIDTH,
            .height = COWBOY_AIMING_HEIGHT,
            .color = C_LIGHT_BLUE,
            .side = LEFT,
            .state = AIMING,
            .health = COWBOY_HEALTH,
            .direction = UP,
            .bullets = COWBOY_BULLET_AMOUNT},

        .cowboy_right = {.x = COWBOY_RIGHT_X, .y = COWBOY_RIGHT_Y, .width = COWBOY_AIMING_WIDTH, .height = COWBOY_AIMING_HEIGHT, .color = C_RED, .side = RIGHT, .state = AIMING, .health = COWBOY_HEALTH, .direction = DOWN, .bullets = COWBOY_BULLET_AMOUNT},

        .object_manager.barrels_length = BARREL_AMOUNT,
        .object_manager.barrels[0] = {.x = 100, .y = 100, .width = BARREL_WIDTH, .height = BARREL_HEIGHT, .is_active = true},

        .object_manager.stones_length = STONE_AMOUNT,
        .object_manager.stones[0] = {.x = 150, .y = 150, .width = STONE_WIDTH, .height = STONE_HEIGHT, .is_active = true},

        .object_manager.cactuses_length = CACTUS_AMOUNT,
        .object_manager.cactuses[0] = {.x = 200, .y = 50, .width = CACTUS_WIDTH, .height = CACTUS_HEIGHT, .is_active = true},

        .object_manager.bullets_length = BULLET_AMOUNT};

    return game_map;
}

void update_bullets(bullet_t *bullets, unsigned short length)
{
    for (int i = 0; i < length; i++)
    {
        if (bullets[i].is_active)
        {
            bullets[i].x += bullets[i].speed_x;
            bullets[i].y += bullets[i].speed_y;
        }
    }
}

void update_cowboy(cowboy_t *cowboy)
{
    if (cowboy->direction == UP)
    {
        if (isCowboyOnMap(cowboy))
        {
            cowboy->y -= COWBOY_RELOCATION;
        }
        else
        {
            cowboy->direction = DOWN;
        }
    }
    else if (cowboy->direction == DOWN)
    {
        if (isCowboyOnMap(cowboy))
        {
            cowboy->y += COWBOY_RELOCATION;
        }
        else
        {
            cowboy->direction = UP;
        }
    }
}

void update_states(game_map_t *game_map)
{
    update_cowboy(&(game_map->cowboy_left));
    update_cowboy(&(game_map->cowboy_right));
    update_bullets(game_map->object_manager.bullets, game_map->object_manager.bullets_length);
    check_collisions(game_map);
}

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

void load_settings(game_map_t *game_map, settings_t *settings)
{
    game_map->cowboy_left.color = settings->player_left_color;
    game_map->cowboy_right.color = settings->player_right_color;
    game_map->bullet_color = settings->bullet_color;
    game_map->bullet_speed = settings->bullet_speed;
}

void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings)
{
    struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = 10000};
    game_map_t game_map = load_default_game();
    load_settings(&game_map, settings);
    bool reload_pistols = false;

    unsigned char ch, choice = RESUME;
    draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);
    while (true)
    {
        if (game_map.cowboy_left.state == DEAD || game_map.cowboy_right.state == DEAD)
        {
            sleep(3);
            break;
        }
        

        if (game_map.cowboy_left.bullets == 0 && game_map.cowboy_right.bullets == 0)
        {
            reload_pistols = true;
            for (int i = 0; i < game_map.object_manager.bullets_length; i++)
            {
                if (game_map.object_manager.bullets[i].is_active)
                {
                    reload_pistols = false;
                }
            }

            if (reload_pistols)
            {
                game_map.cowboy_left.bullets = COWBOY_BULLET_AMOUNT;
                game_map.cowboy_left.state = AIMING;
                game_map.cowboy_left.width = COWBOY_AIMING_WIDTH;
                game_map.cowboy_left.health = COWBOY_AIMING_HEIGHT;

                game_map.cowboy_right.bullets = COWBOY_BULLET_AMOUNT;
                game_map.cowboy_right.x = COWBOY_RIGHT_X;
                game_map.cowboy_right.state = AIMING;
                game_map.cowboy_right.width = COWBOY_AIMING_WIDTH;
                game_map.cowboy_right.health = COWBOY_AIMING_HEIGHT;
            }
        }

        update_states(&game_map);

        ch = getch(stdin);
        if (ch == ESCAPE)
        {
            printf("\n\n\n  PAUSE   \n\n\n");
            start_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);
            if (choice == MAIN_MENU)
            {
                break;
            }
        }
        else if (ch == 'w')
        {
            game_map.cowboy_left.direction = UP;
        }
        else if (ch == 's')
        {
            game_map.cowboy_left.direction = DOWN;
        }
        else if (ch == 'd')
        {
            fire_cowboy_left(&game_map);
        }
        else if (ch == 'o')
        {
            game_map.cowboy_right.direction = UP;
        }
        else if (ch == 'l')
        {
            game_map.cowboy_right.direction = DOWN;
        }
        else if (ch == 'k')
        {
            fire_cowboy_right(&game_map);
        }

        draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);
        clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
    }
}
