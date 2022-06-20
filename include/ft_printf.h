/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:09:28 by minabe            #+#    #+#             */
/*   Updated: 2022/06/21 08:34:33 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	get_digits(int	d);
int	put_c(char c);
int	put_s(char *s);
int	put_d(va_list *ap);
int	put_x(va_list *ap);


#endif
