#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <time.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "draw.h"

#define M_PI 10

int main(int argc, char *argv[])
{
  unsigned char *parlcd_mem_base;
  int i, j, k;
  int ptr;

  unsigned short *frame_buffer;
  font_descriptor_t *font_descriptor;

  /* ??? */
  struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = 120 * 1000 * 1000};

  /* Font */
  font_descriptor = &font_winFreeSystem14x16;

  /* Frame buffer */
  frame_buffer = (unsigned short *)malloc(320 * 480 * 2);

  /* Adresses mapping */
  parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  if (parlcd_mem_base == NULL)
  {
    exit(1);
  }

  int s = 0;
  while (s < 10)
  {
    /* Rainbow */
    parlcd_hx8357_init(parlcd_mem_base);
    parlcd_write_cmd(parlcd_mem_base, 0x2c);
    for (i = 0; i < 320; i++)
    {
      for (j = 0; j < 480; j++)
      {
        parlcd_write_data(parlcd_mem_base, hsv2rgb_lcd(j, 255, (i * 255) / 320));
      }
    }
    sleep(2);

    /* flying letters */
    float g = 10.0;
    for (k = 0; k <= 80; k += 5)
    {
      float alfa = ((10 + k) * M_PI) / 180.0;
      float vx = 32 * (M_PI / 2.0 - alfa);
      float vy = 32 * (2.0 * alfa / M_PI);
      float x = 1;
      float y = 1;
      char ch = ('a' + k / 5);
      unsigned int col = hsv2rgb_lcd(4 * k, 255, 255);
      while ((x < 480) && (y > 0))
      {
        for (ptr = 0; ptr < 320 * 480; ptr++)
        {
          frame_buffer[ptr] = 0;
        }
        draw_char(frame_buffer, font_descriptor, (int)x, 250 - (int)y, ch, col);
        x += vx;
        y += vy;
        vx = vx * 0.97;
        vy = vy * 0.97 - g;
        parlcd_write_cmd(parlcd_mem_base, 0x2c);
        for (ptr = 0; ptr < 480 * 320; ptr++)
        {
          parlcd_write_data(parlcd_mem_base, frame_buffer[ptr]);
        }
        clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
      }
    }
    s++;
  }
}