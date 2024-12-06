/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:21:01 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 23:29:30 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign_int(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->sign == -1)
		count = ft_putchar_fd('-', fd);
	else if (flags->is_plus == 1)
		count = ft_putchar_fd('+', fd);
	else if (flags->is_space == 1)
		count = ft_putchar_fd(' ', fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	print_prefix_int(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = print_blank_space_nbr(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_sign_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}

int	print_int(int n, t_flags *flags, int fd)
{
	int		count;
	int		cnt_tmp;
	long	output_nbr;

	count = 0;
	output_nbr = (long)n;
	set_int_print_conf(flags, &output_nbr);
	cnt_tmp = print_prefix_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_core_int(fd, flags, output_nbr);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_nbr_str(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
