/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:50:02 by minabe            #+#    #+#             */
/*   Updated: 2022/06/21 21:47:04 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	put_p(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += ft_putstr("0x");
	return (res + putnbr_hex(ptr));
}
