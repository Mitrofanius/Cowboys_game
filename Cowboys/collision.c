
#include "collision.h"

bool isOnMap(cowboy_t *cowboy, unsigned char scale)
{
    bool answer = true;

    if (cowboy->direction == UP)
    {
        if (cowboy->y - COWBOY_RELOCATION < 0)
        {
            answer = false;
        }
    }
    else if (cowboy->direction == DOWN)
    {
        if (cowboy->y + COWBOY_RELOCATION + cowboy->height * scale > 320)
        {
            answer = false;
        }
    }

    return answer;
}