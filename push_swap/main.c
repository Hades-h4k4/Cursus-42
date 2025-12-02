/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:44:59 by carltruj          #+#    #+#             */
/*   Updated: 2025/12/02 18:45:02 by carltruj         ###   ########.fr       */
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

static void	parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error();
		ft_lstadd_back(a, ft_lstnew((int)nb));
		i++;
	}
	check_dups(*a);
	index_stack(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	size = ft_lstsize(a);
	if (size <= 3)
		simple_sort(&a, &b);
	else
		radix_butterfly(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
