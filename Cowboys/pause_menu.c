
#include "pause_menu.h"

void start_pause_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice)
{
    draw_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, *choice);

    char ch;
    while ((ch = getch(stdin)) != '\n')
    {
        if (ch == '\033')
        {
            getch(); // skip the [
            switch (getch())
            { // the real value
            case 'A':
                *choice = (*choice - 1 + 2) % 2;
                // code for arrow up
                break;
            case 'B':
                *choice = (*choice + 1) % 2;
                // code for arrow down
                break;
            default:
                break;
            }
        }

        draw_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, *choice);
    }
}