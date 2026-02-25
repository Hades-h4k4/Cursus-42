/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:23:16 by carltruj          #+#    #+#             */
/*   Updated: 2026/02/25 13:23:44 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	index_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*check;
	int		count;

	ptr = *stack;
	while (ptr)
	{
		count = 0;
		check = *stack;
		while (check)
		{
			if (check->value < ptr->value)
				count++;
			check = check->next;
		}
		ptr->index = count;
		ptr = ptr->next;
	}
}

static void	check_dups(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				ft_error();
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static void	process_split(char **tmp_args, t_stack **a)
{
	int		j;
	long	nb;

	j = 0;
	while (tmp_args[j])
	{
		nb = ft_atoi(tmp_args[j]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error();
		ft_lstadd_back(a, ft_lstnew((int)nb));
		free(tmp_args[j]);
		j++;
	}
	free(tmp_args);
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**tmp_args;

	i = 1;
	while (i < argc)
	{
		tmp_args = ft_split(argv[i], ' ');
		if (!tmp_args)
			ft_error();
		process_split(tmp_args, a);
		i++;
	}
	if (!*a)
		exit(0);
	check_dups(*a);
	index_stack(a);
}
