#ifndef GAME_H
#define GAME_H

#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdbool.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "serialize_lock.h"

#include "settings.h"
#include "scenes.h"
#include "draw.h"

#ifdef __cplusplus
extern "C" {
#endif

void start_game(unsigned char *parlcd_mem_base, unsigned char *led_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*GAME_H*/