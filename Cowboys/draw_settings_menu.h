#ifndef DRAW_SETTINGS_MENU_H
#define DRAW_SETTINGS_MENU_H

#include "draw.h"

#ifdef __cplusplus
extern "C" {
#endif

void draw_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *const choice);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*DRAW_SETTINGS_MENU_H*/
