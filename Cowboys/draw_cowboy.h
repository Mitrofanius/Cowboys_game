
#ifndef DRAW_COWBOY_H
#define DRAW_COWBOY_H

#include "draw.h"

#define AIMING 0
#define RUNNING 1
#define DEAD 2

#define LEFT 0
#define RIGHT 1

#ifdef __cplusplus
extern "C" {
#endif

void draw_cowboy(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, cowboy_t *cowboy, unsigned short scale);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*DRAW_COWBOY_H*/