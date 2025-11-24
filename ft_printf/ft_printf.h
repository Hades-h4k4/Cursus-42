/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carltruj <carltruj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:25:32 by carltruj          #+#    #+#             */
/*   Updated: 2025/11/24 17:43:41 by carltruj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_putchar(char c);
int	format(char c, va_list vargs);
int	ft_putstr(char *c);
int	ft_putnbr(long n);
int	ft_puthex(unsigned long long n, int up);
int	ft_putptr(void *p);

#endif