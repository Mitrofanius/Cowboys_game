#include <stdint.h>
#include "draw.h"

#ifndef COLOURS_H
#define COLOURS_H

#define C_SKY 0x14FB
#define C_BLACK 0x0
#define C_WHITE 0xFF00
#define C_LIGHT_BLUE 0x6D99
#define C_DARK_ORANGE 0xC2A2
#define C_LIGHT_ORANGE 0xED04
#define C_SKIN 0xFDEF
#define C_DARK_GREEN 0x0480
#define C_LIGHT_GREEN 0x0
#define C_RED 0xD882
#define C_LIGHT_YELLOW 0xE763
#define C_DARK_RED 0xCB61
#define C_BROWN 0xCB61
#define C_GRAY 0x3186
#define C_LIGHT_GRAY 0x632C
#define C_DARK_YELLOW 0xB620
#define __NO__ 0x1111

void draw_cowboy_blue_aiming(unsigned short *frame_buffer, int x, int y, int scale);
unsigned short get_cowboy_blue_aiming(int i, int j);

#endif /*COLOURS_H*/