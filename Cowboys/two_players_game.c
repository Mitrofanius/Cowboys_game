
#include "two_players_game.h"

void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    game_map_t game_map = {
        .cowboy_left.x = 20,
        .cowboy_left.y = 20,
        .cowboy_left.width = 20,
        .cowboy_left.height = 17,
        .cowboy_left.colour = C_LIGHT_GREEN,
        .cowboy_left.side = LEFT,
        .cowboy_left.state = AIMING,

        .cowboy_right.x = 200,
        .cowboy_right.y = 200,
        .cowboy_right.width = 20,
        .cowboy_right.height = 17,
        .cowboy_right.colour = C_LIGHT_ORANGE,
        .cowboy_right.side = RIGHT,
        .cowboy_right.state = AIMING,
    };

    ///TODO: setup player's setting colours from settings

    draw_two_players_game(parlcd_mem_base, frame_buffer, font_descriptor, &game_map);
    
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
        else if (ch == 'a') 
        {
            game_map.cowboy_left.x -= 10;
        }
        else if (ch == 'd') 
        {
            game_map.cowboy_left.x += 10;
        }
        else if (ch == 'o') 
        {
            game_map.cowboy_right.y -= 10;
        }
        else if (ch == 'l') 
        {
            game_map.cowboy_right.y += 10;
        }
        else if (ch == 'k') 
        {
            game_map.cowboy_right.x -= 10;
        }
        else if (ch == ';') 
        {
            game_map.cowboy_right.x += 10;
        }

        // else if (ch == 'w') 
        // {
        //     first player move
        // }
        // else if (ch == 's') 
        // {
        //     first player move
        // }
        // else if (ch == 'd') 
        // {
        //     first player fire
        // }
        // else if (ch == 'w') 
        // {
        //     second player move
        // }
        // else if (ch == 's') 
        // {
        //     second player move
        // }
        // else if (ch == 'd') 
        // {
        //     second player fire
        // }

        draw_two_players_game(parlcd_mem_base, frame_buffer, font_descriptor, &game_map);
    }
}
