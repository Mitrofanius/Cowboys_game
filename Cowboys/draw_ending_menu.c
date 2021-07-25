
#include "draw.h"

void draw_ending_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, game_map_t *game_map, unsigned short *animation)
{
    int i;

    draw_rectangle(frame_buffer, 130, 95, 214, 132, 3, C_BLACK, 0x9B01);

    if (game_map->cowboy_left.state == DEAD)
    {
        draw_char(frame_buffer, font_descriptor, 191, 109, 'R', 2, game_map->cowboy_right.color);
        draw_char(frame_buffer, font_descriptor, 210, 109, 'I', 2, game_map->cowboy_right.color);
        draw_char(frame_buffer, font_descriptor, 229, 109, 'G', 2, game_map->cowboy_right.color);
        draw_char(frame_buffer, font_descriptor, 248, 109, 'H', 2, game_map->cowboy_right.color);
        draw_char(frame_buffer, font_descriptor, 267, 109, 'T', 2, game_map->cowboy_right.color);

        draw_char(frame_buffer, font_descriptor, 210, 145, 'W', 2, C_LIGHT_GREEN);
        draw_char(frame_buffer, font_descriptor, 229, 145, 'O', 2, C_LIGHT_GREEN);
        draw_char(frame_buffer, font_descriptor, 248, 145, 'N', 2, C_LIGHT_GREEN);
    }
    else if (game_map->cowboy_right.state == DEAD)
    {
        draw_char(frame_buffer, font_descriptor, 201, 109, 'L', 2, game_map->cowboy_left.color);
        draw_char(frame_buffer, font_descriptor, 220, 109, 'E', 2, game_map->cowboy_left.color);
        draw_char(frame_buffer, font_descriptor, 238, 109, 'F', 2, game_map->cowboy_left.color);
        draw_char(frame_buffer, font_descriptor, 257, 109, 'T', 2, game_map->cowboy_left.color);

        draw_char(frame_buffer, font_descriptor, 210, 145, 'W', 2, C_LIGHT_GREEN);
        draw_char(frame_buffer, font_descriptor, 229, 145, 'O', 2, C_LIGHT_GREEN);
        draw_char(frame_buffer, font_descriptor, 248, 145, 'N', 2, C_LIGHT_GREEN);
    }


    if (*animation < 20)
    {
        draw_char(frame_buffer, font_descriptor, 141, 181, 'P', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 160, 181, 'R', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 179, 181, 'E', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 198, 181, 'S', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 217, 181, 'S', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 241, 181, 'E', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 260, 181, 'N', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 279, 181, 'T', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 298, 181, 'E', 2, C_WHITE);
        draw_char(frame_buffer, font_descriptor, 317, 181, 'R', 2, C_WHITE);
    }

    (*animation)++;
    if (*animation == 20)
    {
        draw_rectangle(frame_buffer, 141, 181, 192, 32, 0, 0x9B01, 0x9B01);
        
    }

    if(*animation == 40)
    {
        (*animation) = 0;
    }

    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}