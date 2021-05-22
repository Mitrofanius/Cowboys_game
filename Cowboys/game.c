
#include "game.h"
#include "menu.h"

void start_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    //show_loading_scene();

    char choice = ONE_PLAYER_GAME;
    start_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);

    switch (choice)
    {
        case ONE_PLAYER_GAME:
            /* 1 player game */
            break;
        case TWO_PLAYERS_GAME:
            /* 2 players game */
            printf("\n\n\n start_two_players_game(); \n\n\n");
            //start_two_players_game();
            break;
        case SETTINGS:
            /* settings */
            break;
        default:
            break;
    }

    //show_closing_scene();
}