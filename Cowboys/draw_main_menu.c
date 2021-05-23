
#include "draw_main_menu.h"

void draw_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *const choice)
{
    int i;
    /* Background */
    for (i = 0; i < 320 * 480; i++)
    {
        frame_buffer[i] = 0xCCCE;
    }

    /* 1 PLAYER rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 22, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);
    /* 2 PLAYERS rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 98, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);
    /* STTINGS rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 173, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);
    /* EXIT rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 247, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);


    /* CHOICE rectangle */
    draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 22 + *choice * 75, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x9CF3);


    /* 1 PLAYER label */
    draw_char(frame_buffer, font_descriptor, 88, 25, '1', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 132, 25, 'P', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 176, 25, 'L', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 220, 25, 'A', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 264, 25, 'Y', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 308, 25, 'E', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 352, 25, 'R', CHAR_SCALE, 0xFFFF);

    /* 2 PLAYERS label */
    draw_char(frame_buffer, font_descriptor, 66, 101, '2', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 110, 101, 'P', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 154, 101, 'L', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 198, 101, 'A', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 242, 101, 'Y', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 101, 'E', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 330, 101, 'R', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 374, 101, 'S', CHAR_SCALE, 0xFFFF);

    /* SETTINGS label */
    draw_char(frame_buffer, font_descriptor, 84, 176, 'S', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 128, 176, 'E', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 172, 176, 'T', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 216, 176, 'T', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 260, 176, 'I', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 176, 'N', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 330, 176, 'G', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 374, 176, 'S', CHAR_SCALE, 0xFFFF);

    /* EXIT label */
    draw_char(frame_buffer, font_descriptor, 172, 250, 'E', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 216, 250, 'X', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 260, 250, 'I', CHAR_SCALE, 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 250, 'T', CHAR_SCALE, 0xFFFF);


    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}
