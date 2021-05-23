#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "draw_pause_menu.h"
#include "input_catcher.h"

#define MAIN_MENU 1

#ifdef __cplusplus
extern "C" {
#endif

void start_pause_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, unsigned char *choice);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*PAUSE_MENU_H*/