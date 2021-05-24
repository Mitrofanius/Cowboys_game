#ifndef COWBOY_H
#define COWBOY_H

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

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*COWBOY_H*/