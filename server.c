/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:52:59 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/03 17:55:50 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }
void	signal_converter(int signb, char *c)
{
	if (signb == SIGUSR1)
		*c = *c << 1 | 1;
	else if (signb == SIGUSR2)
		*c = *c << 1;
}

void	char_trick(int signb, siginfo_t *info, void *data)
{
	static int	i = 0;
	static int	pid = 0;
	static char	c = 0;

	(void)data;
	(void)info;
	// printf("Signal %d received from PID %d\n", signb, info->si_pid);
	if (pid == 0)
		pid = info->si_pid;
	signal_converter(signb, &c);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			kill(pid, SIGUSR1);
			pid = 0;
		}
		else
		{
			ft_putchar_fd(c, STDOUT_FILENO);
			c = 0;
		}
	}
	kill(pid, SIGUSR2);
}

int main(void)
{
	struct sigaction	sa;

	printf("SERVER IS STARTING\n");
	printf("MY Server PID : %d\n", getpid());
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

