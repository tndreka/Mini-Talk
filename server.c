/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:52:59 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/03 16:29:06 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	signal_converter(int signb, char *c)
{
	if (signb == SIGUSR1)
		*c = *c << 1 | 1;
	else if (signb == SIGUSR2)
		*c = *c << 1;
}





