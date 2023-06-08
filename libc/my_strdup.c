/*
** EPITECH PROJECT, 2022
** oui
** File description:
** oui
*/

#include "my.h"

void *my_memset(void *ptr, int b, int size)
{
    for (int i = 0; size > i; i++)
        ((char *)ptr)[i] = b;
    return ptr;
}

char *my_strdup(char const *str)
{
    if (str == NULL)
        return NULL;
    int i = 0;
    i = my_strlen(str);
    char *str_cpy = malloc(sizeof(char) * (i + 1));
    if (str_cpy == NULL)
        return NULL;
    str_cpy = my_memset(str_cpy, 0, i);
    return my_strcpy(str_cpy, str);
}
