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

void start_music(sfBool A)
{
    sfMusic *music = sfMusic_createFromFile("./Audio/Lobby.ogg");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, 50);
    if (A) {
        sfMusic_play(music);
    } else {
        sfMusic_stop(music);
    }
}

sfSound *sound_btn(void)
{
    sfSoundBuffer *soundBuffer = SBCF("./Audio/btn.ogg");
    sfSound *sound = sfSound_create();

    sfSound_setVolume(sound, 15);
    sfSound_setBuffer(sound, soundBuffer);
    sfSleep(sfMilliseconds(500));
    return sound;
}

int music_btn(sfRenderWindow *window, sfEvent event)
{
    bg_t pressed = init_scale(pressed, 0.2, 0.2);
    bg_t button = init_scale(button, 0.2, 0.2);
    sfBool but = sfTrue;
    hb_t hitbox;

    button = init_position(button, 0, 0, "./Images/MusicON.png");
    pressed = init_position(pressed, 0, 0, "./Images/MusicOFF.png");
    hitbox = init_hitbox(window, pressed);
    if (event.type == sfEvtMouseButtonPressed &&
    sfFloatRect_contains(&hitbox.img, hitbox.mse.x, hitbox.mse.y) == sfTrue) {
        but = !but;
    }
    if (but) {
        sfRenderWindow_drawSprite(window, button.Sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(window, pressed.Sprite, NULL);
    }
}
