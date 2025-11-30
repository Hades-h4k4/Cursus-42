/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:56:36 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/30 18:44:37 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
    int value;	// interger number.
    int index;
	int size;	// index to manipulate the interger.
    struct s_node *next;	// Ponter of the next node of stack.
    struct s_node *prev;  
} t_node;

typedef struct t_stack {
	t_node *top;
} t_stack;

// funtions used for printf.
int	ft_printf(const char *input, ...);
int	ft_putchar(char c);
int	format(char c, va_list vargs);
int	ft_putstr(char *c);
int	ft_putnbr(long n);
int	ft_puthex(unsigned long long n, int up);
int	ft_putptr(void *p);

//funtions only for the format of the input.
char	**ft_split(char const *str, char c);
int		ft_atoi(const char *nptr);
t_node	*format_argv_char(char *str, t_stack *a);
t_node	*normal_input(char **str, t_stack *a, int i);
int		is_digit(int c);

//funtions of push.
t_node *ft_new_node(int value);
void ft_add_top(t_stack *stack, t_node *new_node);

#endif