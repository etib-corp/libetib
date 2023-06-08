/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** put nbrs
*/
#include "my_printf.h"

int my_put_nbr_printf(long long nb, int fd)
{
    int i = 0;
    long long d = 1;

    if (nb < 0) {
        nb = -nb;
        i = i + my_putchar_printf('-', fd);
    }
    while (nb / d > 9) {
        d *= 10;
    }
    while (d >= 1) {
        i += my_putchar_printf((nb / d % 10) + '0', fd);
        d = d / 10;
    }
    return i;
}

int my_put_usnbr(unsigned long long nb, int fd)
{
    int i = 0;
    long long d = 1;

    while (nb / d > 9) {
        d = d * 10;
    }
    while (d >= 1) {
        i = i + my_putchar_printf((nb / d % 10) + '0', fd);
        d = d / 10;
    }
    return i;
}

int my_printnbr(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    long long value = va_arg(*list, long long);
    int len = my_lennbr(value);
    int count = 0;
    value = my_length_of_di(arg, value);

    count += my_flags(arg, len, fd);
    count += my_put_nbr_printf(value, fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0)
        return arg->width;
    if (value >= 0)
        return count - len;
    return len / 2 + 1;
}

int my_printusnbr(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    unsigned long long value = va_arg(*list, unsigned long long);
    int len = my_lennbr(value);
    int count = 0;
    value = my_length_ic(arg, value);

    count += my_flags(arg, len, fd);
    count += my_put_usnbr(value, fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0)
        return arg->width;
    return count - len;
}
