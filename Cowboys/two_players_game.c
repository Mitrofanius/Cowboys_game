
#include "scenes.h"

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

        .object_manager.barrel_length = 1,
        .object_manager.barrel[0] = {.x = 100, .y = 100, .width = BARREL_WIDTH, .height = BARREL_HEIGHT},

        .object_manager.stone_length = 1,
        .object_manager.stone[0] = {.x = 150, .y = 150, .width = STONE_WIDTH, .height = STONE_HEIGHT},

        .object_manager.cactus_length = 1,
        .object_manager.cactus[0] = {.x = 200, .y = 50, .width = CACTUS_WIDTH, .height = CACTUS_HEIGHT},

        .object_manager.bullet_length = 1,
        .object_manager.bullet[0] = {.x = 50, .y = 50, .width = BULLET_WIDTH, .height = BULLET_HEIGHT, .speed = BULLET_SPEED}
    };

    return game_map;
}

void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings)
{
    game_map_t game_map = load_default_game();

    /* Load current settings into the map */
    game_map.cowboy_left.colour = settings->player_left_color;
    game_map.cowboy_right.colour = settings->player_right_color;
    game_map.bullet_speed = settings->bullet_speed;

    draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);

for (int i = 0; i < 100; i++)
{
    game_map.cowboy_left.width = COWBOY_AIMING_WIDTH;
        game_map.cowboy_left.height = COWBOY_AIMING_HEIGHT;
        game_map.cowboy_left.state = AIMING;
        draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);
        sleep(1);
        game_map.cowboy_left.width = COWBOY_RUNNING_WIDTH;
        game_map.cowboy_left.height = COWBOY_RUNNING_HEIGHT;
        game_map.cowboy_left.state = RUNNING;
        draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);
        sleep(1);
        game_map.cowboy_left.width = COWBOY_DEAD_WIDTH;
        game_map.cowboy_left.height = COWBOY_DEAD_HEIGHT;
        game_map.cowboy_left.state = DEAD;
        draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);
        sleep(1);
}


    unsigned char ch, choice;
    while (true)
    {
        ch = getch(stdin);

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
        else if (ch == 'o')
        {
            game_map.cowboy_right.y -= 10;
        }
        else if (ch == 'l')
        {
            game_map.cowboy_right.y += 10;
        }

        draw_two_players_game(parlcd_mem_base, frame_buffer, &game_map);
    }
}
