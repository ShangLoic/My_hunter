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

void racc(sfRenderWindow *window, ca cut)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, cut.BACK.Sprite, NULL);
    sfRenderWindow_drawText(window, cut.text.text, NULL);
    sfRenderWindow_drawSprite(window, cut.heart.Sprite, NULL);
    sfRenderWindow_drawSprite(window, cut.bat.Sprite, NULL);
    sfRenderWindow_drawSprite(window, cut.boss.Sprite, NULL);
    if (cut.score >= 50)
        sfRenderWindow_drawSprite(window, cut.slime.Sprite, NULL);
    if (cut.score >= 200) {
        sfRenderWindow_drawSprite(window, cut.boss_bar.Sprite, NULL);
    }
    sfRenderWindow_drawSprite(window, cut.cross.Sprite, NULL);
    sfRenderWindow_display(window);
}

void cutter(sfRenderWindow *window, ca cut)
{
    cut.text.str = int_to_str(cut.score);
    cut.boss_bar = init_scale(cut.boss_bar, cut.boss_health / 16, 0.3);
    sfSprite_setScale(cut.boss_bar.Sprite, cut.boss_bar.Scale);
    sfText_setString(cut.text.text, cut.text.str);
    sfSprite_setTextureRect(cut.bat.Sprite, cut.move.a);
    sfSprite_setTextureRect(cut.heart.Sprite, cut.vie);
    sfSprite_setTextureRect(cut.slime.Sprite, cut.slime_rect);
    sfSprite_setTextureRect(cut.boss.Sprite, cut.boss_rect);
    cut.cross = init_position(cut.cross, CBM.x - 36, CBM.y - 36, CROSS);
    racc(window, cut);
}

int hunter_disp(sfRenderWindow *window, sfEvent event, bg_t BACK, bg_t icon)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, BACK.Sprite, NULL);
    sfRenderWindow_drawSprite(window, icon.Sprite, NULL);
    play_btn(window, event);
    sfRenderWindow_display(window);
}

bg_t cut1(sfRenderWindow *window, bg_t BACK)
{
    BACK = init_position(BACK, 0, 0, "./Images/BG/BG4.png");
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return BACK;
}

ca boss_fct(ca cut)
{
    if (cut.score >= 200) {
        if (cut.boss_rect.left >= 740) {
            cut.boss_rect.left = 0;
        } else {
            cut.boss_rect.left += 128;
        }
        if (cut.boss.Position.x >= 2000) {
            cut.vie.left += 300;
            cut.life -= 2;
            destroy_fct(cut.boss);
        } else {
            cut.boss.Position.x += cut.boss_speed;
        }
        sfSprite_setPosition(cut.boss.Sprite, cut.boss.Position);
    }
    return cut;
}
