/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:57:58 by minabe            #+#    #+#             */
/*   Updated: 2022/06/07 01:10:36 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*to;
	const unsigned char	*from;

	if (dst == NULL && src == NULL)
		return (NULL);
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	i = 0;
	if (from < to)
	{
		while (i < len)
		{
			to[len - 1 - i] = from[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			*(to++) = *(from++);
	}
	return (dst);
}
