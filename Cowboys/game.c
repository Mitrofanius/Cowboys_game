
#include "game.h"

void start_game(unsigned char *parlcd_mem_base, unsigned char *led_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor)
{
    unsigned char choice;
    /* Light off LED-32 and RGB-LEDs*/
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_LINE_o) = 0;
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB1_o) = 0;
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB2_o) = 0;

    /* Loading animation */
    draw_loading_scene(parlcd_mem_base, frame_buffer, font_descriptor);

    /* Default settings */
    settings_t settings = {
        .player_left_color = C_LIGHT_YELLOW,
        .player_right_color = C_LIGHT_GREEN,
        .bullet_color = C_PINK,
        .bullet_speed = 10};

    while (true)
    {
        choice = ONE_PLAYER_GAME;
        start_main_menu(parlcd_mem_base, frame_buffer, font_descriptor, &choice);

        switch (choice)
        {
        case ONE_PLAYER_GAME:
            /* 1 player game */
            printf("\n--------------------\n");
            printf("\n|  ONE_PLAYER_GAME |\n");
            printf("\n--------------------\n");
            start_one_player_game(parlcd_mem_base, led_mem_base, frame_buffer, font_descriptor, &settings);
            break;
        case TWO_PLAYERS_GAME:
            /* 2 players game */
            printf("\n--------------------\n");
            printf("\n| TWO_PLAYERS_GAME |\n");
            printf("\n--------------------\n");
            start_two_players_game(parlcd_mem_base, led_mem_base, frame_buffer, font_descriptor, &settings);
            break;
        case SETTINGS:
            /* settings */
            printf("\n--------------------\n");
            printf("\n|     SETTINGS     |\n");
            printf("\n--------------------\n");
            start_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &settings);
            break;
        default:
            /* exit */
            printf("\n--------------------\n");
            printf("\n|       EXIT       |\n");
            printf("\n--------------------\n");
            break;
        }

        if (choice == EXIT)
        {
            break;
        }
    }
    
    /* Closing animation */
    draw_closing_scene(parlcd_mem_base, frame_buffer, font_descriptor);

    /* Light off LED-32 and RGB-LEDs*/
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_LINE_o) = 0;
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB1_o) = 0;
    *(volatile uint32_t *)(led_mem_base + SPILED_REG_LED_RGB2_o) = 0;
}
