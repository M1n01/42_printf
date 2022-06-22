/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:08:27 by minabe            #+#    #+#             */
/*   Updated: 2022/06/21 21:57:42 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	putnbr_hex(unsigned long long nbr)
{
	int	res;

	res = 0;
	if (nbr / 16 != 0)
		res += putnbr_hex(nbr / 16);
	if ((nbr % 16) >= 10)
		res += ft_putchar((nbr % 16) - 10 + 'a');
	else
		res += ft_putchar((nbr % 16) + '0');
	return (res);
}

static int	put_conv(char *iter, va_list *ap)
{
	if (*iter == 'c')
		return (put_c(va_arg(*ap, int)));
	else if (*iter == 's')
		return (put_s(va_arg(*ap, char *)));
	else if (*iter == 'p')
		return (put_p((unsigned long long)va_arg(*ap, void *)));
	else if (*iter == 'd' || *iter == 'i')
		return (put_d(va_arg(*ap, int)));
	else if (*iter == 'u')
		return (put_u((unsigned long long)va_arg(*ap, unsigned long long)));
	else if (*iter == 'x')
		return (put_x(va_arg(*ap, unsigned int)));
	else if (*iter == 'X')
		return (put_x(va_arg(*ap, unsigned int)));
	// else if (*iter == '%')
	// 	return (ft_putchar(*iter));
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
	// printf("---------------c----------------\n");
	// printf("printf:\t\t  %c %c %c \n", '1', '2', '3');
	// ft_printf("ft_printf:\t  %c %c %c \n", '1', '2', '3');
	// printf("---------------s----------------\n");
	// printf("printf:\t\t%s\n", "111");
	// ft_printf("ft_printf:\t%s\n", "111");
	// printf("---------------p----------------\n");
	// char *str = "Hello";
	// int	x = 100;
	// int	d;
	// int	e;
	// d = printf("printf:\t\t%p %p\n", str, &x);
	// e = ft_printf("ft_printf:\t%p %p\n", str, &x);
	// printf("%d %d\n", d, e);
	// printf("printf:\t\t %p \n", 15);
	// ft_printf("ft_printf:\t %p \n", 15);
	printf("---------------x----------------\n");
	printf(" %x ", -1);
	return 0;
}