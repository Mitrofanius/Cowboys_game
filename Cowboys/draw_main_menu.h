#ifndef DRAW_MAIN_MENU_H
#define DRAW_MAIN_MENU_H

#include "draw.h"

#ifdef __cplusplus
extern "C" {
#endif

void draw_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, char *choice);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*DRAW_MAIN_MENU_H*/

