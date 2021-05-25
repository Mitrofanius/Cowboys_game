
#include "settings_menu.h"

void start_settings_menu(unsigned char *parlcd_mem_base, unsigned short *frame_buffer, font_descriptor_t *font_descriptor, settings_t *settings)
{
    unsigned char choice_button = PLAYER_LEFT_COLOUR;
    //unsigned char player_left_color = settings->player_left_color;
    //unsigned char player_right_color = settings->player_right_color;
    //int bullet_speed = settings->bullet_speed;
    cowboy_t cowboy_left = {
        .x = 57,
        .y = 24,
        .width = 20,
        .height = 17,
        .colour = settings->player_left_color,
        .side = LEFT,
        .state = AIMING};

    cowboy_t cowboy_right = {
        .x = 57,
        .y = 100,
        .width = 20,
        .height = 17,
        .colour = settings->player_right_color,
        .side = RIGHT,
        .state = AIMING};

    unsigned char choice_left_player_color = FIRST_CHOICE;
    switch (settings->player_left_color)
    {
    case C_RED:
        choice_left_player_color = FIRST_CHOICE;
        break;
    case C_LIGHT_BLUE:
        choice_left_player_color = SECOND_CHOICE;
        break;
    case C_LIGHT_GREEN:
        choice_left_player_color = THIRD_CHOICE;
        break;
    case C_DARK_ORANGE:
        choice_left_player_color = FOURTH_CHOICE;
        break;
    case C_PINK:
        choice_left_player_color = FIFTH_CHOICE;
        break;
    case C_PURPLE:
        choice_left_player_color = SIXTH_CHOICE;
        break;
    }
    unsigned char choice_right_player_color = FIRST_CHOICE;
    switch (settings->player_right_color)
    {
    case C_RED:
        choice_right_player_color = FIRST_CHOICE;
        break;
    case C_LIGHT_BLUE:
        choice_right_player_color = SECOND_CHOICE;
        break;
    case C_LIGHT_GREEN:
        choice_right_player_color = THIRD_CHOICE;
        break;
    case C_DARK_ORANGE:
        choice_right_player_color = FOURTH_CHOICE;
        break;
    case C_PINK:
        choice_right_player_color = FIFTH_CHOICE;
        break;
    case C_PURPLE:
        choice_right_player_color = SIXTH_CHOICE;
        break;
    }

    int choice_bullet_speed = FIRST_CHOICE;
    switch (settings->bullet_speed)
    {
    case 10:
        choice_bullet_speed = FIRST_CHOICE;
        break;
    case 20:
        choice_bullet_speed = SECOND_CHOICE;
        break;
    case 30:
        choice_bullet_speed = THIRD_CHOICE;
        break;
    case 40:
        choice_bullet_speed = FOURTH_CHOICE;
        break;
    case 50:
        choice_bullet_speed = FIFTH_CHOICE;
        break;
    }

    draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &cowboy_left, &cowboy_right,
                       choice_button, choice_left_player_color, choice_right_player_color, choice_bullet_speed);

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
                case BULLET_SPEED:
                    choice_bullet_speed = (choice_bullet_speed - 1 + 5) % 5;
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
                case BULLET_SPEED:
                    choice_bullet_speed = (choice_bullet_speed + 1) % 5;
                }
                // code for arrow right
                break;
            }

            switch (choice_left_player_color)
            {
            case FIRST_CHOICE:
                settings->player_left_color = C_RED;
                cowboy_left.colour = C_RED;
                break;
            case SECOND_CHOICE:
                settings->player_left_color = C_LIGHT_BLUE;
                cowboy_left.colour = C_LIGHT_BLUE;
                break;
            case THIRD_CHOICE:
                settings->player_left_color = C_LIGHT_GREEN;
                cowboy_left.colour = C_LIGHT_GREEN;
                break;
            case FOURTH_CHOICE:
                settings->player_left_color = C_DARK_ORANGE;
                cowboy_left.colour = C_DARK_ORANGE;
                break;
            case FIFTH_CHOICE:
                settings->player_left_color = C_PINK;
                cowboy_left.colour = C_PINK;
                break;
            case SIXTH_CHOICE:
                settings->player_left_color = C_PURPLE;
                cowboy_left.colour = C_PURPLE;
                break;
            }
            switch (choice_right_player_color)
            {
            case FIRST_CHOICE:
                settings->player_right_color = C_RED;
                cowboy_right.colour = C_RED;
                break;
            case SECOND_CHOICE:
                settings->player_right_color = C_LIGHT_BLUE;
                cowboy_right.colour = C_LIGHT_BLUE;
                break;
            case THIRD_CHOICE:
                settings->player_right_color = C_LIGHT_GREEN;
                cowboy_right.colour = C_LIGHT_GREEN;
                break;
            case FOURTH_CHOICE:
                settings->player_right_color = C_DARK_ORANGE;
                cowboy_right.colour = C_DARK_ORANGE;
                break;
            case FIFTH_CHOICE:
                settings->player_right_color = C_PINK;
                cowboy_right.colour = C_PINK;
                break;
            case SIXTH_CHOICE:
                settings->player_right_color = C_PURPLE;
                cowboy_right.colour = C_PURPLE;
                break;
            }

            switch (choice_bullet_speed)
            {
            case FIRST_CHOICE:
                settings->bullet_speed = 10;
                break;
            case SECOND_CHOICE:
                settings->bullet_speed = 20;
                break;
            case THIRD_CHOICE:
                settings->bullet_speed = 30;
                break;
            case FOURTH_CHOICE:
                settings->bullet_speed = 40;
                break;
            case FIFTH_CHOICE:
                settings->bullet_speed = 50;
                break;
            }
        }
        else if (ch == '\n')
        {
            if (choice_button == BACK)
            {
                break;
            }
        }

        draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &cowboy_left, &cowboy_right, choice_button, choice_left_player_color, choice_right_player_color, choice_bullet_speed);
    }

    ///TODO: change the colour of the cowboys to the chosen one, and speed of the
}
