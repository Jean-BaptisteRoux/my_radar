/*
** EPITECH PROJECT, 2023
** ProjectDay03
** File description:
** test
** test
*/
#include "my.h"

int end_avion(imageinfo **head)
{
    imageinfo *list = *head;
    imageinfo *reste = *head;

    while (list->next->next != NULL)
        list = list->next;
    if (list->next->crash == 1){
        list->next = NULL;
    }
    *head = reste;
    return 1;
}
