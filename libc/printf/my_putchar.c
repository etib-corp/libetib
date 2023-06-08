/*
** EPITECH PROJECT, 2022
** my_putchar.c
** File description:
** puts char
*/

#include "my_printf.h"

int my_putchar_printf(char c, int fd)
{
    return write(fd, &c, 1);
}

int my_printchar(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    char c = va_arg(*list, int);
    (void)pr;
    int count = 0;
    c = my_length_of_c(arg, c);

    count += my_flags(arg, 1, fd);
    count += my_putchar_printf(c, fd);
    count += my_endflags(arg, 1, count, fd);
    if (arg->width > 0)
        return arg->width;
    return 1;
}
