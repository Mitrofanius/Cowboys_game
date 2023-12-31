
#include "draw.h"
 
void draw_char(unsigned short *frame_buffer, font_descriptor_t *font_descriptor, int x, int y, char ch, unsigned char scale, unsigned short color)
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
                    draw_pixel_scale(frame_buffer, x + scale * j, y + scale * i, scale, color);
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

void draw_pixel_scale(unsigned short *frame_buffer, int x, int y, unsigned char scale, unsigned short color)
{
    int i, j;
    for (i = 0; i < scale; i++)
    {
        for (j = 0; j < scale; j++)
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

/* Converts integer to string */
void itoa(char string[], int number)
{
   int i, remainder, length = 0, n;
 
   n = number;
   while (n != 0)
   {
      length++;
      n /= 10;
   }
   
   for (i = 0; i < length; i++)
   {
      remainder = number % 10;
      number = number / 10;
      string[length - (i + 1)] = remainder + '0';
   }

   if (length == 0 && number == 0)
   {
      string[length] = '0';
      length++;
   }
   
   string[length] = '\0';
}
