/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:15:40 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 00:49:10 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(unsigned long n, unsigned long base, char *numb)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (*get_flag())
			return (-1);
		i += ft_print_char('-');
		n = -1 * n;
	}
	if (n < base)
	{
		if (*get_flag())
			return (-1);
		return (ft_print_char(numb[n]));
	}
	i = ft_print_digit(n / base, base, numb);
	return (i + ft_print_digit(n % base, base, numb));
}
