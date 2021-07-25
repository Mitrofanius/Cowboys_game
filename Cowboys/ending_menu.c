
#include "scenes.h"

void start_ending_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, game_map_t *game_map)
{
    char ch;
    unsigned short animation = 0;
    font_descriptor = &font_rom8x16;

    printf("\n--------------------\n");
    printf("\n|    ENDING MENU   |\n");
    printf("\n--------------------\n");
    
    draw_ending_menu(parlcd_mem_base, frame_buffer, font_descriptor, game_map, &animation);
    while ((ch = getch(stdin)) != '\n')
    {
        draw_ending_menu(parlcd_mem_base, frame_buffer, font_descriptor, game_map, &animation);
    }

    printf("\n--------------------\n");
    printf("\n|     MAIN MENU    |\n");
    printf("\n--------------------\n");
    font_descriptor = &font_winFreeSystem14x16;
}