#ifndef SETTINGS_H
#define SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    unsigned short player_left_color;
    unsigned short player_right_color;
    int bullet_speed;
    unsigned short bullet_color;
} settings_t;

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*SETTINGS_H*/
