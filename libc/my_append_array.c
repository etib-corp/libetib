/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-lemin-clement-antoine.xavier
** File description:
** my_append_array
*/

#include "my.h"

char **append_array(char *str, char **array)
{
    if (str == NULL)
        return NULL;
    int size = len_array(array);
    char **new = malloc(8 * (size + 2));
    if (new == NULL)
        return NULL;
    int x = 0;
    for (int i = 0; array != NULL && array[i] != NULL; i++) {
        new[x] = array[i];
        x++;
    }
    new[x] = str;
    new[x + 1] = NULL;
    MY_FREE(array, free);
    return new;
}
