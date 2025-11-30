/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:19:35 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/30 17:02:18 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	temp;
	int			sing;

	temp = 0;
	i = 0;
	sing = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sing = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		temp = (temp * 10) + (nptr[i] - '0');
		i++;
	}
	return (temp * sing);
}
