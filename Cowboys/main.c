
#include "game.h"

#define M_PI 10

int main(int argc, char *argv[])
{
  unsigned char *parlcd_mem_base;
  unsigned short *frame_buffer;
  font_descriptor_t *font_descriptor;

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

  /* Starts game */
  start_game(parlcd_mem_base, frame_buffer, font_descriptor);

  return 0;
}