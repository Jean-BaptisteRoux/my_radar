/*
** EPITECH PROJECT, 2023
** ProjectDay03
** File description:
** test
** test
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void my_rev_list(linked_list_tmp **begin)
{
    linked_list_tmp *jsp = NULL;
    linked_list_tmp *mdr = NULL;
    linked_list_tmp *osef = *begin;

    while (osef != NULL) {
        mdr = osef->next;
        osef->next = jsp;
        jsp = osef;
        osef = mdr;
    }
    *begin = jsp;
}
