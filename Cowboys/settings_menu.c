
#include "scenes.h"

void switch_choice_helper(unsigned short color_to_test, unsigned char *choice_variable);
void switch_color_helper(unsigned char choice_to_test, unsigned short *color_variable_settings, unsigned short *color_variable);

void start_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings)
{
    unsigned char choice_button = PLAYER_LEFT_COLOUR;
    font_descriptor = &font_winFreeSystem14x16;

    /* Local structs variables for drawing setting */
    cowboy_t cowboy_left = {
        .x = 57,
        .y = 24,
        .width = COWBOY_AIMING_WIDTH,
        .height = COWBOY_AIMING_HEIGHT,
        .color = settings->player_left_color,
        .side = LEFT,
        .state = AIMING};

    cowboy_t cowboy_right = {
        .x = 57,
        .y = 100,
        .width = COWBOY_AIMING_WIDTH,
        .height = COWBOY_AIMING_HEIGHT,
        .color = settings->player_right_color,
        .side = RIGHT,
        .state = AIMING};

    bullet_t bullet = {
        .x = 62,
        .y = 176,
        .width = BULLET_WIDTH,
        .height = BULLET_HEIGHT,
        .color = settings->bullet_color,
        .speed_x = 0};

    /* Loading actual left player color settings */
    unsigned char choice_left_player_color = FIRST_CHOICE;
    switch_choice_helper(settings->player_left_color, &choice_left_player_color);

    /* Loading actual right player color settings */
    unsigned char choice_right_player_color = FIRST_CHOICE;
    switch_choice_helper(settings->player_right_color, &choice_right_player_color);

    /* Loading actual bullet color settings */
    unsigned char choice_bullet_color = FIRST_CHOICE;
    switch_choice_helper(settings->bullet_color, &choice_bullet_color);

    /* Loading actual bullet speed settings */
    int choice_bullet_speed = FIRST_CHOICE;
    switch (settings->bullet_speed)
    {
    case 10:
        choice_bullet_speed = FIRST_CHOICE;
        break;
    case 15:
        choice_bullet_speed = SECOND_CHOICE;
        break;
    case 20:
        choice_bullet_speed = THIRD_CHOICE;
        break;
    case 25:
        choice_bullet_speed = FOURTH_CHOICE;
        break;
    case 30:
        choice_bullet_speed = FIFTH_CHOICE;
        break;
    }

    /* Drawing settings first time */
    draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &cowboy_left, &cowboy_right, &bullet,
                       choice_button, choice_left_player_color, choice_right_player_color, choice_bullet_color, choice_bullet_speed);

    unsigned char ch;
    while (true)
    {
        ch = getch(stdin);

        if (ch == '\033')
        {
            getch(); // skip the [
            switch (getch())
            { // the real value
            case 'A':
                choice_button = (choice_button - 1 + 4) % 4;
                // code for arrow up
                break;
            case 'B':
                choice_button = (choice_button + 1) % 4;
                // code for arrow down
                break;
            case 'D':
                switch (choice_button)
                {
                case PLAYER_LEFT_COLOUR:
                    choice_left_player_color = (choice_left_player_color - 1 + 6) % 6;
                    break;
                case PLAYER_RIGHT_COLOUR:
                    choice_right_player_color = (choice_right_player_color - 1 + 6) % 6;
                    break;
                case BULLET_COLOR:
                    choice_bullet_color = (choice_bullet_color - 1 + 6) % 6;
                    break;
                case BULLET_SPEED:
                    choice_bullet_speed = (choice_bullet_speed - 1 + 5) % 5;
                    break;
                }
                // code for arrow left
                break;
            case 'C':
                switch (choice_button)
                {
                case PLAYER_LEFT_COLOUR:
                    choice_left_player_color = (choice_left_player_color + 1) % 6;
                    break;
                case PLAYER_RIGHT_COLOUR:
                    choice_right_player_color = (choice_right_player_color + 1) % 6;
                    break;
                case BULLET_COLOR:
                    choice_bullet_color = (choice_bullet_color + 1) % 6;
                    break;
                case BULLET_SPEED:
                    choice_bullet_speed = (choice_bullet_speed + 1) % 5;
                    break;
                }
                // code for arrow right
                break;
            }

            /* Applying left player color settings */
            switch_color_helper(choice_left_player_color, &(settings->player_left_color), &(cowboy_left.color));
            
            /* Applying right player color settings */
            switch_color_helper(choice_right_player_color, &(settings->player_right_color), &(cowboy_right.color));

            /* Applying bullet color settings */
            switch_color_helper(choice_bullet_color, &(settings->bullet_color), &(bullet.color));
        
            /* Applying bullet speed settings */
            switch (choice_bullet_speed)
            {
            case FIRST_CHOICE:
                settings->bullet_speed = 10;
                break;
            case SECOND_CHOICE:
                settings->bullet_speed = 15;
                break;
            case THIRD_CHOICE:
                settings->bullet_speed = 20;
                break;
            case FOURTH_CHOICE:
                settings->bullet_speed = 25;
                break;
            case FIFTH_CHOICE:
                settings->bullet_speed = 30;
                break;
            }
        }
        else if (ch == '\n')
        {   
            printf("\n--------------------\n");
            printf("\n|     MAIN MENU    |\n");
            printf("\n--------------------\n");
            break;
        }

        /* Drawing settings */
        draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &cowboy_left, &cowboy_right, &bullet,
                           choice_button, choice_left_player_color, choice_right_player_color, choice_bullet_color, choice_bullet_speed);
    }
}

void switch_choice_helper(unsigned short color_to_test, unsigned char *choice_variable)
{
    switch (color_to_test)
    {
    case C_RED:
        *choice_variable = FIRST_CHOICE;
        break;
    case C_LIGHT_BLUE:
        *choice_variable = SECOND_CHOICE;
        break;
    case C_LIGHT_GREEN:
        *choice_variable = THIRD_CHOICE;
        break;
    case C_LIGHT_YELLOW:
        *choice_variable = FOURTH_CHOICE;
        break;
    case C_PINK:
        *choice_variable = FIFTH_CHOICE;
        break;
    case C_LIGHT_GRAY:
        *choice_variable = SIXTH_CHOICE;
        break;
    }
}

void switch_color_helper(unsigned char choice_to_test, unsigned short *color_variable_settings, unsigned short *color_variable)
{
    switch (choice_to_test)
    {
    case FIRST_CHOICE:
        *color_variable_settings = C_RED;
        *color_variable = C_RED;
        break;
    case SECOND_CHOICE:
        *color_variable_settings = C_LIGHT_BLUE;
        *color_variable = C_LIGHT_BLUE;
        break;
    case THIRD_CHOICE:
        *color_variable_settings = C_LIGHT_GREEN;
        *color_variable = C_LIGHT_GREEN;
        break;
    case FOURTH_CHOICE:
        *color_variable_settings = C_LIGHT_YELLOW;
        *color_variable = C_LIGHT_YELLOW;
        break;
    case FIFTH_CHOICE:
        *color_variable_settings = C_PINK;
        *color_variable = C_PINK;
        break;
    case SIXTH_CHOICE:
        *color_variable_settings = C_LIGHT_GRAY;
        *color_variable = C_LIGHT_GRAY;
        break;
    }
}
