
#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include <stdbool.h>
#include <termios.h>

#include "font_types.h"
#include "mzapo_parlcd.h"

#ifdef __cplusplus
extern "C" {
#endif



#define REGTANGL_LEFT_UP_X 57
#define REGTANGLE_FRAME_HEIGHT 5
#define REGTANGLE_WIDTH 368
#define REGTANGLE_HEIGHT 54
#define CHAR_SCALE 3

void draw_char(unsigned short *frame_buffer, font_descriptor_t *font_descriptor, int x, int y, char ch, unsigned char scale, unsigned short color);

void draw_pixel(unsigned short *frame_buffer, int x, int y, unsigned short color);

void draw_pixel_scale(unsigned short *frame_buffer, int x, int y, unsigned char scale, unsigned short color);

unsigned int hsv2rgb_lcd(int hue, int saturation, int value);

void draw_rectangle(unsigned short *frame_buffer, int x, int y, int width, int height, int frame_height, unsigned short frame_color, unsigned short fill_color);

char getch();

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*DRAW_H*/

