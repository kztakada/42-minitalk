/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:18:16 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 19:42:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_prefix_str(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_zero == 1 && flags->precision != -1)
	{
		if (ISLINUX == 0)
			count = print_zero_loop(flags->blank_size, fd);
		if (ISLINUX == 1)
			count = print_space_loop(flags->blank_size, fd);
	}
	else if (flags->is_minus == 0)
		count = print_space_loop(flags->blank_size, fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	print_core_str(const char *str, t_flags *flags, int fd)
{
	int		count;
	char	*output_str;

	count = 0;
	output_str = ft_substr(str, 0, flags->charactors);
	if (!output_str)
		return (-1);
	count = ft_putstr_fd(output_str, fd);
	free(output_str);
	if (count < 0)
		return (-1);
	return (count);
}

int	print_str(const char *str, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	if (!str)
		str = "(null)";
	set_str_print_conf(flags, str);
	count = print_prefix_str(flags, fd);
	if (count < 0)
		return (-1);
	cnt_tmp = print_core_str(str, flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_nbr_str(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
