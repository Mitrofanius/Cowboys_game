#include <colours.h>

unsigned short cowboy_blue_aiming[] = {
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_BLACK, C_BLACK, C_SKIN, C_SKIN, C_BLACK, C_BLACK, C_SKIN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, C_GRAY, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_GRAY, C_GRAY, C_GRAY,
    __NO__, __NO__, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_RED, C_RED, C_SKIN, C_SKIN, C_SKIN, C_GRAY, C_GRAY, C_GRAY, C_GRAY, C_BLACK, C_BLACK, C_BLACK, C_BLACK,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_GRAY, C_BLACK, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_SKIN, C_SKIN, C_BLACK, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_BROWN, C_BROWN, C_BROWN, C_WHITE, C_WHITE, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, C_LIGHT_BLUE, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_SKIN, C_SKIN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BROWN, C_BROWN, __NO__, C_BROWN, C_BROWN, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BLACK, C_BLACK, __NO__, C_BLACK, C_BLACK, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__, __NO__};

void draw_cowboy_blue_aiming(unsigned short *frame_buffer, int x, int y, int scale)
{
    int h = 17;
    int w = 20;
    int i, j;

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (cowboy_blue_aiming[i * w + j] != __NO__)
            {
                draw_pixel_big(frame_buffer, x + scale * j, y + scale * i, cowboy_blue_aiming[i * w + j], scale);
            }
        }
    }
}

// unsigned short get_cowboy_blue_aiming(int i, int j){

// }