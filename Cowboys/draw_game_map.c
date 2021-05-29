#include "draw.h"

void draw_game_map(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, game_map_t *game_map, int scale)
{
    draw_cowboy(parlcd_mem_base, frame_buffer, &(game_map->cowboy_left), scale);
    draw_cowboy(parlcd_mem_base, frame_buffer, &(game_map->cowboy_right), scale);
    draw_objects(parlcd_mem_base, frame_buffer, &(game_map->object_manager), scale);

    draw_game_label(frame_buffer, game_map->cowboy_left.health, game_map->cowboy_left.color, game_map->cowboy_left.bullets, game_map->cowboy_right.health, game_map->cowboy_right.color, game_map->cowboy_right.bullets);
}

void draw_game_label(unsigned short *frame_buffer, unsigned char left_health, unsigned short left_color, unsigned char left_bullets,  unsigned char right_health, unsigned short right_color, unsigned char right_bullets)
{
    font_descriptor_t *font_descriptor = &font_rom8x16;
    char buffer[10];


    /* HP label left cowboy */
    int i = 0;
    itoa(buffer, left_health);
    draw_char(frame_buffer, font_descriptor, 10, 10, 'H', 2, left_color);
    draw_char(frame_buffer, font_descriptor, 10 + 8 * 2, 10, 'P', 2, left_color);
    draw_char(frame_buffer, font_descriptor, 10 + 8 * 2 * 2, 10, ':', 2, left_color);
    while (true)
    {   
        draw_char(frame_buffer, font_descriptor, 10 + 8 * (3 + i) * 2, 10, buffer[i], 2, left_color);

        i++;
        if (buffer[i] == '\0')
        {
            break;
        }
    }


    /* Left bullets label */
    itoa(buffer, left_bullets);
    draw_char(frame_buffer, font_descriptor, 228 - 8 * 2 * 5, 10, buffer[0], 2, C_PINK);
    

    /* BULLETS label in the middle */
    draw_char(frame_buffer, font_descriptor, 228 - 8 * 2 * 3, 10, 'B', 2, C_PINK);
    draw_char(frame_buffer, font_descriptor, 228 - 8 * 2 * 2, 10, 'U', 2, C_PINK);
    draw_char(frame_buffer, font_descriptor, 228 - 8 * 2, 10, 'L', 2, C_PINK);
    draw_char(frame_buffer, font_descriptor, 228, 10, 'L', 2, C_PINK);
    draw_char(frame_buffer, font_descriptor, 228 + 8 * 2, 10, 'E', 2, C_PINK);
    draw_char(frame_buffer, font_descriptor, 228 + 8 * 2 * 2, 10, 'T', 2, C_PINK);
    draw_char(frame_buffer, font_descriptor, 228 + 8 * 2 * 3, 10, 'S', 2, C_PINK);


    /* Right bullets label */
    itoa(buffer, right_bullets);
    draw_char(frame_buffer, font_descriptor, 228 + 8 * 2 * 5, 10, buffer[0], 2, C_PINK);
    

    /* HP label right cowboy */
    i = 0;
    itoa(buffer, right_health);
    draw_char(frame_buffer, font_descriptor, 370, 10, 'H', 2, right_color);
    draw_char(frame_buffer, font_descriptor, 370 + 8 * 2, 10, 'P', 2, right_color);
    draw_char(frame_buffer, font_descriptor, 370 + 8 * 2 * 2, 10, ':', 2, right_color);
    while (true)
    {   
        draw_char(frame_buffer, font_descriptor, 370 + 8 * (3 + i) * 2, 10, buffer[i], 2, right_color);

        i++;
        if (buffer[i] == '\0')
        {
            break;
        }
    }
    i = 0;
}
