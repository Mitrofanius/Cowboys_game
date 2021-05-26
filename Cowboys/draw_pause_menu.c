
#include "draw.h"

void draw_pause_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *const choice)
{
    int i;
    /* Background */
    for (i = 0; i < 320 * 480; i++)
    {
        frame_buffer[i] = 0xCCCE;
    }


    /* RESUME rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 98, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);
    /* MAIN MENU rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 173, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);


    /* CHOICE rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 22 + (*choice + 1) * 75, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x9CF3);


    /* 2 PLAYERS label */
    draw_char(frame_buffer, font_descriptor, 110, 101, 'R', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 154, 101, 'E', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 198, 101, 'S', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 242, 101, 'U', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 101, 'M', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 330, 101, 'E', CHAR_SCALE, 0xFFFF);

    /* SETTINGS label */
    draw_char(frame_buffer, font_descriptor, 84, 176, 'M', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 128, 176, 'A', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 162, 176, 'I', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 188, 176, 'N', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 242, 176, 'M', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 176, 'E', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 330, 176, 'N', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 374, 176, 'U', CHAR_SCALE, 0xFFFF);


    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}
