#ifndef OBJECTS_H
#define OBJECTS_H

#define BARREL_AMOUNT 5
#define STONE_AMOUNT 5
#define CACTUS_AMOUNT 5
#define BULLET_AMOUNT 4

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        unsigned short x;
        unsigned short y;
        unsigned short width;
        unsigned short height;
        unsigned short color;
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
        unsigned short color;
        int speed;
    } bullet_t;

    typedef struct
    {
        cactus_t cactuses[CACTUS_AMOUNT];
        unsigned char cactuses_length;

        barrel_t barrels[BARREL_AMOUNT];
        unsigned char barrels_length;

        stone_t stones[STONE_AMOUNT];
        unsigned char stones_length;

        bullet_t bullets[BULLET_AMOUNT];
        unsigned char bullets_length;
    } object_manager_t;

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*OBJECTS_H*/