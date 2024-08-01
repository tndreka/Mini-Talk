/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:39:04 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/01 21:23:42 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* CLIENT PROTOTYPE 
// void	send_info_per_bit(int pid, char *s)
// {
// 	int		i;
// 	int		len;
// 	int		j;

// 	i = 0;
// 	len = ft_strlen(s);
// 	while (i <= len)
// 	{
// 		j = 1;
// 		while (j < 8)
// 		{
// 			if ((s[i] >> j) & 1)
// 			{
// 				if (!(kill(pid, SIGUSR1)))
// 				{
// 					perror("FAILING IN SENDING SIGNAL");
// 					break ;
// 				}
// 			}
// 			else
// 			{
// 				if (!(kill(pid, SIGUSR2)))
// 				{
// 					perror("FAILING IN SENDING SIGNAL");
// 					break ;
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
*/

/*SERVER PROTOTYPE 
// void	get_sig(int b)
// {
// 	int	i;
// 	int sig;
	
// 	i = 7;
// 	while (i >= 0)
// 	{
// 		if(sig == SIGUSR1)
// 		{
// 			printf("SIG1");
// 			printf("%d", (b >> i) & 1);
// 		}
// 		if(sig == SIGUSR1)
// 		{
// 			printf("SIG3");
// 			printf("%d", (b >> i) & 1);
// 		}
// 		else
// 			printf("SIGNAL ERROR");
// 		i--;
// 	}
// 	printf(" ");
// }
// #include <stdio.h>

// int	main(void)
// {
// 	//printf("this is my proccess id : %d\n", getpid());
// 	// if (signal(SIGUSR1, get_sig) == SIG_ERR)
	
// 	// 	exit(1);
// 	// if (signal(SIGUSR2, get_sig) == SIG_ERR)
// 	// 	exit(1);
	
// 	//return (0);
// 	printf("My Server PID is: %d\n", getpid());
// 	while (1)
// 	{
// 		signal(SIGUSR2, get_sig);
// 		signal(SIGUSR1, get_sig);
// 		pause();
// 	}
// 	return (0);
// }

*/