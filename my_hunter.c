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
#include <stdlib.h>

int play_btn(sfRenderWindow *window, sfEvent event)
{
    bg_t pressed = init_scale(pressed, 0.5, 0.5);
    bg_t button = init_scale(button, 0.5, 0.5);
    hb_t bx;

    button = init_position(button, 765, 650, "./Images/Play_btn.png");
    pressed = init_position(pressed, 765, 650, "./Images/Play_pressed.png");
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

ca slime_fct(ca cut)
{
    if (cut.score >= 45) {
        if (cut.slime_rect.left >= 225) {
            cut.slime_rect.left = 0;
        } else {
            cut.slime_rect.left += 75;
        }
        if (cut.slime.Position.x <= -50) {
            cut.slime.Position.x = 5000;
            cut.vie.left += 300;
            cut.life--;
        } else {
            cut.slime.Position.x -= 30;
        }
        sfSprite_setPosition(cut.slime.Sprite, cut.slime.Position);
    }
    return cut;
}

void game_display(sfRenderWindow *window, sfEvent event)
{
    ca cut = chacal(cut, window);

    while (sfRenderWindow_isOpen(window)) {
        cut.bx = init_hitb(window, cut.bat, event);
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_btn(window, event);
            cut = on_click(window, event, cut);
        }
        if (sfTime_asSeconds(sfClock_getElapsedTime(cut.move.clock)) >= 0.09) {
            cut = anim(cut, cut.bat, cut.x);
            cut = slime_fct(cut);
            cut = boss_fct(cut);
            cut.move.a = init_rect(cut.move, 130);
        }
        if (cut.life <= 0 || sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape))
            my_restart(window, event, cut);
        cutter(window, cut);
    }
}

int my_hunter(void)
{
    sfRenderWindow *window = window_creating(1920, 1080, 32);
    sfEvent event;
    bg_t BACK = init_scale(BACK, 1, 1);
    bg_t icon = init_scale(icon, 0.8, 0.8);

    icon = setup(window, icon);
    BACK = init_position(BACK, 0, 0, "./Images/BG/BG1.png");
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_btn(window, event);
        }
        hunter_disp(window, event, BACK, icon);
        if (sfTrue == sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfRenderWindow_close(window);
        }
    }
    destroy_fct(BACK);
    sfRenderWindow_destroy(window);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-') {
        return lore(av);
    } else if (ac == 1) {
        return my_hunter();
    } else {
        my_putstr("./my_hunter --> to play.\n./my_hunter -h --> to get ");
        my_putstr("more informations.\n");
        return 84;
    }
}
