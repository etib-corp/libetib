/*
** EPITECH PROJECT, 2022
** parser.c
** File description:
** make parsing for my_printf
*/

#include "my_printf.h"

int skip_lib(const char c, const char *tokens)
{
    int i = 0;

    while (tokens[i] != '\0') {
        if (tokens[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}

void length(parser_t *pr, args_t *arg)
{
    length_t length[] = {
        {'l', 1}, {'h', 2}, {'L', 3}, {'q', 9},
        {'j', 4}, {'z', 5}, {'t', 6}, {'\0', 0}
    };
    if (pr->format[pr->index] == pr->format[pr->index + 1]) {
        if (pr->format[pr->index] == 'l') {
            pr->index = pr->index + 2;
            arg->length = 7;
        }
        if (pr->format[pr->index] == 'h') {
            pr->index = pr->index + 2;
            arg->length = 8;
        }
    }
    for (int i = 0; length[i].l_type != '\0'; i++) {
        if (length[i].l_type == pr->format[pr->index]) {
            pr->index++;
            arg->length = length[i].v_type;
        }
    }
}

int precision(parser_t *pr)
{
    int nb = 0;

    if (pr->format[pr->index] != '.') {
        return 0;
    }
    if (skip_lib(pr->format[pr->index + 1], "0123456789FfxXdioubB") != 0) {
        pr->index++;
        nb = my_getnbr(pr->format + pr->index);
        for (; skip_lib(pr->format[pr->index] , "0123456789") != 0;
        pr->index++);
    }
    if (nb == 0)
        return -1;
    return nb;
}

void conversion(char c, args_t *arg, parser_t *pr, int fd)
{
    convert_t conv[] = {
        {'d', my_printnbr}, {'i', my_printnbr}, {'o', my_printnbr_octal},
        {'u', my_printusnbr}, {'x', my_printnbr_hexa}, {'X', my_printnbr_mhexa},
        {'f', my_printfloat}, {'F', my_printfloat}, {'c', my_printchar},
        {'s', my_printstr}, {'p', my_printptr}, {'n', my_printnbr_wtn},
        {'S', my_showva}, {'b', my_printnbr_bin}, {'\0', NULL},
    };
    int i = 0;

    for (; conv[i].flag_type != c && i <= 12; i++);
    if (conv[i].flag_type == '\0')
        return;
    arg->conversion = conv[i].flag_type;
    update(arg, conv[i].flag_type);
    pr->count += conv[i].exec(&pr->ap, arg, pr, fd);
    pr->index++;
}

void flags(parser_t *pr, args_t *arg)
{
    while (skip_lib(pr->format[pr->index], "#-0 +") != 0) {
        switch (pr->format[pr->index]) {
        case ' ':
            arg->space++;
            break;
        case '+':
            arg->plus++;
            break;
        case '-':
            arg->mins++;
            break;
        case '0':
            arg->zero++;
            break;
        case '#':
            arg->sharp++;
            break;
        }
        pr->index++;
    }
}
