#ifndef COLLISION_H
#define COLLISION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "objects.h"

bool isOnMap(cowboy_t *cowboy, unsigned char scale);

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*COLLISION_H*/