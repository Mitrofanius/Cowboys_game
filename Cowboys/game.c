
#include "game.h"

void start_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    unsigned char choice;
    draw_loading_scene(parlcd_mem_base, frame_buffer, font_descriptor);

    while (true)
    {
        choice = ONE_PLAYER_GAME;
        start_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);

        switch (choice)
        {
        case ONE_PLAYER_GAME:
            /* 1 player game */
            printf("\n\n\n ONE_PLAYER_GAME \n\n\n");
            start_one_player_game(parlcd_mem_base, frame_buffer, font_descriptor);
            break;
        case TWO_PLAYERS_GAME:
            /* 2 players game */
            printf("\n\n\n TWO_PLAYERS_GAME \n\n\n");
            start_two_players_game(parlcd_mem_base, frame_buffer, font_descriptor);
            break;
        case SETTINGS:
            /* settings */
            printf("\n\n\n SETTINGS \n\n\n");
            start_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor);
            break;
        default:
            printf("\n\n\n EXIT \n\n\n");
            break;
        }

        if (choice == EXIT)
        {
            break;
        }
    }

    draw_closing_scene(parlcd_mem_base, frame_buffer, font_descriptor);
}
