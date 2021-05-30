
#include "draw.h"

void draw_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer,
                        font_descriptor_t *font_descriptor, cowboy_t *cowboy_left,
                        cowboy_t *cowboy_right, bullet_t *bullet, unsigned char choice_button, unsigned char choice_left_player_color,
                        unsigned char choice_right_player_color, unsigned char choice_bullet_color, int choice_bullet_speed)
{
    int i;
    /* Background */
    for (i = 0; i < 320 * 480; i++)
    {
        frame_buffer[i] = 0xBC06;
    }


    // left player color settings
    if (choice_button == PLAYER_LEFT_COLOUR)
    {
        draw_rectangle(frame_buffer, 54, 21, 66, 57, 3, 0x9CF3, 0x9CF3);
    }
    draw_cowboy(frame_buffer, cowboy_left, 3);
    draw_rectangle(frame_buffer, 124 + 51 * choice_left_player_color, 26, 48, 48, 3, C_WHITE, C_WHITE);
    draw_rectangle(frame_buffer, 127, 29, 42, 42, 0, C_RED, C_RED);
    draw_rectangle(frame_buffer, 178, 29, 42, 42, 0, C_LIGHT_BLUE, C_LIGHT_BLUE);
    draw_rectangle(frame_buffer, 229, 29, 42, 42, 0, C_LIGHT_GREEN, C_LIGHT_GREEN);
    draw_rectangle(frame_buffer, 280, 29, 42, 42, 0, C_LIGHT_YELLOW, C_LIGHT_YELLOW);
    draw_rectangle(frame_buffer, 331, 29, 42, 42, 0, C_PINK, C_PINK);
    draw_rectangle(frame_buffer, 382, 29, 42, 42, 0, C_LIGHT_GRAY, C_LIGHT_GRAY);


    // Right player color settings
    if (choice_button == PLAYER_RIGHT_COLOUR)
    {
        draw_rectangle(frame_buffer, 54, 97, 66, 57, 3, 0x9CF3, 0x9CF3);
    }
    draw_cowboy(frame_buffer, cowboy_right, 3);
    draw_rectangle(frame_buffer, 124 + 51 * choice_right_player_color, 102, 48, 48, 3, C_WHITE, C_WHITE);
    draw_rectangle(frame_buffer, 127, 105, 42, 42, 0, C_RED, C_RED);
    draw_rectangle(frame_buffer, 178, 105, 42, 42, 0, C_LIGHT_BLUE, C_LIGHT_BLUE);
    draw_rectangle(frame_buffer, 229, 105, 42, 42, 0, C_LIGHT_GREEN, C_LIGHT_GREEN);
    draw_rectangle(frame_buffer, 280, 105, 42, 42, 0, C_LIGHT_YELLOW, C_LIGHT_YELLOW);
    draw_rectangle(frame_buffer, 331, 105, 42, 42, 0, C_PINK, C_PINK);
    draw_rectangle(frame_buffer, 382, 105, 42, 42, 0, C_LIGHT_GRAY, C_LIGHT_GRAY);

    /* Bullet color settings */
    if (choice_button == BULLET_COLOR)
    {
        draw_rectangle(frame_buffer, 54, 173, 66, 57, 3, 0x9CF3, 0x9CF3);
    }
    draw_bullet(frame_buffer, bullet, 12);
    draw_rectangle(frame_buffer, 124 + 51 * choice_bullet_color, 178, 48, 48, 3, C_WHITE, C_WHITE);
    draw_rectangle(frame_buffer, 127, 181, 42, 42, 0, C_RED, C_RED);
    draw_rectangle(frame_buffer, 178, 181, 42, 42, 0, C_LIGHT_BLUE, C_LIGHT_BLUE);
    draw_rectangle(frame_buffer, 229, 181, 42, 42, 0, C_LIGHT_GREEN, C_LIGHT_GREEN);
    draw_rectangle(frame_buffer, 280, 181, 42, 42, 0, C_LIGHT_YELLOW, C_LIGHT_YELLOW);
    draw_rectangle(frame_buffer, 331, 181, 42, 42, 0, C_PINK, C_PINK);
    draw_rectangle(frame_buffer, 382, 181, 42, 42, 0, C_LIGHT_GRAY, C_LIGHT_GRAY);

    /* Bullet speed settings */
    if (choice_button == BULLET_SPEED)
    {
        draw_rectangle(frame_buffer, 52, 247, 134, 52, 3, 0x9CF3, 0x9CF3);
    }
    else
    {
        draw_rectangle(frame_buffer, 52, 247, 134, 52, 3, 0x49A5, 0x9B01);
    }
    draw_char(frame_buffer, font_descriptor, 59, 250, 'M', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 108, 250, 'P', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 147, 250, 'H', CHAR_SCALE, 0xFFFF);
    draw_rectangle(frame_buffer, 196, 250, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 241, 250, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 286, 250, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 331, 250, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 376, 250, 48, 48, 3, C_WHITE, 0xCCCE);
    for (int i = 0; i <= choice_bullet_speed; i++)
    {
        draw_rectangle(frame_buffer, 199 + i * 45, 253, 42, 42, 0, 0x9CF3, 0x9CF3);
    }

    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}
