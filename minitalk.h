/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 03:45:16 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/03 17:49:21 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//LYbraries
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(char *s);
int		ft_strlen(char *s);
void	ft_putchar_fd(char c, int fd);

#endif