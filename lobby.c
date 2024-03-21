/*
** EPITECH PROJECT, 2023
** My_Hunter
** File description:
** Jeu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int str_to_int(const char *str)
{
    int nb;
    int i = 0;

    while (str[i] >= 48 && str[i] <= 57) {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    return nb;
}

int replay_btn(sfRenderWindow *window, sfEvent event)
{
    bg_t pressed = init_scale(pressed, 0.5, 0.5);
    bg_t button = init_scale(button, 0.5, 0.5);
    hb_t bx;

    button = init_position(button, 765, 820, "./Images/Re_btn.png");
    pressed = init_position(pressed, 765, 820, "./Images/Re_pressed.png");
    bx = init_hitbox(window, pressed);
    sfRenderWindow_drawSprite(window, button.Sprite, NULL);
    if (event.type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bx.img, bx.mse.x, bx.mse.y) == sfTrue) {
        sfRenderWindow_drawSprite(window, pressed.Sprite, NULL);
    }
    if (event.type == sfEvtMouseButtonReleased &&
    sfFloatRect_contains(&bx.img, bx.mse.x, bx.mse.y) == sfTrue) {
        game_display(window, event);
        destroy_fct(button);
        destroy_fct(pressed);
    }
}

void draw_rest(sfRenderWindow *window, bg_t BACK, bg_t icon, bg_t GameOver)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, BACK.Sprite, NULL);
    sfRenderWindow_drawSprite(window, icon.Sprite, NULL);
    sfRenderWindow_drawSprite(window, GameOver.Sprite, NULL);
}

int my_restart(sfRenderWindow *window, sfEvent event, ca cut)
{
    bg_t BACK = init_scale(BACK, 1, 1);
    bg_t icon = init_scale(icon, 0.5, 0.5);
    bg_t GameOver = init_scale(GameOver, 1, 1);

    GameOver = init_position(GameOver, 530, 220, "./Images/GameOver.png");
    icon = init_position(icon, 0, 0, "./Images/icon.png");
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    BACK = init_position(BACK, 0, 0, "./Images/BG/BG2.png");
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_btn(window, event);
        }
        if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(window);
        }
        draw_rest(window, BACK, icon, GameOver);
        disp_txt(cut, window, event);
    }
    return 0;
}

int lore(char **av)
{
    if (av[1][1] == 'h' && av[1][2] == '\0') {
        my_putstr("        Welcome to 'Kill bats to may become batman at");
        my_putstr(" 2am in a deep forest!'\n\nHere, you have to kill ");
        my_putstr("bats and others, to may become batman at 2am in a deep ");
        my_putstr("forest.\nTo kill them, you need to click on it and ");
        my_putstr("BOOOOM!\nCare, the more you kill them, the more they are ");
        my_putstr("fast.\nYou got 3 lives, if you miss your shoot or the bat");
        my_putstr(" reaches the other side of you screen, you will ");
        my_putstr("lose a life.");
        return 0;
    } else {
        my_putstr("./my_hunter --> to play.\n./my_hunter -h --> to get ");
        my_putstr("more informations.\n");
        return 84;
    }
}
