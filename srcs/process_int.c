/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:48:31 by minabe            #+#    #+#             */
/*   Updated: 2022/06/23 14:33:49 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	put_d(int d)
{
	int	res;

	res = 0;
	return (res + ft_putnbr(d));
}

int	put_u(unsigned int ud)
{
	int	res;

	res = 0;
	if (ud < 10)
	{
		res += ft_putchar(ud + '0');
		return (res);
	}
	res += ft_putnbr(ud / 10);
	res += ft_putchar(ud % 10 + '0');
	return (res);
}
