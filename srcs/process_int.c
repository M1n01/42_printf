/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:48:31 by minabe            #+#    #+#             */
/*   Updated: 2022/06/21 22:13:48 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_putuint(unsigned int n);

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
	return (res + ft_putuint(ud));
}

static int	ft_putuint(unsigned int n)
{
	int	res;

	res = 0;
	if (n < 10)
	{
		res += ft_putchar(n + '0');
		return (res);
	}
	res += ft_putnbr(n / 10);
	res += ft_putchar(n % 10 + '0');
	return (res);
}