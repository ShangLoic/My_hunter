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

double high(double y)
{
    if (y <= 50) {
        y += rand() % 30;
    } else if (y >= 1000) {
        y -= rand() % 30;
    } else {
        y += rand() % 40 - 20;
    }
    return y;
}

ca longu(ca cut, int x)
{
    if (cut.move.x <= -130) {
        cut.move.x = 1920;
        cut.vie.left += 300;
        cut.life--;
    } else {
        cut.move.x -= x;
    }
    return cut;
}

ca anim(ca cut, bg_t bat, int x)
{
    sfIntRect a;

    if (cut.move.c >= 2) {
        cut.move.c = 0;
    } else {
        cut.move.c++;
    }
    cut = longu(cut, x);
    cut.move.y = high(cut.move.y);
    bat.Position.x = cut.move.x;
    bat.Position.y = cut.move.y;
    sfSprite_setPosition(bat.Sprite, bat.Position);
    sfClock_restart(cut.move.clock);
    return cut;
}
