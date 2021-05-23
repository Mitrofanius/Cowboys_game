#ifndef DRAW_SCENE_ANIMATION_H
#define DRAW_SCENE_ANIMATION_H

#include "draw.h"

#ifdef __cplusplus
extern "C" {
#endif

void draw_loading_scene(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);

void draw_closing_scene(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*DRAW_SCENE_ANIMATION_H*/