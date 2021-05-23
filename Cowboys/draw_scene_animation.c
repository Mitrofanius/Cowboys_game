
#include "draw_scene_animation.h"

void draw_loading_scene(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    int i, k;
    char modulo_time = 0;
    char modulo_char = 0;

    for (i = 0; i <= REGTANGLE_WIDTH - REGTANGLE_FRAME_HEIGHT * 2; i += 4)
    {   
        
        /* Background */
        for (k = 0; k < 320 * 480; k++)
        {
            frame_buffer[k] = 0xCCCE;
        }
        /* Loading rectangle */
        draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 173, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);

        /* Progress rectangle */
        draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X + REGTANGLE_FRAME_HEIGHT, 173 + REGTANGLE_FRAME_HEIGHT, i, REGTANGLE_HEIGHT - REGTANGLE_FRAME_HEIGHT * 2, 0, 0, 0xFFFF);

        /* Loading label */
        draw_char(frame_buffer, font_descriptor, 66, 101, 'L', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 110, 101, 'O', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 154, 101, 'A', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 198, 101, 'D', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 242, 101, 'I', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 286, 101, 'N', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 330, 101, 'G', CHAR_SCALE, 0xFFFF);
        
        /* Animation */
        if (modulo_char == 0) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '|', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 1) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '/', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 2) 
        {
            draw_char(frame_buffer, font_descriptor, 370, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 378, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 390, 101, '-', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 3) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '\\', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 4) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '|', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 5) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '/', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 6) 
        {
            draw_char(frame_buffer, font_descriptor, 370, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 378, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 390, 101, '-', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 7) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '\\', CHAR_SCALE, 0xFFFF);
        }

        /* Timer for anmation */
        if (modulo_time % 10 == 0)
        {
            modulo_char = (modulo_char + 1) % 8;
        }

        /* Sends info to screen */
        parlcd_write_cmd(parlcd_mem_base, 0x2c);
        for (k = 0; k < 480 * 320; k++)
        {
            parlcd_write_data(parlcd_mem_base, frame_buffer[k]);
        }

        modulo_time++;
    }
}

void draw_closing_scene(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    int i, k;
    char modulo_time = 0;
    char modulo_char = 0;

    for (i = 0; i <= REGTANGLE_WIDTH - REGTANGLE_FRAME_HEIGHT * 2; i += 4)
    {   
        
        /* Background */
        for (k = 0; k < 320 * 480; k++)
        {
            frame_buffer[k] = 0xCCCE;
        }
        /* Loading rectangle */
        draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X, 173, REGTANGLE_WIDTH, REGTANGLE_HEIGHT, REGTANGLE_FRAME_HEIGHT, 0, 0x49A5);

        /* Progress rectangle */
        draw_rectangle(frame_buffer, REGTANGL_LEFT_UP_X + REGTANGLE_FRAME_HEIGHT, 173 + REGTANGLE_FRAME_HEIGHT, i, REGTANGLE_HEIGHT - REGTANGLE_FRAME_HEIGHT * 2, 0, 0, 0xFFFF);

        /* Closing label */
        draw_char(frame_buffer, font_descriptor, 66, 101, 'C', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 110, 101, 'L', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 154, 101, 'O', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 198, 101, 'S', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 242, 101, 'I', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 286, 101, 'N', CHAR_SCALE, 0xFFFF);
        draw_char(frame_buffer, font_descriptor, 330, 101, 'G', CHAR_SCALE, 0xFFFF);
        
        /* Animation */
        if (modulo_char == 0) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '|', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 1) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '/', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 2) 
        {
            draw_char(frame_buffer, font_descriptor, 370, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 378, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 390, 101, '-', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 3) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '\\', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 4) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '|', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 5) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '/', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 6) 
        {
            draw_char(frame_buffer, font_descriptor, 370, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 378, 101, '-', CHAR_SCALE, 0xFFFF);
            draw_char(frame_buffer, font_descriptor, 390, 101, '-', CHAR_SCALE, 0xFFFF);
        }
        else if (modulo_char == 7) 
        {
            draw_char(frame_buffer, font_descriptor, 379, 101, '\\', CHAR_SCALE, 0xFFFF);
        }

        /* Timer for anmation */
        if (modulo_time % 10 == 0)
        {
            modulo_char = (modulo_char + 1) % 8;
        }

        /* Sends info to screen */
        parlcd_write_cmd(parlcd_mem_base, 0x2c);
        for (k = 0; k < 480 * 320; k++)
        {
            parlcd_write_data(parlcd_mem_base, frame_buffer[k]);
        }

        modulo_time++;
    }
}
