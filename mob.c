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

ca bassirou(ca cut, sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (cut.life <= 0) {
            game_display(window, event);
            destroy_fct(cut.background);
            destroy_fct(cut.bat);
            destroy_fct(cut.slime);
        } else {
            cut.vie.left += 300;
            cut.life--;
        }
    }
    return cut;
}

ca respawn_bat(ca cut)
{
    cut.move.x = 2000;
    cut.move.y = rand() % 700 + 100;
    if (cut.x <= 50) {
        cut.x += 3;
    }
    cut.score += 10;
    return cut;
}

ca boss_click(ca cut )
{
    cut.boss_health--;
    if (cut.boss_health <= 20) {
        cut.boss_speed = 50;
        cut.boss.Texture = TCFF("./Images/Run.png", NULL);
        SSST(cut.boss.Sprite, cut.boss.Texture, sfFalse);
    }
    if (cut.boss_health <= 0) {
        cut.boss_speed = 0;
        cut.boss.Position.x = -300;
        cut.score += 100;
        if (cut.life <= 2) {
            cut.life++;
            cut.vie.left -= 300;
        }
        sfSprite_setPosition(cut.boss.Sprite, cut.boss.Position);
    }
    return cut;
}

ca click_on_mob(ca cut, sfRenderWindow *window, sfEvent event)
{
    if (CONT(&cut.bx.img, CBM.x, CBM.y) == sfTrue) {
        return respawn_bat(cut);
    } else if (CONT(&cut.bx_slime.img, SLBX.x, SLBX.y) == sfTrue) {
        cut.slime.Position.x = 2000;
        cut.score += 5;
        return cut;
    }
    return bassirou(cut, window, event);
}

ca on_click(sfRenderWindow *window, sfEvent event, ca cut)
{
    cut.bx_slime = init_hitb(window, cut.slime, event);
    cut.bx_boss = init_hitb(window, cut.boss, event);
    if (event.type == sfEvtMouseButtonPressed) {
        if (CONT(&cut.bx_boss.img, CBBM.x, CBBM.y) == sfTrue) {
            cut = boss_click(cut);
        } else
            cut = click_on_mob(cut, window, event);
    }
    return cut;
}
