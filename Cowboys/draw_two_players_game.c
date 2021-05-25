
#include "draw_two_players_game.h"

void draw_two_players_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, game_map_t *game_map)
{
    int i;
    /* Background */
    for (i = 0; i < 320 * 480; i++)
    {
        frame_buffer[i] = 0xCCCE;
    }

    draw_cowboy(parlcd_mem_base, frame_buffer, font_descriptor, &(game_map->cowboy_left), 3);
    draw_cowboy(parlcd_mem_base, frame_buffer, font_descriptor, &(game_map->cowboy_right), 3);
    
    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}