/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:43:09 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/03 16:47:28 by tndreka          ###   ########.fr       */
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

int	signal_check(int counter)
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
		printf("SENDING SIGNAL FAILD");
		return (1);
	}
	return (0);
}

void	binary_trick(int pid, char c)
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
	signal_check(counter);	
}

int	main(int ac, char **av)
{
	int					pid;
	char				*s;
	struct sigaction	sa;

	if (ac > 2)
	{
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

int	ft_atoi(char *s)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		++s;
	}
	return (res * sign);
}
