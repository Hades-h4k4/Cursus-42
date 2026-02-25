/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtions.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:14:40 by carltruj          #+#    #+#             */
/*   Updated: 2026/02/15 16:17:35 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*free_all(char **tab, int count)
{
	while (count--)
		free(tab[count]);
	free(tab);
	return (NULL);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*copy_word(const char *str, int start, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	word_len(const char *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i + len] && str[i + len] != c)
		len++;
	return (len);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!tab || !str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (word_len(str, i, c) > 0)
		{
			tab[j] = copy_word(str, i, word_len(str, i, c));
			if (!tab[j])
				return (free_all(tab, j));
			j++;
			i += word_len(str, i, c);
		}
	}
	tab[j] = NULL;
	return (tab);
}
