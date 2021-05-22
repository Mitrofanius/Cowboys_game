
#include "menu.h"

void start_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, char *choice)
{   
    char ch;
    while ((ch = getc(stdin)) != 'q')
    {   
        draw_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, choice);

        if (ch == 'w') 
        {
            *choice = (*choice - 1 + 4) % 4;
        }
        else if (ch == 's') 
        {
            *choice = (*choice + 1) % 4;
        }
    }   
}