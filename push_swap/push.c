/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:57:36 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/30 17:49:56 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *ft_new_node(int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);

    new_node->value = value;
    new_node->index = 0;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
} 

void ft_add_top(t_stack *stack, t_node *new_node)
{
    if (stack == NULL || new_node == NULL)
        return;
    new_node->next = stack->top;
    stack->top = new_node;
}