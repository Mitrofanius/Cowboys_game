#ifndef INPUT_CATCHER_H
#define INPUT_CATCHER_H

#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <sys/time.h>
#include <sys/types.h>

#define ESCAPE 27

#ifdef __cplusplus
extern "C"
{
#endif

    char getch();

#ifdef __cplusplus
} /* extern "C"*/
#endif

#endif /*INPUT_CATCHER_H*/