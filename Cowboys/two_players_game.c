
#include "scenes.h"
#include <time.h>

game_map_t load_default_game()
{
    game_map_t game_map = {
        .cowboy_left = {
            .x = COWBOY_LEFT_X,
            .y = COWBOY_LEFT_Y,
            .width = COWBOY_AIMING_WIDTH,
            .height = COWBOY_AIMING_HEIGHT,
            .colour = C_LIGHT_BLUE,
            .side = LEFT,
            .state = AIMING,
        },

        .cowboy_right = {
            .x = COWBOY_RIGHT_X,
            .y = COWBOY_RIGHT_Y,
            .width = COWBOY_AIMING_WIDTH,
            .height = COWBOY_AIMING_HEIGHT,
            .colour = C_RED,
            .side = RIGHT,
            .state = AIMING,
        },

        .object_manager.barrels_length = 1,
        .object_manager.barrels[0] = {.x = 100, .y = 100, .width = BARREL_WIDTH, .height = BARREL_HEIGHT},

        .object_manager.stones_length = 1,
        .object_manager.stones[0] = {.x = 150, .y = 150, .width = STONE_WIDTH, .height = STONE_HEIGHT},

        .object_manager.cactuses_length = 1,
        .object_manager.cactuses[0] = {.x = 200, .y = 50, .width = CACTUS_WIDTH, .height = CACTUS_HEIGHT}};

    return game_map;
}

void update_bullets(bullet_t *bullets, unsigned short length)
{
    for (int i = 0; i < length; i++)
    {
        //check collision update in there is no collision with objects, cowboy and on the map
        bullets[i].x += bullets[i].speed;
    }
}

void update_states(game_map_t *game_map)
{
    //update_cowboy();
    //update_cowboy();
    update_bullets(game_map->object_manager.bullets, game_map->object_manager.bullets_length);
}

void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings)
{

    struct timespec loop_delay =
        {.tv_sec = 0, .tv_nsec = 10000};

    game_map_t game_map = load_default_game();

    /* Load current settings into the map */
    game_map.cowboy_left.colour = settings->player_left_color;
    game_map.cowboy_right.colour = settings->player_right_color;
    game_map.bullet_speed = settings->bullet_speed;

    draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);

    unsigned char ch, choice;
    while (true)
    {

        ch = getch(stdin);

        update_states(&game_map);

        if (ch == ESCAPE)
        {
            printf("ESCAPE");
            start_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);
            if (choice == MAIN_MENU)
            {
                break;
            }
        }
        else if (ch == 'w')
        {
            game_map.cowboy_left.y -= 10;
        }
        else if (ch == 's')
        {
            game_map.cowboy_left.y += 10;
        }
        else if (ch == 'd' && game_map.cowboy_left.state == AIMING)
        {
            game_map.object_manager.bullets[game_map.object_manager.bullets_length].speed = game_map.bullet_speed;
            game_map.object_manager.bullets[game_map.object_manager.bullets_length].x = game_map.cowboy_left.x + COWBOY_AIMING_WIDTH * 3;
            game_map.object_manager.bullets[game_map.object_manager.bullets_length].y = game_map.cowboy_left.y + 7 * 3;
            game_map.object_manager.bullets[game_map.object_manager.bullets_length].width = BULLET_WIDTH;
            game_map.object_manager.bullets[game_map.object_manager.bullets_length].height = BULLET_HEIGHT;
            game_map.object_manager.bullets_length++;
        }
        else if (ch == 'o')
        {
            game_map.cowboy_right.y -= 10;
        }
        else if (ch == 'l')
        {
            game_map.cowboy_right.y += 10;
        }

        draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);
        clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
    }
}
