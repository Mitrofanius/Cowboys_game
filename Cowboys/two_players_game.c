
#include "two_players_game.h"

void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    ///TODO: setup player's setting

    game_map_t game_map = {
        .cowboy_blue.x = 30,
        .cowboy_blue.y = 30,
        .cowboy_blue.width = 20,
        .cowboy_blue.height = 17,
        .cowboy_blue.colour = C_LIGHT_BLUE,
        .cowboy_blue.side = LEFT,
        .cowboy_blue.state = AIMING
    };

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
