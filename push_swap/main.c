/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:56:14 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/30 19:07:51 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_node *top)
{
    t_node *current;

    current = top;
    ft_printf("--- Pila ---\n");
    while (current != NULL)
    {
        // 3. Imprimir el valor del nodo actual
        ft_printf("| %d (index: %d) |\n", current->value, current->size);
        
        // 4. Mover al siguiente nodo
        current = current->next;
    }
    ft_printf("------------\n\n");
}

int main(int argc, char **argv)
{
	t_node	*node;
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	node = NULL; //inicializated by null to avoid segsiv.
	a->top = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error");
		return (1);
	}
	else if (argc == 2)
		node = format_argv_char(argv[1], a);//also checks that the inputs is correct.
	else if (argc > 2)
		node = normal_input(argv, a, argc);
	ft_print_stack(node);
	return (0);
}



