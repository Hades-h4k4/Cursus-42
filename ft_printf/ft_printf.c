/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:11:21 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/23 18:44:41 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char c, int vargs)
{
	if (c == 'c')
		return (ft_putchar((char)vargs));
	return (0);
}

int ft_printf(const char *input, ...)
{
	va_list vargs;
	va_start(vargs, input);
	int i;
	int sig;

	i = 0;
	while(*input)
	{
		
			if(*input == '%')
			{
				input++;
				sig = va_arg(vargs, int);
				i += format(*input, sig);
			}
			else
				i += ft_putchar(*input);
			input++;
	}
	va_end(vargs);
	return (i);
}