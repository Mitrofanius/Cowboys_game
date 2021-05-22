#ifndef GAME_H
#define GAME_H

#include "draw.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

void start_game(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*GAME_H*/