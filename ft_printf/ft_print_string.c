/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:15:15 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 00:55:39 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			set_flag(1);
		if (*get_flag())
			return (-1);
		return (6);
	}
	while (*str)
	{
		ft_print_char((int)*str);
		if (*get_flag())
			return (-1);
		++str;
		++i;
	}
	return (i);
}
