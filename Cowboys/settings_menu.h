#ifndef SETTINGS_MENU_H
#define SETTINGS_MENU_H

#include "draw_settings_menu.h"
#include "settings.h"
#include "input_catcher.h"

#ifdef __cplusplus
extern "C" {
#endif

void start_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*SETTINGS_MENU_H*/