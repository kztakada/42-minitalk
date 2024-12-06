/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:51:50 by katakada          #+#    #+#             */
/*   Updated: 2024/10/17 17:44:12 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	long	number;
	int		count;
	int		cnt_tmp;

	number = n;
	count = 0;
	if (number < 0)
	{
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		count++;
		number *= -1;
	}
	if (number >= 10)
	{
		cnt_tmp = ft_putnbr_fd((number / 10), fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	if (ft_putchar_fd((number % 10 + '0'), fd) < 0)
		return (-1);
	count++;
	return (count);
}
