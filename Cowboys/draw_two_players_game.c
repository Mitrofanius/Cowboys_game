
#include "draw.h"

void draw_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, game_map_t *game_map)
{
    int i;
    /* Background */
    for (i = 0; i < 320 * 480; i++)
    {
        frame_buffer[i] = 0xBC06;
    }

    draw_game_map(parlcd_mem_base, frame_buffer, game_map, 3);

    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}