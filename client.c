/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:43:09 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/01 21:29:16 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// this global variable is used as a flag to notyfy for each signal 
//that the function receves
static int	g_sigreciver = 0;

void	signal_keeper(int signb, siginfo_t *info, void *data)
{
	static int	i = 0;

	g_sigreciver = 1;
	if (signb == SIGUSR2)
		i++;
	else if (signb == SIGUSR1)
		printf("bytes recived : %d", (i / 8));
}

int	signal_check(int counter, int i)
{
	g_sigreciver = 0;
	counter = 20;
	while (g_sigreciver == 0 && counter > 0)
	{
		usleep(50);
		counter--;
	}
	if (g_sigreciver == 0)
	{
		printf("SENDING SIGNAL FAILD IN THIS BIT INDEX! ! ! ! %d", i);
		return (1);
	}
	return (0);
}

int	binary_trick(int pid, char c)
{
	int		i;
	int		counter;

	i = 7;
	while (i > 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
	signal_check(&counter, i);
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
