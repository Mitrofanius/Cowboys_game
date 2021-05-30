
#include "scenes.h"

void start_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice)
{
    font_descriptor = &font_winFreeSystem14x16;
    
    draw_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, choice);

    unsigned char ch;

    while ((ch = getch(stdin)) != '\n')
    {
        if (ch == '\033')
        {
            getch(); // skip the [
            switch (getch())
            { // the real value
            case 'A':
                *choice = (*choice - 1 + 4) % 4;
                // code for arrow up
                break;
            case 'B':
                *choice = (*choice + 1) % 4;
                // code for arrow down
                break;
            default:
                fflush(stdin);
                break;
            }
        }

        draw_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, choice);
    }
}