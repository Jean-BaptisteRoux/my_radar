/*
** EPITECH PROJECT, 2023
** ProjectDay03
** File description:
** test
** test
*/
#include "my.h"

int strl(char const *str)
{
    int a;

    if (str == NULL)
        return -1;
    for (a = 0; str[a] != '\0'; a++)
        continue;
    return (a);
}

int len_linked_list_tmp(linked_list_tmp *list)
{
    int i = 0;

    while (list != NULL){
        i++;
        list = list->next;
    }
    return i;
}

int len_linked_list_t(imageinfo *list)
{
    int i = 0;

    while (list != NULL){
        i++;
        list = list->next;
    }
    return i;
}

int my_put_in_list(linked_list_tmp **list, int nb)
{
    linked_list_tmp *chaine = malloc(sizeof(linked_list_tmp));

    chaine->id = nb;
    chaine->next = *list;
    *list = chaine;
    return 0;
}

static sfRectangleShape *rectangle(imageinfo *info)
{
    sfRectangleShape* circle = NULL;

    circle = sfRectangleShape_create();
    sfRectangleShape_setSize(circle, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineThickness(circle, 5.f);
    sfRectangleShape_setOutlineColor(circle, sfGreen);
    sfRectangleShape_setFillColor(circle, sfTransparent);
    sfRectangleShape_setPosition(circle, (sfVector2f){info->start.x -
    info->vitesse / 2.f, info->start.y - info->vitesse / 2.f});
    return circle;
}

static int my_put_in_list_a(imageinfo **list, char **data)
{
    imageinfo *chaine;
    sfTexture *texture = sfTexture_createFromFile("source/plane.png", NULL);
    sfSprite *tmp = NULL;

    tmp = sfSprite_create();
    sfSprite_setTexture(tmp, texture, NULL);
    chaine = malloc(sizeof(imageinfo));
    chaine->start = (sfVector2f){getnbr(data[1]), getnbr(data[2])};
    sfSprite_setPosition(tmp, chaine->start);
    chaine->end = (sfVector2f){getnbr(data[3]), getnbr(data[4])};
    chaine->vitesse = getnbr(data[5]);
    chaine->time = getnbr(data[6]);
    chaine->rect = rectangle(chaine);
    chaine->sprite = tmp;
    chaine->angle = atan2(chaine->end.y - chaine->start.y,
    chaine->end.x - chaine->start.x);
    chaine->crash = 0;
    chaine->niveau = rand() % 110;
    chaine->next = *list;
    *list = chaine;
}

static sfCircleShape *cercle(imageinfo *info)
{
    sfCircleShape* circle = NULL;

    circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, (info->vitesse / 2.f) * 19.2);
    sfCircleShape_setOutlineThickness(circle, 5.f);
    sfCircleShape_setOutlineColor(circle, sfBlue);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOrigin(circle, (sfVector2f){(info->vitesse / 2.f)
    * 19.2, (info->vitesse / 2.f) * 19.2});
    sfCircleShape_setPosition(circle, (sfVector2f){info->start.x +
    (261 * 0.375 - 5), info->start.y + (261 * 0.196875 - 5)});
    return circle;
}

static int my_put_in_list_t(imageinfo **list, char **data)
{
    imageinfo *chaine;
    sfTexture *texture = sfTexture_createFromFile("source/tower.png", NULL);
    sfSprite *tmp = NULL;

    chaine = malloc(sizeof(imageinfo));
    tmp = sfSprite_create();
    sfSprite_setTexture(tmp, texture, NULL);
    chaine->start.x = getnbr(data[1]);
    chaine->start.y = getnbr(data[2]);
    sfSprite_setPosition(tmp, chaine->start);
    chaine->end.x = 0;
    chaine->end.y = 0;
    chaine->vitesse = getnbr(data[3]);
    chaine->time = 0;
    chaine->zone = cercle(chaine);
    chaine->sprite = tmp;
    chaine->crash = 0;
    chaine->next = *list;
    *list = chaine;
    return 0;
}

imageinfo *my_params_to_list(char ***av, char deteminant)
{
    imageinfo *list = NULL;

    for (int i = 0; av[i] != NULL; i++) {
        if (av[i][0][0] == deteminant && deteminant == 'A')
            my_put_in_list_a(&list, av[i]);
        if (av[i][0][0] == deteminant && deteminant == 'T')
            my_put_in_list_t(&list, av[i]);
    }
    return list;
}
