
#include "scenes.h"

void start_ending_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, game_map_t *game_map)
{
    unsigned short animation = 0;
    draw_ending_menu(parlcd_mem_base, frame_buffer, game_map, &animation);

    char ch;
    while ((ch = getch(stdin)) != '\n')
    {
        draw_ending_menu(parlcd_mem_base, frame_buffer, game_map, &animation);
    }
}