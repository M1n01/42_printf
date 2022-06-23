/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:09:28 by minabe            #+#    #+#             */
/*   Updated: 2022/06/23 15:32:12 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	putnbr_hex(unsigned long long nbr, char conv);
int	put_c(char c);
int	put_s(char *s);
int	put_p(unsigned long long ptr);
int	put_d(int d);
int	put_u(unsigned int ud);
int	put_x(unsigned int d, char conv);

#endif
