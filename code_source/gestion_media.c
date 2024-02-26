/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

void playmusic(char *chemin, int x)
{
    sfMusic *music = sfMusic_createFromFile(chemin);

    if (x == 1)
        sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    sfMusic_setVolume(music, 20);
}

static void suite(parametre_t *p)
{
    sfVector2u windowSize = sfRenderWindow_getSize(p->window);
    sfVector2f tour = {
        (float)windowSize.x / (512 * 10),
        (float)windowSize.y / (512 * 10)
    };
    imageinfo *pointer = p->tour;

    for (int i = 0; pointer != NULL; i++){
        sfSprite_setScale(pointer->sprite, tour);
        pointer = pointer->next;
    }
    return;
}

void ajuste_fond(parametre_t *p)
{
    sfVector2u windowSize = sfRenderWindow_getSize(p->window);
    imageinfo *pointer = p->avion;
    sfVector2f avion = {
        (float)windowSize.x / (285 * (10 * 8)),
        (float)windowSize.y / (268 * (12 * 4))
    };

    sfSprite_setScale(p->world, (sfVector2f){
        (float)windowSize.x / 3956,
        (float)windowSize.y / 1615
    });
    for (int i = 0; pointer != NULL; i++){
        sfSprite_setScale(pointer->sprite, avion);
        pointer = pointer->next;
    }
    return suite(p);
}

static void boucle_avion(parametre_t *p, imageinfo *pointer, int chrono)
{
    for (int i = 0; pointer != NULL && p->black == 0; i++){
        if (pointer->time < chrono && pointer->crash == 0 && p->touche_rc == 1)
            sfRenderWindow_drawRectangleShape(p->window, pointer->rect, NULL);
        if (pointer->time < chrono && pointer->crash == 0 &&
        p->touche_sprite == 1)
            sfRenderWindow_drawSprite(p->window, pointer->sprite, NULL);
        pointer = pointer->next;
    }
}

static void boucle_tour(parametre_t *p, imageinfo *pointer, int chrono)
{
    for (int i = 0; pointer != NULL && p->black == 0; i++){
        if (pointer->time < chrono && p->touche_rc == 1)
            sfRenderWindow_drawCircleShape(p->window, pointer->zone, NULL);
        if (pointer->time < chrono && p->touche_sprite == 1)
            sfRenderWindow_drawSprite(p->window, pointer->sprite, NULL);
        pointer = pointer->next;
    }
}

void disp_sprite(parametre_t *p)
{
    int chrono = sfTime_asMilliseconds(sfClock_getElapsedTime
    (p->chrono)) / 1000;

    sfRenderWindow_clear(p->window, sfWhite);
    sfRenderWindow_drawSprite(p->window, p->world, NULL);
    sfText_setString(p->text, my_int_to_char1(chrono));
    sfRenderWindow_drawText(p->window, p->text, NULL);
    boucle_avion(p, p->avion, chrono);
    boucle_tour(p, p->tour, chrono);
    if (p->black == 1)
        sfRenderWindow_clear(p->window, sfBlack);
    sfRenderWindow_display(p->window);
}
