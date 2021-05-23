
#include "settings_menu.h"

void start_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{   
    unsigned char choice = BACK;
    draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);
    
    unsigned char ch;
    while (true)
    {   
        ch = getch(stdin);
        
        if (ch == 'w') 
        {
            choice = (choice - 1 + 1) % 1;
        }
        else if (ch == 's') 
        {
            choice = (choice + 1) % 1;
        }
        else if (ch == '\n') {
            if (choice == BACK)
            {
                break;
            }
            
        }

        draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);
    }
}
