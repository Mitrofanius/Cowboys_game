
#include "draw.h"

void draw_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer,
                        font_descriptor_t *font_descriptor, cowboy_t *cowboy_left,
                        cowboy_t *cowboy_right, unsigned char choice_button, unsigned char choice_left_player_color,
                        unsigned char choice_right_player_color, int choice_bullet_speed)
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
    draw_cowboy(parlcd_mem_base, frame_buffer, cowboy_left, 3);
    draw_rectangle(frame_buffer, 124 + 51 * choice_left_player_color, 26, 48, 48, 3, C_WHITE, C_WHITE);
    draw_rectangle(frame_buffer, 127, 29, 42, 42, 0, C_RED, C_RED);
    draw_rectangle(frame_buffer, 178, 29, 42, 42, 0, C_LIGHT_BLUE, C_LIGHT_BLUE);
    draw_rectangle(frame_buffer, 229, 29, 42, 42, 0, C_LIGHT_GREEN, C_LIGHT_GREEN);
    draw_rectangle(frame_buffer, 280, 29, 42, 42, 0, C_DARK_ORANGE, C_DARK_ORANGE);
    draw_rectangle(frame_buffer, 331, 29, 42, 42, 0, C_PINK, C_PINK);
    draw_rectangle(frame_buffer, 382, 29, 42, 42, 0, C_PURPLE, C_PURPLE);


    // Right player color settings
    if (choice_button == PLAYER_RIGHT_COLOUR)
    {
        draw_rectangle(frame_buffer, 54, 97, 66, 57, 3, 0x9CF3, 0x9CF3);
    }
    draw_cowboy(parlcd_mem_base, frame_buffer, cowboy_right, 3);
    draw_rectangle(frame_buffer, 124 + 51 * choice_right_player_color, 102, 48, 48, 3, C_WHITE, C_WHITE);
    draw_rectangle(frame_buffer, 127, 105, 42, 42, 0, C_RED, C_RED);
    draw_rectangle(frame_buffer, 178, 105, 42, 42, 0, C_LIGHT_BLUE, C_LIGHT_BLUE);
    draw_rectangle(frame_buffer, 229, 105, 42, 42, 0, C_LIGHT_GREEN, C_LIGHT_GREEN);
    draw_rectangle(frame_buffer, 280, 105, 42, 42, 0, C_DARK_ORANGE, C_DARK_ORANGE);
    draw_rectangle(frame_buffer, 331, 105, 42, 42, 0, C_PINK, C_PINK);
    draw_rectangle(frame_buffer, 382, 105, 42, 42, 0, C_PURPLE, C_PURPLE);


    /* Bullet speed settings */
    if (choice_button == BULLET_SPEED)
    {
        draw_rectangle(frame_buffer, 52, 174, 134, 52, 3, 0x9CF3, 0x9CF3);
    }
    else
    {
        draw_rectangle(frame_buffer, 52, 174, 134, 52, 3, 0x49A5, 0x9B01);
    }
    draw_char(frame_buffer, font_descriptor, 59, 176, 'M', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 108, 176, 'P', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 147, 176, 'H', CHAR_SCALE, 0xFFFF);
    draw_rectangle(frame_buffer, 196, 176, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 241, 176, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 286, 176, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 331, 176, 48, 48, 3, C_WHITE, 0xCCCE);
    draw_rectangle(frame_buffer, 376, 176, 48, 48, 3, C_WHITE, 0xCCCE);
    for (int i = 0; i <= choice_bullet_speed; i++)
    {
        draw_rectangle(frame_buffer, 199 + i * 45, 179, 42, 42, 0, 0x9CF3, 0x9CF3);
    }
    

    /* BACK rectangle */
    if (choice_button == BACK)
    {
        draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 22 + choice_button * 75, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x9CF3);
    }
    else
    {
        draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 247, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x9B01);
    }

    /* EXIT label */
    draw_char(frame_buffer, font_descriptor, 172, 250, 'B', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 216, 250, 'A', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 250, 250, 'C', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 250, 'K', CHAR_SCALE, 0xFFFF);

    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}
