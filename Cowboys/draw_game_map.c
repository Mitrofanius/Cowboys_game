#include "draw.h"

void draw_game_map(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, game_map_t *game_map, int scale)
{
    draw_cowboy(parlcd_mem_base, frame_buffer, &(game_map->cowboy_left), scale);
    draw_cowboy(parlcd_mem_base, frame_buffer, &(game_map->cowboy_right), scale);
    draw_objects(parlcd_mem_base, frame_buffer, &(game_map->object_manager), scale);
}
