/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:34:15 by minabe            #+#    #+#             */
/*   Updated: 2022/06/07 18:21:48 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set);
static size_t	get_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (set == NULL)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end <= start)
		return ("\0");
	str = ft_calloc(end - start + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	ssize_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = len - 1;
	while (i >= 0)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i--;
	}
	return (i + 1);
}
