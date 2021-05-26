
#include "game.h"
#include "serialize_lock.h"

#define M_PI 10

int main(int argc, char *argv[])
{
  if (serialize_lock(1) <= 0)
  {
    printf("System is occupied\n");

    if (1)
    {
      printf("Waitting\n");
      /* Wait till application holding lock releases it or exits */
      serialize_lock(0);
    }
  }

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
  serialize_unlock();

  return 0;
}