/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_util_loop_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:31:21 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 20:31:22 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_loop(int loop_times, int fd, int c)
{
	int	count;

	count = 0;
	while (loop_times-- > 0)
	{
		if (ft_putchar_fd(c, fd) < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	print_zero_loop(int loop_times, int fd)
{
	return (print_loop(loop_times, fd, '0'));
}

int	print_space_loop(int loop_times, int fd)
{
	return (print_loop(loop_times, fd, ' '));
}
