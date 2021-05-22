
#include "game.h"
#include "menu.h"

void start_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    draw_loading_scene(parlcd_mem_base, frame_buffer, font_descriptor);

    char choice = ONE_PLAYER_GAME;
    start_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);

    switch (choice)
    {
        case ONE_PLAYER_GAME:
            /* 1 player game */
            printf("\n\n\n ONE_PLAYER_GAME \n\n\n");
            //start_one_player_game();
            break;
        case TWO_PLAYERS_GAME:
            /* 2 players game */
            printf("\n\n\n TWO_PLAYERS_GAME \n\n\n");
            //start_two_players_game();
            break;
        case SETTINGS:
            /* settings */
            printf("\n\n\n SETTINGS \n\n\n");
            //start_settings();
            break;
        default:
            printf("\n\n\n EXIT \n\n\n");
            break;
    }

    draw_closing_scene(parlcd_mem_base, frame_buffer, font_descriptor);
}

void start_one_player_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{

}

void start_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{

}

void start_settings(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{
    
}