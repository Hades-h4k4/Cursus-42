/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putelse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:31:32 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/24 17:15:25 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *c)
{
	int i;

	i = 0;
	while(c[i])
	{
		ft_putchar(c[i++]);
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int i;

	i = 0;
	if(n < 0)
	{
		n = -n;
		i++;
		ft_putchar('-');
	}
	if (n >=  10)
		i += ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
	i++;
	return (i);
}

int	ft_puthex(unsigned int n, int up)
{
	int		i;
	char	*hex;

	hex = (up) ? "0123456789ABCDEF" : "0123456789abcedf";
	i = 0;
	if (n >= 16)
		i += ft_puthex(n / 16, up);
	i += ft_putchar(hex[n % 16]);
	return (i);
}

int	ft_putptr(void *p)
{
	int i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_puthex((unsigned long long)p, 0);
	return (i);
}
