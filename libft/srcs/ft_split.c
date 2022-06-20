/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:52:54 by minabe            #+#    #+#             */
/*   Updated: 2022/06/07 12:38:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static void		sep_words(char **split, char *s, char c);
static char		**malloc_error(char **str);
static void		write_word(char *from, char *dest, char c);

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**res;

	words = count_words(s, c);
	res = malloc(sizeof(char *) * words + 1);
	if (!res)
		return (NULL);
	res[words] = NULL;
	sep_words(res, (char *)s, c);
	return (res);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i] != '\0') && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	sep_words(char **split, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			split[word] = malloc(sizeof(char) * (j + 1));
			if (!split[word])
				malloc_error(split);
			write_word(split[word], s + i, c);
			i += j;
			word++;
		}
	}
	return ;
}

static char	**malloc_error(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	write_word(char *dest, char *from, char c)
{
	size_t	i;

	i = 0;
	while (from[i] != c && from[i] != '\0')
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}
