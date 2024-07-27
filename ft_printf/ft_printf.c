/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:13:34 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 00:59:49 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *buffer, ...)
{
	va_list	pa;
	size_t	index;

	va_start(pa, buffer);
	index = 0;
	set_flag(0);
	while (*buffer)
	{
		if (*buffer == '%')
		{
			++buffer;
			index += ft_format_printer(*(buffer), pa);
			if (*get_flag())
				return (-1);
		}
		else
		{
			index += ft_print_char(*buffer);
			if (*get_flag())
				return (-1);
		}
		++buffer;
	}
	va_end(pa);
	return (index);
}
