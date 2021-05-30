
#include "scenes.h"

game_map_t load_default_game()
{
    game_map_t game_map = {
        .cowboy_left = {
            .x = COWBOY_LEFT_X,
            .y = COWBOY_LEFT_Y,
            .width = COWBOY_AIMING_WIDTH,
            .height = COWBOY_AIMING_HEIGHT,
            .color = C_LIGHT_BLUE,
            .side = LEFT,
            .state = AIMING,
            .health = COWBOY_HEALTH,
            .direction = UP,
            .bullets = COWBOY_BULLET_AMOUNT},

        .cowboy_right = {.x = COWBOY_RIGHT_X, .y = COWBOY_RIGHT_Y, .width = COWBOY_AIMING_WIDTH, .height = COWBOY_AIMING_HEIGHT, .color = C_RED, .side = RIGHT, .state = AIMING, .health = COWBOY_HEALTH, .direction = DOWN, .bullets = COWBOY_BULLET_AMOUNT},

        .object_manager.barrels_length = BARREL_AMOUNT,

        .object_manager.stones_length = STONE_AMOUNT,

        .object_manager.cactuses_length = CACTUS_AMOUNT,

        .object_manager.bullets_length = BULLET_AMOUNT,
        .amount_of_active_objects = 0};

    generate_objects_on_greed(&game_map);
    return game_map;
}

void update_bullets(bullet_t *bullets, unsigned short length)
{
    for (int i = 0; i < length; i++)
    {
        if (bullets[i].is_active)
        {
            bullets[i].x += bullets[i].speed_x;
            bullets[i].y += bullets[i].speed_y;
        }
    }
}

void make_decision(game_map_t *game_map)
{
    int rand_num = rand();
    if (rand_num % 2 == 0)
    {
        fire_cowboy_right(game_map);
    }
}

/* Animation sliding cowboy UP and DOWN */
void update_cowboy(cowboy_t *cowboy)
{
    if (cowboy->direction == UP)
    {
        if (isCowboyOnMap(cowboy))
        {
            cowboy->y -= COWBOY_RELOCATION;
        }
        else
        {
            cowboy->direction = DOWN;
        }
    }
    else if (cowboy->direction == DOWN)
    {
        if (isCowboyOnMap(cowboy))
        {
            cowboy->y += COWBOY_RELOCATION;
        }
        else
        {
            cowboy->direction = UP;
        }
    }
}

void update_states(game_map_t *game_map)
{
    update_cowboy(&(game_map->cowboy_left));
    update_cowboy(&(game_map->cowboy_right));
    update_bullets(game_map->object_manager.bullets, game_map->object_manager.bullets_length);
    check_collisions(game_map);
}

void load_settings(game_map_t *game_map, settings_t *settings)
{
    game_map->cowboy_left.color = settings->player_left_color;
    game_map->cowboy_right.color = settings->player_right_color;
    game_map->bullet_color = settings->bullet_color;
    game_map->bullet_speed = settings->bullet_speed;
}

unsigned long long int power(unsigned char base, unsigned char exponent)
{
    unsigned long long int number = 1;
    for (unsigned char i = 0; i < exponent; i++)
    {
        number *= base;
    }
    return number;
}

