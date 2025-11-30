/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:40:19 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/30 19:10:17 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_digit(int c)
{
	if ((c <= '9' && c >= '0')|| c == 32 || c == '-')
		return (1);
	return (0);
}

static void	free_lst(char **lst)
{
	int i;

	i = 0;
	while(lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

t_node	*format_argv_char(char *str, t_stack *a)
{
	t_node *node;
	int num;
	char **lst;
	int i;

	lst = ft_split(str, ' ');
	if (!lst)
		return (NULL);
	i = 0;
	while (lst[i])
		i++;
	while(i-- >= 1)
	{
		num = ft_atoi(lst[i]);
		node = ft_new_node(num);
		ft_add_top(a, node);
	}
	free_lst(lst);
	return (node);
}

t_node	*normal_input(char **str, t_stack *a, int i)
{
	t_node *node;
	int num;
	int j;

	i--;
	j = 1;
	while(j <= i)
	{
		ft_printf("%d\n", ft_atoi(str[j]));
		if(is_digit(*str[j]))
			j++;
		else
		{
			ft_printf("Error\n");
			return (NULL);
		}
	}	
	while(i >= 1)
	{
		num = ft_atoi(str[i]);
		node = ft_new_node(num);
		ft_add_top(a, node);
		i--;
	}
	return (node);
}
