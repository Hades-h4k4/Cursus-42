/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:57:27 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/30 16:59:09 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	format(char c, va_list vargs)
{
	if (c == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	if (c == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(vargs, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(vargs, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(vargs, unsigned int), 1));
	if (c == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	vargs;
	int		i;

	va_start(vargs, input);
	i = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			i += format(*input, vargs);
		}
		else
			i += ft_putchar(*input);
		input++;
	}
	va_end(vargs);
	return (i);
}