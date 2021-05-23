#ifndef INPUT_CATCHER_H
#define INPUT_CATCHER_H

#include <stdio.h>
#include <termios.h>

#define ESCAPE 27

#ifdef __cplusplus
extern "C" {
#endif

char getch();

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif  /*INPUT_CATCHER_H*/