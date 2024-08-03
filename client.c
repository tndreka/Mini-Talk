/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:43:09 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/03 23:36:33 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// this global variable is used as a flag to notyfy for each signal 
//that the function receves
static int	g_sigreciver = 0;

void	signal_keeper(int signb, siginfo_t *info, void *data)
{
	static int	i = 0;

	(void)data;
	(void)info;
	g_sigreciver = 1;
	if (signb == SIGUSR2)
		i++;
	else if (signb == SIGUSR1)
		ft_printf("bytes recived : %d", (i / 8));
}

int	signal_check(int counter)
{
	g_sigreciver = 0;
	while (g_sigreciver == 0 && counter > 0)
	{
		usleep(10);
		counter--;
	}
	return (0);
}

void	binary_trick(int pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (signal_check(20) != 0)
			return ;
		i--;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	char				*s;
	struct sigaction	sa;

	if (ac == 3)
	{
		sa.sa_sigaction = signal_keeper;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pid = ft_atoi(av[1]);
		s = av[2];
		while (*s)
			binary_trick(pid, *s++);
		binary_trick(pid, '\0');
	}
	else
		write(1, "ERROR", 5);
	return (EXIT_SUCCESS);
}
