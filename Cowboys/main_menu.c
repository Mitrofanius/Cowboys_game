
#include "main_menu.h"

void start_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice)
{   
    draw_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, choice);
    
    unsigned char ch;
    while ((ch = getch(stdin)) != '\n')
    {   
        if (ch == 'w') 
        {
            *choice = (*choice - 1 + 4) % 4;
        }
        else if (ch == 's') 
        {
            *choice = (*choice + 1) % 4;
        }

        draw_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, choice);
    }   
}