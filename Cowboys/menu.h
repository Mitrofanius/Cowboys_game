#ifndef MENU_H
#define MENU_H

#include <stdio.h>

#include "mzapo_parlcd.h"
#include "draw.h"


#ifdef __cplusplus
extern "C" {
#endif

#define ONE_PLAYER_GAME 0
#define TWO_PLAYERS_GAME 1
#define SETTINGS 2

void start_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, char *choice);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*MENU_H*/