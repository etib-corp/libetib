/*
** EPITECH PROJECT, 2023
** mystrlen
** File description:
** mystrlen
*/
#include "my.h"

int len_array(char **array)
{
    if (array == NULL)
        return 0;
    int i = 0;
    while (array[i] != NULL)
        i++;
    return i;
}
