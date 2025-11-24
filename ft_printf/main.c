/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:34:05 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/24 17:16:05 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int *p;
	ft_printf("char[%%c]: %c\nstring[%%s]: %s\nnumber[%%d]: %d\nintergers[%%i]: %i\nhexmin[%%x]: %x\nhexmax[%%X]: %X\nunsigned[%%u]: %u\npointer[%%p]: %p\n\n", 'A', "string", 12345, 12345, 798527, 942837, -1, p);
	int a = ft_printf("%c%s%d%i%x%X%u%p\n", 'A', "BC", 123, 123, 255, 910, 321, 0);
	ft_printf("long of a: %d\n", (a - 1));
	return (0);
}