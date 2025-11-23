/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:39:08 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/14 17:35:56 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	lon;

	i = 0;
	lon = 0;
	while (src[lon])
	{
		lon++;
	}
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
	{
		dest[i] = '\0';
	}
	return (lon);
}
