
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
        .state = AIMING
    };

    cowboy_t cowboy_right = {
        .x = 57,
        .y = 100,
        .width = 20,
        .height = 17,
        .colour = settings->player_right_color,
        .side = LEFT,
        .state = AIMING
    };
    
    unsigned char choice_left_player_color;
    switch(settings->player_left_color)
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

    draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &cowboy_left, &cowboy_right, choice_button, choice_left_player_color);

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
            case 'C':
                switch (choice_button)
                {
                    case PLAYER_LEFT_COLOUR:
                    choice_left_player_color = (choice_left_player_color - 1 + 6) % 6;
                    break;
                }
                // code for arrow left
                break;
            case 'D':
                switch (choice_button)
                {
                    case PLAYER_LEFT_COLOUR:
                    choice_left_player_color = (choice_left_player_color + 1) % 6;
                    break;
                }
                // code for arrow right
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

        draw_settings_menu(parlcd_mem_base, frame_buffer, font_descriptor, &cowboy_left, &cowboy_right, choice_button, choice_left_player_color);
    }

    ///TODO: change the colour of the cowboys to the chosen one, and speed of the 
}
