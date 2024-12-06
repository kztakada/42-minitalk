/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_func_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:17:10 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 20:09:27 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define NIL "(nil)"
#else
# define NIL "0"
#endif

int	ft_putnbr_ptr_base(unsigned long long n, char *base, int fd)
{
	int	count;

	if (n == 0)
	{
		count = ft_putstr_fd(NIL, fd);
		if (count < 0)
			return (-1);
		return (count);
	}
	count = ft_putnbr_hex_base(n, base, fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putnbr_hex_base(unsigned long long n, char *base, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	if (n >= 16)
	{
		cnt_tmp = ft_putnbr_hex_base(n / 16, base, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
		cnt_tmp = ft_putchar_fd(base[n % 16], fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	else
	{
		cnt_tmp = ft_putchar_fd(base[n], fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}
