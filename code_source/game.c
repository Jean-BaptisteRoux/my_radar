/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

int condition(imageinfo *list)
{
    if (sqrt(pow(list->end.x - list->start.x, 2) + pow(list->end.y -
    list->start.y, 2)) <= list->vitesse)
        return 1;
    return 0;
}

void avanceravion(parametre_t *p)
{
    int chrono = sfTime_asMilliseconds(sfClock_getElapsedTime
    (p->chrono)) / 1000;
    imageinfo *pointer = p->avion;
    float dx;
    float dy;

    for (int i = 0; pointer != NULL; i++){
        if (pointer->time < chrono && pointer->crash == 0){
            dx = pointer->vitesse * cos(pointer->angle);
            dy = pointer->vitesse * sin(pointer->angle);
            pointer->start.x += dx;
            pointer->start.y += dy;
            sfSprite_setPosition(pointer->sprite, pointer->start);
            sfRectangleShape_setPosition(pointer->rect, (sfVector2f)
            {pointer->start.x + pointer->vitesse / 2.f + 0, pointer->
            start.y + pointer->vitesse / 2.f + 0});
        }
        pointer = pointer->next;
    }
}

static int atteri(imageinfo *avion)
{
    int x;
    int y;
    int tmp;
    int retour = 0;

    while (avion){
        x = avion->start.x - avion->end.x;
        y = avion->start.y - avion->end.y;
        tmp = avion->vitesse;
        if (x < tmp && x > -tmp && y < tmp && y > -tmp && avion->crash == 0){
            avion->crash = 1;
            retour++;
        }
        avion = avion->next;
    }
    return retour;
}

static int end(imageinfo *avion)
{
    while (avion){
        if (avion->crash != 1)
            return 0;
        avion = avion->next;
    }
    return 1;
}

static void fin(parametre_t *p)
{
    pnbr(p->arrive);
    write(1, " avion(s) arrivé(s) sur ", 25);
    pnbr(len_linked_list_t(p->avion));
    write(1, "\n", 1);
    disp_sprite(p);
    sleep(1);
    sfRenderWindow_close(p->window);
    free(p);
    return;
}

void boucle(parametre_t *p)
{
    sfClock *chrono2 = sfClock_create();

    while (sfRenderWindow_isOpen(p->window)) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(p->chrono)) > 2){
            sfClock_restart(chrono2);
            avanceravion(p);
        }
        event(p);
        disp_sprite(p);
        colition(p->avion, p->tour);
        end_avion(&(p->avion));
        p->arrive += atteri(p->avion);
        if (end(p->avion)){
            return fin(p);
        }
    }
}

void letsbeguinthegame(parametre_t *p)
{
    playmusic("source/Stardew Valley OST Stardew Valley Overture.ogg", 1);
    sfRenderWindow_display(p->window);
    ajuste_fond(p);
    boucle(p);
}
