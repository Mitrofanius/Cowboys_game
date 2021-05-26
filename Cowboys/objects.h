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
    cactus_t cactus[5];
    unsigned char cactus_length;

    barrel_t barrel[5];
    unsigned char barrel_length;

    stone_t stone[5];
    unsigned char stone_length;
    
    bullet_t bullet[4];
    unsigned char bullet_length;
} object_manager_t;


#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*OBJECTS_H*/