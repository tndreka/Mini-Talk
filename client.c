/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:43:09 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/31 21:14:50 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_info_per_bit(int pid, char *s)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		j = 1;
		while (j < 8)
		{
			if ((s[i] >> j) & 1)
			{
				if (!(kill(pid, SIGUSR1)))
				{
					perror("FAILING IN SENDING SIGNAL");
					break ;
				}
			}
			else
			{
				if (!(kill(pid, SIGUSR2)))
				{
					perror("FAILING IN SENDING SIGNAL");
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;

	if (ac > 2)
	{
		pid = ft_atoi(av[1]);
		s = av[2];
		send_info_per_bit(pid, s);
	}
	write(1, "ERROR", 5);
}
