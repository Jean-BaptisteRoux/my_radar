/*
** EPITECH PROJECT, 2023
** ProjectDay
** File description:
** test
** test
*/
#include "my.h"

static char **suite(char *str, linked_list_tmp *list)
{
    int len;
    char **dest = NULL;
    int tmp = 0;

    len = len_linked_list_tmp(list);
    dest = malloc(sizeof(char *) * (len + 1));
    tmp = 0;
    for (int i = 0; i < len; i++){
        dest[i] = malloc(sizeof(char) * list->id);
        for (int j = 0; j < list->id; j++){
            dest[i][j] = str[tmp];
            tmp++;
        }
        tmp++;
        dest[i][list->id + 1] = '\0';
        list = list->next;
    }
    dest[len + 1] = NULL;
    return dest;
}

char **str_to_array(char *str)
{
    char sep = ' ';
    linked_list_tmp *list = NULL;
    int tmp = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != sep){
            tmp++;
        } else {
            my_put_in_list(&list, tmp);
            tmp = 0;
        }
    }
    my_put_in_list(&list, tmp);
    my_rev_list(&list);
    return suite(str, list);
}

static int menu(char ***info)
{
    parametre_t *paramètres = initialisation_windows(info);

    letsbeguinthegame(paramètres);
    return 0;
}

char ***traitement_fichier(int compar, FILE *fd)
{
    char ***fichier;
    char *str;
    size_t len = 0;

    fichier = malloc(sizeof(char **) * compar);
    for (int i = 0; i <= compar + 1; i++){
        getline(&str, &len, fd);
        fichier[i] = str_to_array(str);
    }
    srand(time(NULL));
    fichier[compar + 1] = NULL;
    menu(fichier);
    return fichier;
}

static int help(void)
{
    char *str;
    size_t len = 0;
    FILE *fd;

    fd = fopen("-h", "r");
    for (int i = 0; i < 9; i++){
        getline(&str, &len, fd);
        write(1, str, strl(str));
    }
    getline(&str, &len, fd);
    write(1, str, strl(str)-50);
    write(1, "\n", 1);
    return 0;
}

int main(int ac, char **argv)
{
    int fd;
    int size = 1;
    char tmp[1] = " ";
    int compar = 0;

    if (ac != 2)
        return 84;
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        return help();
    fd = open(argv[1], O_RDONLY, S_IRWXU);
    if (fd == -1)
        return 84;
    while (size == 1){
        size = read(fd, tmp, 1);
        if (tmp[0] == '\n')
            compar++;
    }
    close(fd);
    traitement_fichier(compar, fopen(argv[1], "r"));
}
