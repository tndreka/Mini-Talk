/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:14:41 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 01:03:45 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec_int(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		if (*get_flag())
			return (-1);
		i += ft_print_char('-');
		return (ft_print_dec_int(-n) + 1);
	}
	else if (n < 10)
	{
		if (*get_flag())
			return (-1);
		i += ft_print_char(n + 48);
	}
	else
	{
		i += ft_print_dec_int(n / 10);
		i += ft_print_dec_int(n % 10);
		if (*get_flag())
			return (-1);
	}
	return (i);
}
