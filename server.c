/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:52:59 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/03 23:51:52 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//This is the global variable  to track the PID of the sending process
static int	g_pid = 0;

void	send_signal(siginfo_t *info, char *c, int *i)
{
	if ((*i) == 8)
	{
		(*i) = 0;
		if ((*c) == '\0')
		{
			g_pid = 0;
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			write(1, c, 1);
		}
		(*c) = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

void	char_trick(int signb, siginfo_t *info, void *data)
{
	static int	i = 0;
	static char	c = 0;

	(void)data;
	if (g_pid == 0)
		g_pid = info->si_pid;
	if (info->si_pid != g_pid)
		return ;
	if (signb == SIGUSR1)
		c = (c << 1) | 1;
	else if (signb == SIGUSR2)
		c = (c << 1);
	i++;
	send_signal(info, &c, &i);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("SERVER IS STARTING\n");
	ft_printf("MY Server PID : %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = char_trick;
	if (sigaction(SIGUSR1, &sa, NULL))
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL))
		return (EXIT_FAILURE);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
