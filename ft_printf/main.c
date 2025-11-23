/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:34:05 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/23 19:37:11 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("char[%%c]: %c\nstring[%%s]: %s\nnumber[%%d]: %d\nintergers[%%i]: %i\n\n", 'A', "string", 12345, 12345);
	int a = ft_printf("%c%s%d%i\n", 'A', "BC", 123, 123);
	ft_printf("long of a: %d\n", a);
	return (0);
}