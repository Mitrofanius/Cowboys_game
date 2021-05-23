
#include "one_player_game.h"

void start_one_player_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    ///TODO: setup player's setting

    draw_one_player_game(parlcd_mem_base, frame_buffer, font_descriptor);
    
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
        //     move player
        // }
        // else if (ch == 's') 
        // {
        //     move player
        // }
        // else if (ch == 'd') 
        // {
        //     fire
        // }

        draw_one_player_game(parlcd_mem_base, frame_buffer, font_descriptor);
    }
}
