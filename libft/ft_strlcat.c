/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:43:17 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/14 17:16:02 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t			i;
	unsigned int	l_dest;
	unsigned int	l_src;

	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	i = 0;
	if (l_dest >= size)
	{
		return (size + l_src);
	}
	while (src[i] && l_dest + i < size - 1)
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (l_dest + l_src);
}
