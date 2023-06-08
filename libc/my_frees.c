/*
** EPITECH PROJECT, 2023
** my_frees.c
** File description:
** len of an array
*/

#include "my.h"

void free_char_array(char **array)
{
    for (int i = 0; array != NULL && array[i] != NULL; i++)
        free(array[i]);
    if (array != NULL)
        free(array);
}
