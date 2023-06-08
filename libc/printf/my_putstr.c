/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** puts a string
*/

#include "my_printf.h"

int my_putstr_printf(char const *str, int s, int fd)
{
    if (s < my_strlen(str) && s != 0)
        return write(fd, str, s);
    else
        return write(fd, str, my_strlen(str));
}

static char *my_length_of_s(args_t *arg, char *value)
{
    data_t data;

    data.str = value;
    if (arg->length == 1)
        return "0";
    return data.str;
}

int my_printstr(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    int count = 0;
    char *value = va_arg(*list, char *);
    int len = 0;
    value = my_length_of_s(arg, value);

    if (arg->precision > 0 && arg->precision < my_strlen(value))
        len = arg->precision;
    else
        len = my_strlen(value);
    count += my_flags(arg, len, fd);
    count += my_putstr_printf(value, arg->precision, fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0)
        return arg->width;
    return count - len;
}
