/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:39:04 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/29 22:46:52 by tndreka          ###   ########.fr       */
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
