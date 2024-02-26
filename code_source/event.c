/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** Réalisation d'un jeu de tir simple
*/

#include "my.h"

void taille(parametre_t *p)
{
    sfVector2u tailleActuelle = sfRenderWindow_getSize(p->window);
    sfVector2u tailleMin = {800, 600};
    sfVector2u tailleMax = {1920, 1080};

    if (tailleActuelle.x < tailleMin.x || tailleActuelle.y < tailleMin.y) {
        sfRenderWindow_setSize(p->window, tailleMin);
    } else if (tailleActuelle.x > tailleMax.x ||
        tailleActuelle.y > tailleMax.y) {
        sfRenderWindow_setSize(p->window, tailleMax);
    }
}

static void touche(parametre_t *p)
{
    if (p->event.text.unicode == 'l')
        p->touche_rc *= -1;
    if (p->event.text.unicode == 's')
        p->touche_sprite *= -1;
}

void event(parametre_t *p)
{
    while (sfRenderWindow_pollEvent(p->window, &(p->event))) {
        switch (p->event.type){
            case sfEvtClosed:
                sfRenderWindow_close(p->window);
                return;
            case sfEvtResized:
                taille(p);
            case sfEvtTextEntered:
                touche(p);
            default:
                continue;
        }
    }
}
