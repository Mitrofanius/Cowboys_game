
#ifndef DRAW_H
#define DRAW_H

#include "font_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void draw_char(unsigned short *frame_buffer, font_descriptor_t *font_descriptor, int x, int y, char ch, unsigned short color);

void draw_pixel(unsigned short *frame_buffer, int x, int y, unsigned short color);

void draw_pixel_big(unsigned short *frame_buffer, int x, int y, unsigned short color);

unsigned int hsv2rgb_lcd(int hue, int saturation, int value);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*DRAW_H*/

