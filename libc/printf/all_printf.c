/*
** EPITECH PROJECT, 2023
** B-CPE-200-RUN-2-1-corewar-julien.ferdinand
** File description:
** all_printf
*/
#include "my_printf.h"

int my_fprintf(FILE *file, const char *restrict format, ...)
{
    int count = 0;
    va_list ap;
    va_start(ap, format);
    count += my_vdprintf(file->_fileno, format, &ap);
    va_end(ap);
    return count;
}

int my_vfprintf(FILE *file, const char *restrict format, va_list *ap)
{
    return my_vdprintf(file->_fileno, format, ap);
}

int my_vprintf(const char *restrict format, va_list *ap)
{
    return my_vdprintf(1, format, ap);
}
