#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *input, ...);
int ft_putchar(char c);
int	format(char c, int vargs);

#endif