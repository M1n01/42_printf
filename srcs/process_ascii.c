/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:28 by minabe            #+#    #+#             */
/*   Updated: 2022/06/21 08:47:51 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	put_c(char c)
{
	int	res;

	res = ft_putchar(c);
	return (res);
}

int	put_s(char *s)
{
	size_t	i;
	int		res;

	if (!s)
		return (put_s("(null)"));
	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		res += ft_putchar(s[i]);
		i++;
	}
	return (res);
}
