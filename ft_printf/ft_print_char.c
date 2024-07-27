/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:15:04 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 00:38:38 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(int flag)
{
	*get_flag() = flag;
}

int	*get_flag(void)
{
	static int	flag;

	return (&flag);
}

int	ft_print_char(int c)
{
	if (write(1, &c, 1) == -1)
		set_flag(1);
	return (1);
}
