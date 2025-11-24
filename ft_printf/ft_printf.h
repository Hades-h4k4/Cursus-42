#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_printf(const char *input, ...);
int ft_putchar(char c);
int	format(char c, va_list vargs);
int	ft_putstr(char *c);
int	ft_putnbr(long n);
int	ft_puthex(unsigned int n, int up);
int	ft_putptr(void *p);

#endif