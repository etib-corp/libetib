/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-julien.ferdinand
** File description:
** get_av
*/
#include "my.h"

int get_int(char *field, char **av, int error_return, int not_found_return)
{
    int n = 0;
    int i = 0;
    if (av == NULL || field == NULL || my_strlen(field) == 0)
        return error_return;
    for ( ; av[i]; i++) {
        if (my_strcmp(av[i], field) == 0) {
            n = my_getnbr(av[i + 1]);
            break;
        }
    }
    if (av[i] == NULL)
        return not_found_return;
    if ((av[i + 1] == NULL || !my_str_is_digit(av[i + 1])))
        return error_return;
    return n;
}
