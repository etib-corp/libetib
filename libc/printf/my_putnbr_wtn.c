/*
** EPITECH PROJECT, 2022
** my_putnbr_wtn.c
** File description:
** the number of characters written so far
*/

#include "my_printf.h"

int my_printnbr_wtn(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    (void)fd;
    long long *nb = 0;
    nb = my_length_of_n(arg, nb);
    *va_arg(*list, long long*) = pr->count;
    return 0;
}

int my_printnbr_bin(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    size_t value = va_arg(*list,size_t);
    int len = my_lennbr_base(value, "01");
    int count = 0;
    value = my_length_ic(arg, value);

    count += my_flags(arg, len, fd);
    count += my_putnbr_base(value, "01", fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0 && arg->sharp == 0)
        return arg->width;
    if (arg->width > 0 && arg->width > len)
        return 1 + arg->width;
    return count - len;
}
