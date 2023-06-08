/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-julien.ferdinand
** File description:
** mutli_av
*/

#include "my.h"

int multiple_arg(char *field, char **av)
{
    if (field == NULL || av == NULL)
        return true;
    int n = 0;
    for (int i = 0; av[i]; i++) {
        if (my_strcmp(field, av[i]) == 0)
            n++;
    }
    return n;
}
