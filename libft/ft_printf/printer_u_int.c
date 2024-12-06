/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_u_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:05:07 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 22:54:42 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prefix_u_int(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = print_blank_space_nbr(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}

int	print_u_int(unsigned int u_number, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	set_u_int_print_conf(flags, u_number);
	cnt_tmp = print_prefix_u_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_core_int(fd, flags, u_number);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_nbr_str(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
