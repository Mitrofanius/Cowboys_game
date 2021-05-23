
#include "pause_menu.h"

void start_pause_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice)
{   
    draw_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, choice);
    
    char ch;
    while ((ch = getch(stdin)) != '\n')
    {   
        if (ch == 'w') 
        {
            *choice = (*choice - 1 + 2) % 2;
        }
        else if (ch == 's') 
        {
            *choice = (*choice + 1) % 2;
        }

        draw_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, choice);
    }   
}