#include "draw.h"

unsigned short barrel_pixels[] = {
    __NO__, __NO__, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, __NO__, __NO__,
    __NO__, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, __NO__,
    C_DARK_ORANGE, C_SKIN, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_SKIN, C_DARK_ORANGE,
    C_DARK_ORANGE, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, C_DARK_ORANGE,
    C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE,
    C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE,
    C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE,
    C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE,
    C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE,
    C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE,
    C_BLACK, C_DARK_ORANGE, C_DARK_ORANGE, C_SKIN, C_SKIN, C_SKIN, C_DARK_ORANGE, C_SKIN, C_DARK_ORANGE, C_DARK_ORANGE, C_BLACK,
    __NO__, C_BLACK, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_DARK_ORANGE, C_BLACK, __NO__,
    __NO__, __NO__, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_BLACK, __NO__, __NO__
};

unsigned short stone_pixels[] = {
    __NO__, __NO__, __NO__, __NO__, C_LIGHT_GRAY, C_LIGHT_GRAY, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, __NO__, __NO__, __NO__,
    __NO__, __NO__, C_LIGHT_GRAY, C_LIGHT_GRAY, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_LIGHT_GRAY, __NO__, __NO__,
    __NO__, C_LIGHT_GRAY, C_LIGHT_GRAY, C_WHITE, C_WHITE, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_LIGHT_GRAY, __NO__,
    C_LIGHT_GRAY, C_LIGHT_GRAY, C_WHITE, C_WHITE, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY,
    C_LIGHT_GRAY, C_WHITE, C_WHITE, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_LIGHT_GRAY,
    C_LIGHT_GRAY, C_WHITE, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_BLACK, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_LIGHT_GRAY,
    __NO__, C_BLACK, C_WHITE, C_WHITE, C_LIGHT_GRAY, C_BLACK, C_BLACK, C_LIGHT_GRAY, C_LIGHT_GRAY, C_BLACK,
    __NO__, __NO__, C_BLACK, C_BLACK, C_BLACK, __NO__, __NO__, C_BLACK, C_BLACK, __NO__
};

unsigned short bullet_pixels[] = {
    __NO__, C_LIGHT_GRAY, C_LIGHT_GRAY, __NO__,
    C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY,
    C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY, C_LIGHT_GRAY,
    __NO__, C_LIGHT_GRAY, C_LIGHT_GRAY, __NO__
};

unsigned short cactus_pixels[] = {
    __NO__, __NO__, __NO__, __NO__, C_DARK_GREEN, C_DARK_GREEN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_DARK_GREEN, C_DARK_GREEN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_LIGHT_GREEN, C_LIGHT_GREEN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_LIGHT_GREEN, C_LIGHT_GREEN, __NO__, __NO__, __NO__, __NO__,
    C_DARK_GREEN, C_DARK_GREEN, __NO__, __NO__, C_LIGHT_GREEN, C_LIGHT_GREEN, __NO__, __NO__, C_DARK_GREEN, C_DARK_GREEN,
    C_DARK_GREEN, C_DARK_GREEN, __NO__, __NO__, C_LIGHT_GREEN, C_LIGHT_GREEN, __NO__, __NO__, C_DARK_GREEN, C_DARK_GREEN,
    C_LIGHT_GREEN, C_LIGHT_GREEN, C_DARK_GREEN, C_DARK_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_DARK_GREEN, C_DARK_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN,
    C_LIGHT_GREEN, C_LIGHT_GREEN, C_DARK_GREEN, C_DARK_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_DARK_GREEN, C_DARK_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN,
    C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN,
    C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN, C_LIGHT_GREEN,
    C_BLACK, C_BLACK, C_BLACK, C_BLACK, C_LIGHT_GREEN, C_LIGHT_GREEN, C_BLACK, C_BLACK, C_BLACK, C_BLACK,
    __NO__, __NO__, __NO__, __NO__, C_LIGHT_GREEN, C_LIGHT_GREEN, __NO__, __NO__, __NO__, __NO__,
    __NO__, __NO__, __NO__, __NO__, C_BLACK, C_BLACK, __NO__, __NO__, __NO__, __NO__
};

void draw_objects(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, object_manager_t *object_manager, int scale)
{
    int i;

    for (i = 0; i < object_manager->barrels_length; i++)
    {
        draw_barrel(parlcd_mem_base, frame_buffer, &(object_manager->barrels[i]), scale);
    }

    for (i = 0; i < object_manager->stones_length; i++)
    {
        draw_stone(parlcd_mem_base, frame_buffer, &(object_manager->stones[i]), scale);
    }

    for (i = 0; i < object_manager->cactuses_length; i++)
    {
        draw_cactus(parlcd_mem_base, frame_buffer, &(object_manager->cactuses[i]), scale);
    }

    for (i = 0; i < object_manager->bullets_length; i++)
    {
        draw_bullet(parlcd_mem_base, frame_buffer, &(object_manager->bullets[i]), scale);
    }
}

void draw_cactus(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, cactus_t *cactus, int scale)
{
    int i, j;

    for (i = 0; i < cactus->height; i++)
    {
        for (j = 0; j < cactus->width; j++)
        {
            if (cactus_pixels[i * cactus->width + j] != __NO__)
            {
                draw_pixel_scale(frame_buffer, cactus->x + scale * j, cactus->y + scale * i, scale, cactus_pixels[i * cactus->width + j]);
            }
        }
    }
}

void draw_bullet(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, bullet_t *bullet, int scale)
{
    int i, j;

    for (i = 0; i < bullet->height; i++)
    {
        for (j = 0; j < bullet->width; j++)
        {
            if (bullet_pixels[i * bullet->width + j] != __NO__)
            {
                //draw_pixel_scale(frame_buffer, bullet->x + scale * j, bullet->y + scale * i, scale, bullet_pixels[i * bullet->width + j]);
                draw_pixel_scale(frame_buffer, bullet->x + scale * j, bullet->y + scale * i, scale, C_LIGHT_GREEN);
            }
        }
    }
}

void draw_stone(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, stone_t *stone, int scale)
{
    int i, j;

    for (i = 0; i < stone->height; i++)
    {
        for (j = 0; j < stone->width; j++)
        {
            if (stone_pixels[i * stone->width + j] != __NO__)
            {
                draw_pixel_scale(frame_buffer, stone->x + scale * j, stone->y + scale * i, scale, stone_pixels[i * stone->width + j]);
            }
        }
    }
}

void draw_barrel(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, barrel_t *barrel, int scale)
{
    int i, j;

    for (i = 0; i < barrel->height; i++)
    {
        for (j = 0; j < barrel->width; j++)
        {
            if (barrel_pixels[i * barrel->width + j] != __NO__)
            {
                draw_pixel_scale(frame_buffer, barrel->x + scale * j, barrel->y + scale * i, scale, barrel_pixels[i * barrel->width + j]);
            }
        }
    }
}
