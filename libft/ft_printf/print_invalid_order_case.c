/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_order_case.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:29:29 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 18:14:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	force_print_format(int is_precision, t_flags *flags, int fd, int count)
{
	int	cnt_tmp;

	cnt_tmp = force_print_flags(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = force_print_number(fd, flags->blank_size);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	if (is_precision)
	{
		cnt_tmp = force_print_precision(flags, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	force_print_until_last_char(const char **format, t_flags *flags, int fd,
		int count)
{
	int	cnt_tmp;

	cnt_tmp = 0;
	while (**format != '\0' && **format != '%')
	{
		if (ft_putchar_fd(**format, fd) < 0)
			return (-1);
		(*format)++;
		cnt_tmp++;
	}
	if (**format == '%')
		flags->type = 0;
	(*format)--;
	return (count + cnt_tmp);
}

int	print_invalid_order_case(const char **format, t_flags *flags, va_list *args,
		int fd)
{
	int	count;
	int	is_percent_start;
	int	is_precision;

	count = 0;
	is_percent_start = (*(*format - 1) == '%');
	force_set_format_flags(format, flags);
	force_set_field_size(format, flags, args);
	is_precision = force_set_precision(format, flags, args);
	if (flags->blank_size == -1000 || flags->precision == -1000)
		return (print_over_flow_case());
	if (is_percent_start)
	{
		if (ft_putchar_fd('%', fd) < 0)
			return (-1);
		count++;
	}
	count = force_print_format(is_precision, flags, fd, count);
	if (count < 0)
		return (-1);
	count = force_print_until_last_char(format, flags, fd, count);
	if (count < 0)
		return (-1);
	return (count);
}
