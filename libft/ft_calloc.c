/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:46:12 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/14 17:21:56 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total;
	unsigned char	*p;

	total = nmemb * size;
	p = (unsigned char *)malloc(total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return ((void *)p);
}
