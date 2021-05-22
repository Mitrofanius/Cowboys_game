
#include "draw.h"

#define SCALE 3
 
void draw_char(unsigned short *frame_buffer, font_descriptor_t *font_descriptor, int x, int y, char ch, unsigned short color)
{
    // int w = char_width(ch);
    int w = 14;
    const font_bits_t *ptr;

    if ((ch >= font_descriptor->firstchar) && (ch - font_descriptor->firstchar < font_descriptor->size))
    {
        if (font_descriptor->offset)
        {
            ptr = &font_descriptor->bits[font_descriptor->offset[ch - font_descriptor->firstchar]];
        }
        else
        {
            int bw = (font_descriptor->maxwidth + 15) / 16;
            ptr = &font_descriptor->bits[(ch - font_descriptor->firstchar) * bw * font_descriptor->height];
        }
        int i, j;

        for (i = 0; i < font_descriptor->height; i++)
        {
            font_bits_t val = *ptr;
            for (j = 0; j < w; j++)
            {
                if ((val & 0x8000) != 0)
                {
                    draw_pixel_big(frame_buffer, x + SCALE * j, y + SCALE * i, color);
                }
                val <<= 1;
            }
            ptr++;
        }
    }
}

void draw_pixel(unsigned short *frame_buffer, int x, int y, unsigned short color)
{
    if (x >= 0 && x < 480 && y >= 0 && y < 320)
    {
        frame_buffer[x + 480 * y] = color;
    }
}

void draw_pixel_big(unsigned short *frame_buffer, int x, int y, unsigned short color)
{
    int i, j;
    for (i = 0; i < SCALE; i++)
    {
        for (j = 0; j < SCALE; j++)
        {
            draw_pixel(frame_buffer, x + i, y + j, color);
        }
    }
}

unsigned int hsv2rgb_lcd(int hue, int saturation, int value)
{
    hue = (hue % 360);
    float f = ((hue % 60) / 60.0);
    int p = (value * (255 - saturation)) / 255;
    int q = (value * (255 - (saturation * f))) / 255;
    int t = (value * (255 - (saturation * (1.0 - f)))) / 255;

    unsigned int r, g, b;

    if (hue < 60)
    {
        r = value;
        g = t;
        b = p;
    }
    else if (hue < 120)
    {
        r = q;
        g = value;
        b = p;
    }
    else if (hue < 180)
    {
        r = p;
        g = value;
        b = t;
    }
    else if (hue < 240)
    {
        r = p;
        g = q;
        b = value;
    }
    else if (hue < 300)
    {
        r = t;
        g = p;
        b = value;
    }
    else
    {
        r = value;
        g = p;
        b = q;
    }

    r >>= 3;
    g >>= 2;
    b >>= 3;

    return (((r & 0x1f) << 11) | ((g & 0x3f) << 5) | (b & 0x1f));
}

void draw_rectangle(unsigned short *frame_buffer, int x, int y, int width, int height, int frame_height, unsigned short frame_color, unsigned short fill_color)
{
    for (int i = y; i < y + height; i++)
    {
        for (int j = i * 480 + x; j < i * 480 + x + width; j++)
        {
            if (i < y + frame_height || i > y + height - frame_height - 1) 
            {
                frame_buffer[j] = frame_color;
                continue;
            }

            if (j < i * 480 + x + frame_height || j > i * 480 + x + width - frame_height - 1) 
            {
                frame_buffer[j] = frame_color;
                continue;
            }

            frame_buffer[j] = fill_color;
        }
    }
}

void draw_main_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, char *choice)
{
    int i;
    for (i = 0; i < 320 * 480; i++)
    {
        frame_buffer[i] = 0xCCCE;
    }

    /* 1 PLAYER rectangle */
    draw_rectangle(frame_buffer, 57, 22, 368, 54, 5, 0, 0x49A5);
    /* 2 PLAYERS rectangle */
    draw_rectangle(frame_buffer, 57, 98, 368, 54, 5, 0, 0x49A5);
    /* STTINGS rectangle */
    draw_rectangle(frame_buffer, 57, 173, 368, 54, 5, 0, 0x49A5);
    /* EXIT rectangle */
    draw_rectangle(frame_buffer, 57, 247, 368, 54, 5, 0, 0x49A5);


    /* CHOICE rectangle */
    draw_rectangle(frame_buffer, 57, 22 + *choice * 75, 368, 54, 5, 0, 0x9CF3);


    /* 1 PLAYER label */
    draw_char(frame_buffer, font_descriptor, 88, 25, '1', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 132, 25, 'P', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 176, 25, 'L', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 220, 25, 'A', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 264, 25, 'Y', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 308, 25, 'E', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 352, 25, 'R', 0xFFFF);

    /* 2 PLAYERS label */
    draw_char(frame_buffer, font_descriptor, 66, 101, '2', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 110, 101, 'P', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 154, 101, 'L', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 198, 101, 'A', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 242, 101, 'Y', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 101, 'E', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 330, 101, 'R', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 374, 101, 'S', 0xFFFF);

    /* SETTINGS label */
    draw_char(frame_buffer, font_descriptor, 84, 176, 'S', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 128, 176, 'E', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 172, 176, 'T', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 216, 176, 'T', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 260, 176, 'I', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 176, 'N', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 330, 176, 'G', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 374, 176, 'S', 0xFFFF);

    /* EXIT label */
    draw_char(frame_buffer, font_descriptor, 172, 250, 'E', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 216, 250, 'X', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 260, 250, 'I', 0xFFFF);
    draw_char(frame_buffer, font_descriptor, 286, 250, 'T', 0xFFFF);


    /* Sends info to screen */
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 480 * 320; i++)
    {
        parlcd_write_data(parlcd_mem_base, frame_buffer[i]);
    }
}
