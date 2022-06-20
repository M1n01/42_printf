/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:08:27 by minabe            #+#    #+#             */
/*   Updated: 2022/06/21 08:49:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	get_digits(int	d)
{
	int	digits;

	if (d == -2147483648)
		return (11);
	digits = 0;
	if (d < 0)
	{
		digits++;
		d *= -1;
	}
	while (d / 10)
	{
		digits++;
		d /= 10;
	}
	return (digits);
}

static int	put_conv(char *iter, va_list *ap)
{
	if (*iter == 'c')
		return (put_c(va_arg(*ap, int)));
	else if (*iter == 's')
		return (put_s(va_arg(*ap, char *)));
	// else if (*iter == 'p')
	// 	return (put_p(*ap));
	// else if (*iter == 'd')
	// 	return (put_d(*ap));
	// else if (*iter == 'i')
	// 	return (put_i(*ap));
	// else if (*iter == 'u')
	// 	return (put_u(*ap));
	// else if (*iter == 'x')
	// 	return (put_x(*ap));
	// else if (*iter == 'X')
	// 	return (put_X(*ap));
	// else if (*iter == '%')
	// 	return (put_per(*ap));
	return (0);
}

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		res;
	char 	*iter;
	va_list	ap;

	iter = (char *)format;
	if (!iter)
		return (0);
	res = 0;
	va_start(ap, format);
	while (*iter != '\0')
	{
		if (*iter == '%')
		{
			iter++;
			res += put_conv(iter, &ap);
			iter++;
			continue ;
		}
		res += ft_putchar(*iter);
		iter++;
	}
	va_end(ap);
	return (res);
}

int	main()
{
	printf("---------------c----------------\n");
	printf("printf:\t\t  %c %c %c \n", '1', '2', '3');
	ft_printf("ft_printf:\t  %c %c %c \n", '1', '2', '3');
	printf("printf:\t\t %c %c %c \n", '0', 0, '1');
	ft_printf("ft_printf:\t %c %c %c \n", '0', 0, '1');
	printf("printf:\t\t %c %c %c \n", 0, '1', '2');
	ft_printf("ft_printf:\t %c %c %c \n", 0, '1', '2');
	printf("---------------s----------------\n");
	printf("printf:\t\t%s\n", "111");
	printf("ft_printf:\t%s\n", "111");
	return 0;
}