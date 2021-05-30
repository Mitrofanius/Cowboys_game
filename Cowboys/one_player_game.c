
#include "scenes.h"

void start_one_player_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings)
{
    font_descriptor = &font_rom8x16;
    ///TODO: setup player's setting

    draw_one_player_game(parlcd_mem_base, frame_buffer, font_descriptor, NULL);

    unsigned char ch, choice;
    while (true)
    {
        ch = getch(stdin);

        if (ch == ESCAPE)
        {
            printf("\n--------------------\n");
            printf("\n|       PAUSE      |\n");
            printf("\n--------------------\n");
            start_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);
            if (choice == MAIN_MENU)
            {
                printf("\n--------------------\n");
                printf("\n|     MAIN MENU    |\n");
                printf("\n--------------------\n");
                break;
            }
            printf("\n--------------------\n");
            printf("\n|      RESUME      |\n");
            printf("\n--------------------\n");
        }

        draw_one_player_game(parlcd_mem_base, frame_buffer, font_descriptor, NULL);
    }
}
