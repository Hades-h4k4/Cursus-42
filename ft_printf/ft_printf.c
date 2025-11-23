/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:11:21 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/23 19:27:23 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char c, va_list vargs)
{
	if (c == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	if (c == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(vargs, int)));

		
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int ft_printf(const char *input, ...)
{
	va_list vargs;
	va_start(vargs, input);
	int i;

	i = 0;
	while(*input)
	{
		
			if(*input == '%')
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