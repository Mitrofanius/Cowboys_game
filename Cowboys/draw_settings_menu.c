
#include "draw_settings_menu.h"

void draw_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *const choice)
{
    int i;
    /* Background */
    for (i = 0; i < 320 * 480; i++)
    {
        frame_buffer[i] = 0xCCCE;
    }


    /* BACK rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 247, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);


    /* CHOICE rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 22 + (*choice + 3)* 75, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x9CF3);


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
