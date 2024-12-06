/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:02:38 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 13:35:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_prefix_char(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_minus == 0)
	{
		if (flags->is_zero)
		{
			if (ISLINUX == 1)
				count = print_space_loop(flags->blank_size - 1, fd);
			if (ISLINUX == 0)
				count = print_zero_loop(flags->blank_size - 1, fd);
		}
		else
			count = print_space_loop(flags->blank_size - 1, fd);
	}
	if (count < 0)
		return (-1);
	return (count);
}

int	print_suffix_char(t_flags *flags, int fd)
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

int	print_core_char(int c, int fd)
{
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	return (1);
}

int	print_char(int c, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	flags->charactors = 1;
	set_char_print_conf(flags);
	cnt_tmp = print_prefix_char(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_core_char(c, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_char(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