void start_game_loop(unsigned char *parlcd_mem_base, unsigned char *led_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings, bool bot)
{
    int counter = 0;
    bool reload_pistols = false;
    unsigned char round_amount = 33;
    unsigned char ch, choice = RESUME;
    struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = 10000};
    font_descriptor = &font_rom8x16;

    /* Sets up the map and settings */
    game_map_t game_map = load_default_game();
    load_settings(&game_map, settings);

    draw_game(parlcd_mem_base, frame_buffer, font_descriptor, &game_map);
    while (true)
    {
        /* Light on LED-32 */
        *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_LINE_o) = UINT32_MAX - (power(2, round_amount - 1) - 1);

        /* Light on RGB-LED left*/
        if (game_map.cowboy_left.health > COWBOY_HEALTH / 3)
        {
            *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB1_o) = 0x00FF00;
        }
        else if (0 < game_map.cowboy_left.health && game_map.cowboy_left.health <= COWBOY_HEALTH / 3)
        {
            *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB1_o) = 0xFF7700;
        }
        else if (game_map.cowboy_left.health == 0)
        {
            *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB1_o) = 0xFF0000;
        }

        /* Light off RGB-LED right*/
        if (game_map.cowboy_right.health > COWBOY_HEALTH / 3)
        {
            *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB2_o) = 0x00FF00;
        }
        else if (0 < game_map.cowboy_right.health && game_map.cowboy_right.health <= COWBOY_HEALTH / 3)
        {
            *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB2_o) = 0xFF7700;
        }
        else if (game_map.cowboy_right.health == 0)
        {
            *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB2_o) = 0xFF0000;
        }

        /* Checks whether it is the end of current game*/
        if (game_map.cowboy_left.state == DEAD || game_map.cowboy_right.state == DEAD)
        {
            sleep(1);
            game_map.cowboy_left.animation = 0;
            game_map.cowboy_right.animation = 0;
            draw_game(parlcd_mem_base, frame_buffer, font_descriptor, &game_map);
            sleep(1);
            printf("\n--------------------\n");
            printf("\n|     GAME OVER     |\n");
            printf("\n--------------------\n");
            start_ending_menu(parlcd_mem_base, frame_buffer, font_descriptor, &game_map);
            break;
        }

        /* New round logic (reloads pistols and spawns new objects on the map)*/
        if (game_map.cowboy_left.bullets == 0 && game_map.cowboy_right.bullets == 0)
        {
            reload_pistols = true;
            for (int i = 0; i < game_map.object_manager.bullets_length; i++)
            {
                if (game_map.object_manager.bullets[i].is_active)
                {
                    reload_pistols = false;
                }
            }

            if (reload_pistols)
            {
                game_map.cowboy_left.bullets = COWBOY_BULLET_AMOUNT;
                game_map.cowboy_left.state = AIMING;
                game_map.cowboy_left.width = COWBOY_AIMING_WIDTH;
                game_map.cowboy_left.height = COWBOY_AIMING_HEIGHT;

                game_map.cowboy_right.bullets = COWBOY_BULLET_AMOUNT;
                game_map.cowboy_right.x = COWBOY_RIGHT_X;
                game_map.cowboy_right.state = AIMING;
                game_map.cowboy_right.width = COWBOY_AIMING_WIDTH;
                game_map.cowboy_right.height = COWBOY_AIMING_HEIGHT;

                generate_objects_on_greed(&game_map);
                reload_pistols = false;
                round_amount--;
                if (round_amount == 0)
                {
                    round_amount = 33;
                }
            }
        }

        /* Updates bullet and cowboy coordinates, cowboy direction and checks collisions */
        update_states(&game_map);

        ch = getch(stdin);
        if (ch == ESCAPE)
        {
            printf("\n--------------------\n");
            printf("\n|       PAUSE      |\n");
            printf("\n--------------------\n");
            start_pause_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);
            if (choice == MAIN_MENU)
            {
                printf("\n--------------------\n");
                printf("\n|     MAIN MENU    |\n");
                printf("\n--------------------\n");
                break;
            }
            printf("\n--------------------\n");
            printf("\n|      RESUME      |\n");
            printf("\n--------------------\n");
        }
        else if (ch == 'w')
        {
            game_map.cowboy_left.direction = UP;
        }
        else if (ch == 's')
        {
            game_map.cowboy_left.direction = DOWN;
        }
        else if (ch == 'd')
        {
            fire_cowboy_left(&game_map);
        }

        if (!bot)
        {
            if (ch == 'o')
            {
                game_map.cowboy_right.direction = UP;
            }
            else if (ch == 'l')
            {
                game_map.cowboy_right.direction = DOWN;
            }
            else if (ch == 'k')
            {
                fire_cowboy_right(&game_map);
            }
        }

        if (counter == 60)
        {
            make_decision(&game_map);
            counter = 0;
        }

        draw_game(parlcd_mem_base, frame_buffer, font_descriptor, &game_map);
        clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
        counter++;
    }

    /* Light off LED-32 and RGB-LEDs*/
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_LINE_o) = 0;
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB1_o) = 0;
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB2_o) = 0;
}
