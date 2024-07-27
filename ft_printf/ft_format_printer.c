/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:14:44 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 00:45:14 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_printer(char format, va_list pa)
{
	int	index;

	index = 0;
	if (format == '%')
		index += ft_print_char((int) '%');
	if (format == 'c')
		index += ft_print_char(va_arg(pa, int));
	else if (format == 's')
		index += ft_print_string(va_arg(pa, char *));
	else if (format == 'd' || format == 'i')
		index += ft_print_dec_int(va_arg(pa, int));
	else if (format == 'u')
		index += ft_print_digit(va_arg(pa, unsigned int), 10, "0123456789");
	else if (format == 'x')
		index += ft_print_digit(va_arg(pa, unsigned int), 16, \
		"0123456789abcdef");
	else if (format == 'X')
		index += ft_print_digit(va_arg(pa, unsigned int), 16, \
		"0123456789ABCDEF");
	else if (format == 'p')
		index += ft_print_pointer((unsigned long long)va_arg(pa, void *), 16, \
		"0123456789abcdef");
	return (index);
}
