/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:19:45 by minabe            #+#    #+#             */
/*   Updated: 2022/06/10 15:02:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start < slen && len != 0)
		ft_memcpy(str, s + start, len);
	return (str);
}
