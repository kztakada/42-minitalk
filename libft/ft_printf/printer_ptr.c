/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:33:23 by katakada          #+#    #+#             */
/*   Updated: 2024/10/11 16:30:38 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_0x_ptr(unsigned long long ptr, int fd)
{
	int	count;

	count = 0;
	if (ptr || ISLINUX == 0)
	{
		count += ft_putstr_fd("0x", fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_prefix_ptr(unsigned long long ptr, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = print_blank_space_nbr(flags, fd);
	if (count < 0)
		return (-1);
	cnt_tmp = print_0x_ptr(ptr, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero_hex(flags, fd);
	if (count < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}

int	print_core_ptr(unsigned long long ptr, t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (!(!ptr && flags->precision == -3))
	{
		count = ft_putnbr_ptr_base((unsigned long long)ptr, HEX_LOWER, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_ptr(unsigned long long ptr, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	set_ptr_print_conf(flags, (unsigned long long)ptr);
	count = print_prefix_ptr(ptr, flags, fd);
	if (count < 0)
		return (-1);
	cnt_tmp = print_core_ptr(ptr, flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_nbr_str(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
