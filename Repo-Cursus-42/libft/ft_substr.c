/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:30:10 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/17 18:03:05 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_substr_len(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	if (len > ft_strlen(s + start))
		len = (ft_strlen(s + start));
	return (len);
}

char	*ft_if_zero(void)
{
	char	*sub;

	sub = malloc(1);
	if (!sub)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	real_len;
	char	*sub;

	if (!s)
		return (NULL);
	real_len = ft_substr_len(s, start, len);
	if (real_len == 0)
	{
		sub = ft_if_zero();
		return (sub);
	}
	sub = malloc((real_len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < real_len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
