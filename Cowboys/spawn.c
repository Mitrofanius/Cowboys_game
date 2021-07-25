#include "spawn.h"
#include <stdio.h>

void generate_objects_on_greed(game_map_t *game_map)
{
    time_t t;
    unsigned char max_num_of_objects, object_type;
    int number_of_block;

    fill_greed(game_map);

    srand((unsigned)time(&t));

    max_num_of_objects = rand() % 3 + 5;

    while (game_map->amount_of_active_objects < max_num_of_objects)
    {
        number_of_block = rand() % (GREED_HEIGHT * GREED_WIDTH);

        if (game_map->array_of_free_places[number_of_block] == 0)
        {
            object_type = (rand() % 3 + 1);

            if (object_type == TYPE_CACTUS)
            {
                for (int i = 0; i < CACTUS_AMOUNT; i++)
                {
                    if (!game_map->object_manager.cactuses[i].is_active)
                    {
                        game_map->object_manager.cactuses[i].x = game_map->objects_coordinates[number_of_block * 2];
                        game_map->object_manager.cactuses[i].y = game_map->objects_coordinates[number_of_block * 2 + 1];
                        game_map->object_manager.cactuses[i].width = CACTUS_WIDTH;
                        game_map->object_manager.cactuses[i].height = CACTUS_HEIGHT;
                        game_map->object_manager.cactuses[i].is_active = true;
                        game_map->object_manager.cactuses[i].index = number_of_block;
                        game_map->amount_of_active_objects++;
                        game_map->array_of_free_places[number_of_block] = TYPE_CACTUS;
                        break;
                    }
                }
            }
            else if (object_type == TYPE_BARREL)
            {
                game_map->array_of_free_places[number_of_block] = TYPE_BARREL;
                for (int i = 0; i < BARREL_AMOUNT; i++)
                {
                    if (!game_map->object_manager.barrels[i].is_active)
                    {
                        game_map->object_manager.barrels[i].x = game_map->objects_coordinates[number_of_block * 2];
                        game_map->object_manager.barrels[i].y = game_map->objects_coordinates[number_of_block * 2 + 1];
                        game_map->object_manager.barrels[i].width = BARREL_WIDTH;
                        game_map->object_manager.barrels[i].height = BARREL_HEIGHT;
                        game_map->object_manager.barrels[i].is_active = true;
                        game_map->object_manager.barrels[i].index = number_of_block;
                        game_map->amount_of_active_objects++;
                        game_map->array_of_free_places[number_of_block] = TYPE_BARREL;

                        break;
                    }
                }
            }
            else if (object_type == TYPE_STONE)
            {
                for (int i = 0; i < STONE_AMOUNT; i++)
                {
                    if (!game_map->object_manager.stones[i].is_active)
                    {
                        game_map->object_manager.stones[i].x = game_map->objects_coordinates[number_of_block * 2];
                        game_map->object_manager.stones[i].y = game_map->objects_coordinates[number_of_block * 2 + 1];
                        game_map->object_manager.stones[i].width = STONE_WIDTH;
                        game_map->object_manager.stones[i].height = STONE_HEIGHT;
                        game_map->object_manager.stones[i].is_active = true;
                        game_map->object_manager.stones[i].index = number_of_block;
                        game_map->amount_of_active_objects++;
                        game_map->array_of_free_places[number_of_block] = TYPE_STONE;

                        break;
                    }
                }
            }
        }
    }
}

void fill_greed(game_map_t *game_map)
{
    for (int i = 0; i < GREED_HEIGHT * GREED_WIDTH; i++)
    {
        game_map->array_of_free_places[i] = 0;
    }

    for (int y = 0; y < GREED_HEIGHT; y++)
    {

        for (int x = 0; x < GREED_WIDTH * 2; x += 2)
        {
            game_map->objects_coordinates[x + y * GREED_WIDTH * 2] = START_X + x / 2 * 13 * SCALE;
            game_map->objects_coordinates[(x + y * GREED_WIDTH * 2) + 1] = START_Y + y * 13 * SCALE;
        }
    }
}