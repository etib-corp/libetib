/*
** EPITECH PROJECT, 2022
** my_printnbr_base.c
** File description:
** print nbrs in a base
*/

#include "my_printf.h"

int my_putnbr_base(size_t nbr, char const *base, int fd)
{
    size_t d = 1;
    int i = 0;
    size_t len = my_strlen(base);

    while (nbr / d >= len)
        d = d * len;
    while (d >= 1) {
        i = i + my_putchar_printf(base[nbr / d % len], fd);
        d = d / len;
    }
    return i;
}

int my_printnbr_octal(va_list *ap, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    size_t value = va_arg(*ap, size_t);
    char base[] = "01234567";
    int len = my_lennbr_base(value, base);
    int count = 0;
    value = my_length_ic(arg, value);

    count += my_flags(arg, len, fd);
    count += my_putnbr_base(value, base, fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0)
        return arg->width;
    return count - len;
}

int my_printnbr_hexa(va_list *ap, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    size_t value = va_arg(*ap, size_t);
    char base[] = "0123456789abcdef";
    int len = my_lennbr_base(value, base);
    int count = 0;
    value = my_length_ic(arg, value);

    count += my_flags(arg, len, fd);
    count += my_putnbr_base(value, base, fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0)
        return arg->width;
    return count - len;
}

int my_printnbr_mhexa(va_list *ap, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    size_t value = va_arg(*ap, size_t);
    char base[] = "0123456789ABCDEF";
    int len = my_lennbr_base(value, base);
    int count = 0;
    value = my_length_ic(arg, value);

    count += my_flags(arg, len, fd);
    count += my_putnbr_base(value, base, fd);
    count += my_endflags(arg, len, count, fd);
    if (arg->width > 0)
        return arg->width;
    return count - len;
}

int my_printptr(va_list *list, args_t *arg, parser_t *pr, int fd)
{
    (void)pr;
    int count = 0;
    char base[] = "0123456789abcdef";
    unsigned long long value = va_arg(*list, size_t);
    int len = my_lennbr_base(value, base);

    count += my_flags(arg, len, fd);
    count += my_putstr_printf("0x", 2, fd);
    count += my_putnbr_base(value, base, fd);
    count += my_endflags(arg, len, count, fd);
    return count;
}
