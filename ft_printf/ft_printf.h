/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:13:26 by tndreka           #+#    #+#             */
/*   Updated: 2024/05/04 00:43:58 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** INCLUDE LYBRARIES
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef LONG_MAX
#  define LONG_MAX 	9223372036854775807
# endif

# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775807LL 
# endif

# ifndef ULONG_MAX
#  define ULONG_MAX 18446744073709551615ULL
# endif

int		ft_printf(const char *buffer, ...);
int		ft_format_printer(char format, va_list ap);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_digit(unsigned long n, unsigned long base, char *numb);
int		ft_print_pointer(unsigned long n, int base, char *numb);
int		ft_print_dec_int(long n);
int		*get_flag(void);
void	set_flag(int flag);

#endif