/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:48:31 by minabe            #+#    #+#             */
/*   Updated: 2022/06/21 08:40:44 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	put_n(int d, int padding);

int	put_d(va_list ap)
{
	int	d;
	int	len;
	int	res;

	d = va_arg(ap, int);
	len = get_digits(d);
	res = 0;
	while ((width - putlen) > 0)
	{
		res += ft_putchar(' ');
		width--;
	}
	return (res + put_n(d, padding));
}

static int	put_n(int d, int padding)
{
	int	res;

	res = 0;
	if (d == INT_MIN)
	{
		res += ft_putchar('-');
		while (padding-- > 0)
			res += ft_putchar('0');
		res += ft_putstr("2147483648");
		return (res);
	}
	if (d < 0)
	{
		res += ft_putchar('-');
		d *= -1;
	}
	while (padding-- > 0)
		res += ft_putchar('0');
	if (d / 10)
		res += put_n(d / 10, padding);
	res += ft_putchar((d % 10) + '0');
	return (res);
}