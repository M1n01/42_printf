/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:42:37 by minabe            #+#    #+#             */
/*   Updated: 2022/06/10 14:26:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	to_find;

	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (n)
	{
		if (*str == to_find)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
