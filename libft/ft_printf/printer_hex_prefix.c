/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_hex_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:32:57 by katakada          #+#    #+#             */
/*   Updated: 2024/10/06 11:58:11 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sharp_hex(t_flags *flags, int fd, char *base)
{
	int	count;

	count = 0;
	if (flags->is_sharp)
	{
		if (base[15] == 'F')
			count = ft_putstr_fd(HEX_SIGN_UPPER, fd);
		else
			count = ft_putstr_fd(HEX_SIGN_LOWER, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_prefix_hex(t_flags *flags, int fd, char *base)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = print_blank_space_nbr(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_sharp_hex(flags, fd, base);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero_hex(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
