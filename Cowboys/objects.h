#ifndef OBJECTS_H
#define OBJECTS_H

#define AIMING 0
#define RUNNING 1
#define DEAD 2

#define COWBOY_RELOCATION 3

#define COWBOY_LEFT_X 15
#define COWBOY_LEFT_Y 130
#define COWBOY_RIGHT_X 405
#define COWBOY_RIGHT_Y 130

#define COWBOY_DEAD_WIDTH 18
#define COWBOY_DEAD_HEIGHT 15
#define COWBOY_RUNNING_WIDTH 14
#define COWBOY_RUNNING_HEIGHT 17
#define COWBOY_AIMING_WIDTH 20
#define COWBOY_AIMING_HEIGHT 17

#define UP 0
#define DOWN 1

#define BARREL_WIDTH 11
#define BARREL_HEIGHT 13
#define STONE_WIDTH 10
#define STONE_HEIGHT 9
#define CACTUS_WIDTH 10
#define CACTUS_HEIGHT 13
#define BULLET_WIDTH 4
#define BULLET_HEIGHT 4

#define BARREL_AMOUNT 5
#define STONE_AMOUNT 5
#define CACTUS_AMOUNT 5
#define BULLET_AMOUNT 4

#define COWBOY_HEALTH 100

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
        unsigned char side;
        unsigned char state;
        unsigned char health;
        unsigned char direction;
        unsigned char bullets;
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