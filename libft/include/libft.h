/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:49 by minabe            #+#    #+#             */
/*   Updated: 2022/06/23 15:28:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <limits.h>

int		ft_isspace(char c);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long n);
size_t	ft_strlen(const char *str);

#endif
