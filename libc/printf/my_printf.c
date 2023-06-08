/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** reproduces the behaviour of printf
*/
#include "my_printf.h"

void update(args_t *arg, char c)
{
    if (arg->zero > 0 && arg->mins > 0)
        arg->zero = 0;
    if (arg->precision > 0 && arg->zero > 0 && skip_lib(c, "duioxX") == 0)
        arg->zero = 0;
    if (arg->plus > 0 && arg->space > 0)
        arg->space = 0;
    if (arg->precision > 0 && skip_lib(c, "diouxXaAeEfFgGsS") == 0)
        arg->precision = 0;
    if (skip_lib(c, "fF") != 0 && arg->precision == 0)
        arg->precision = 6;
    if (arg->sharp > 0 && skip_lib(c, "bBoXxaAeEfFgG") == 0)
        arg->sharp = 0;
    if (arg->plus > 0 && skip_lib(c, "dfFdigGaAeE") == 0)
        arg->plus = 0;
}

void parser_printf(parser_t *pr, int fd)
{
    args_t arg = {0};
    int prev_index = pr->index;

    flags(pr, &arg);
    arg.width = my_getnbr(pr->format + pr->index);
    for (; skip_lib(pr->format[pr->index], "0123456789") != 0; pr->index++);
    arg.precision = precision(pr);
    length(pr, &arg);
    if (skip_lib(pr->format[pr->index], "diouxXeEfFgGAacsbSnmp") != 0)
        conversion(pr->format[pr->index], &arg, pr, fd);
    else if (pr->format[pr->index] == '%') {
        pr->count += my_printmodulo(fd);
        pr->index++;
    } else {
        pr->index = prev_index - 1;
    }
}

int my_printf(const char *restrict format, ...)
{
    int count = 0;
    va_list ap;
    va_start(ap, format);
    count += my_vdprintf(1, format, &ap);
    va_end(ap);
    return count;
}

int my_dprintf(int fd, const char *restrict format, ...)
{
    int count = 0;
    va_list ap;
    va_start(ap, format);
    count += my_vdprintf(fd, format, &ap);
    va_end(ap);
    return count;
}

int my_vdprintf(int fd, const char *restrict format, va_list *ap)
{
    parser_t pr = { 0, 0, format, {} };
    int prev = 0;
    va_copy(pr.ap, *ap);

    while (format[pr.index] != '\0') {
        if (format[pr.index] == '%' && format[pr.index + 1] != '\0') {
            pr.index++;
            parser_printf(&pr, fd);
        }
        if (pr.index == prev) {
            pr.count++;
            my_putchar_printf(format[pr.index], fd);
            pr.index++;
        }
        prev = pr.index;
    }
    return pr.count;
}
