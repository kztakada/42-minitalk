/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:40:44 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 13:35:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prefix_percent(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_zero == 1)
		count = print_zero_loop(flags->blank_size - 1, fd);
	else if (flags->is_minus == 0)
		count = print_space_loop(flags->blank_size - 1, fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	print_sufix_percent(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_minus == 1)
	{
		count = print_space_loop(flags->blank_size - 1, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_core_percent(int fd)
{
	int	count;

	count = 0;
	if (ft_putchar_fd('%', fd) < 0)
		return (-1);
	count++;
	return (count);
}

int	print_percent(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	flags->charactors = 1;
	set_char_print_conf(flags);
	count = print_prefix_percent(flags, fd);
	if (count < 0)
		return (-1);
	cnt_tmp = print_core_percent(fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_sufix_percent(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
