/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:42:40 by carltruj          #+#    #+#             */
/*   Updated: 2025/12/02 18:47:28 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* utils.c */
void	ft_error(void);
long	ft_atoi(const char *str);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

/* ops.c */
void	op_s(t_stack **stack, char *str);
void	op_p(t_stack **src, t_stack **dst, char *str);
void	op_r(t_stack **stack, char *str);
void	op_rr(t_stack **stack, char *str);
int		ft_lstsize(t_stack *lst);

/* sort.c */
void	simple_sort(t_stack **a, t_stack **b);
void	radix_butterfly(t_stack **a, t_stack **b, int size);

/* main.c (helper) */
void	index_stack(t_stack **stack);
void	free_stack(t_stack **stack);

#endif