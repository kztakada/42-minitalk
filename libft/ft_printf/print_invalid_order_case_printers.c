/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_order_case_printers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:45:42 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 17:52:44 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	force_print_sharp_plus(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_sharp)
	{
		if (ft_putchar_fd('#', fd) < 0)
			return (-1);
		count++;
	}
	if (flags->is_plus)
	{
		if (ft_putchar_fd('+', fd) < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	force_print_space_minus_zero(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_space)
	{
		if (ft_putchar_fd(' ', fd) < 0)
			return (-1);
		count++;
	}
	if (flags->is_minus)
	{
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		count++;
	}
	if (flags->is_zero)
	{
		if (ft_putchar_fd('0', fd) < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	force_print_flags(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = force_print_sharp_plus(flags, fd);
	if (count < 0)
		return (-1);
	cnt_tmp = force_print_space_minus_zero(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}

int	force_print_number(int fd, int number)
{
	int	count;

	count = 0;
	if (number > 0)
	{
		count = ft_putnbr_fd(number, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	force_print_precision(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	if (ft_putchar_fd('.', fd) < 0)
		return (-1);
	count++;
	if (flags->precision > 0)
		cnt_tmp = force_print_number(fd, flags->precision);
	else
		cnt_tmp = ft_putchar_fd('0', fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
