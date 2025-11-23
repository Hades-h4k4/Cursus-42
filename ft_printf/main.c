/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:34:05 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/23 19:30:32 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("char[%%c]: %c\nstring[%%s]: %s\nnumber[%%d]: %d\n", 'A', "string", 12345);
	int a = ft_printf("%c%s%d", 'A', "BC", 123);
	ft_printf("long of a: %d", a);
	return (0);
}