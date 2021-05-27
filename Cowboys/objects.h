#ifndef OBJECTS_H
#define OBJECTS_H

#include "objects.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short width;
    unsigned short height;
    unsigned short colour;
    unsigned short side;
    unsigned char state;
} cowboy_t;

typedef struct
{
    unsigned short x;
    unsigned short y;
    unsigned short width;
    unsigned short height;
} cactus_t;

typedef struct
{
    unsigned short x;
    unsigned short y;
    unsigned short width;
    unsigned short height;
} barrel_t;

typedef struct
{
    unsigned short x;
    unsigned short y;
    unsigned short width;
    unsigned short height;
} stone_t;

typedef struct
{
    unsigned short x;
    unsigned short y;
    unsigned short width;
    unsigned short height;
    int speed;
} bullet_t;

typedef struct
{
    cactus_t cactuses[5];
    unsigned char cactuses_length;

    barrel_t barrels[5];
    unsigned char barrels_length;

    stone_t stones[5];
    unsigned char stones_length;
    
    bullet_t bullets[4];
    unsigned char bullets_length;
} object_manager_t;


#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*OBJECTS_H*/