/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:54:13 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 00:44:12 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long n, int base, char *numb)
{
	int	index;

	index = 0;
	index = write(1, "0x", 2);
	if (index == -1)
		set_flag(1);
	if (*get_flag())
		return (-1);
	index += ft_print_digit(n, base, numb);
	return (index);
}
