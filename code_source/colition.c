/*
** EPITECH PROJECT, 2023
** ProjectDay
** File description:
** test
** test
*/
#include "my.h"

static int zone(imageinfo *avion, imageinfo *tour)
{
    while (tour != NULL){
        if (sqrt(pow(tour->start.x - avion->start.x, 2) + pow(tour->start.y -
    avion->start.y, 2)) <= avion->vitesse + (tour->vitesse * 19.2))
        return 0;
        tour = tour->next;
    }
    return 1;
}

static int sup(imageinfo *avion, imageinfo *tour, imageinfo *pointer)
{
    int x = pointer->start.x - avion->start.x;
    int y = pointer->start.y - avion->start.y;
    sfColor color;

    if (pointer->crash == 0 && avion->crash == 0){
        if (x < 20 && x > -20 && y < 20 && y > -20 && zone(avion, tour)
        && avion->niveau == pointer->niveau){
            avion->crash = 1;
            pointer->crash = 1;
            color = sfColor_fromRGB(255, 0, 0);
            sfSprite_setColor(avion->sprite, color);
            sfSprite_setColor(pointer->sprite, color);
            return 1;
        }
    }
    return 0;
}

int colition(imageinfo *avion, imageinfo *tour)
{
    imageinfo *pointer;

    sup(avion, tour, avion->next);
    for (int i = 0; avion != NULL; i++){
        pointer = avion->next;
        for (int j = 0; pointer != NULL; j++){
            sup(avion, tour, pointer);
            pointer = pointer->next;
        }
        avion = avion->next;
    }
    return 0;
}
