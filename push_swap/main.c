/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:44:59 by carltruj          #+#    #+#             */
/*   Updated: 2026/02/25 13:23:32 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int     size;

    a = NULL;
    b = NULL;
    if (argc < 2)
        return (0);

    // Esta función ahora limpia comillas y argumentos sueltos por igual
    parse_args(argc, argv, &a);

    size = ft_lstsize(a);

    // Gestión de algoritmos
    if (size == 2 && a->value > a->next->value)
        ft_sa(&a, "sa");
    else if (size <= 3)
        simple_sort(&a, &b);
    else
        radix_butterfly(&a, &b, size);

    free_stack(&a);
    free_stack(&b);
    return (0);
}
