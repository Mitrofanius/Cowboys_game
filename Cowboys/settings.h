#ifndef SETTING_H
#define SETTING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    unsigned short player_left_color;
    unsigned short player_right_color;
    int bullet_speed;
} settings_t;


#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*SETTING_H*/