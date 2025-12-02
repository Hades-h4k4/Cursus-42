/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:44:28 by carltruj          #+#    #+#             */
/*   Updated: 2025/12/02 18:44:31 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2 && (*a)->value > (*a)->next->value)
		op_s(a, "sa\n");
	else if (size == 3)
	{
		if ((*a)->value > (*a)->next->value && (*a)->value > ft_lstlast(*a)->value)
			op_r(a, "ra\n");
		if ((*a)->next->value > (*a)->value 
			&& (*a)->next->value > ft_lstlast(*a)->value)
			op_rr(a, "rra\n");
		if ((*a)->value > (*a)->next->value)
			op_s(a, "sa\n");
	}
	(void)b;
}

static int	get_max_pos(t_stack *stack, int max_idx)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == max_idx)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	range;

	i = 0;
	range = 15;
	if (size >= 500)
		range = 30;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			op_p(a, b, "pb\n");
			op_r(b, "rb\n");
			i++;
		}
		else if ((*a)->index <= i + range)
		{
			op_p(a, b, "pb\n");
			i++;
		}
		else
			op_r(a, "ra\n");
	}
}

void	radix_butterfly(t_stack **a, t_stack **b, int size)
{
	int	pos;
	int	curr_max;

	push_to_b(a, b, size);
	curr_max = size - 1;
	while (*b)
	{
		pos = get_max_pos(*b, curr_max);
		if (pos <= ft_lstsize(*b) / 2)
		{
			while ((*b)->index != curr_max)
				op_r(b, "rb\n");
		}
		else
		{
			while ((*b)->index != curr_max)
				op_rr(b, "rrb\n");
		}
		op_p(b, a, "pa\n");
		curr_max--;
	}
}
