/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:00 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 19:37:02 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_by_format_type(int fd, t_flags *flags, va_list *args)
{
	if (flags->type == 'c')
		return (print_char(va_arg(*args, int), flags, fd));
	if (flags->type == 's')
		return (print_str(va_arg(*args, const char *), flags, fd));
	if (flags->type == 'd' || flags->type == 'i')
		return (print_int(va_arg(*args, int), flags, fd));
	if (flags->type == 'x')
		return (print_hex_base(va_arg(*args, unsigned int), flags, HEX_LOWER,
				fd));
	if (flags->type == 'X')
		return (print_hex_base(va_arg(*args, unsigned int), flags, HEX_UPPER,
				fd));
	if (flags->type == 'p')
		return (print_ptr((unsigned long long)va_arg(*args, void *), flags,
				fd));
	if (flags->type == 'u')
		return (print_u_int(va_arg(*args, unsigned int), flags, fd));
	if (flags->type == '%')
		return (print_percent(flags, fd));
	return (0);
}

int	set_format_type_and_flags(const char **format, t_flags *flags,
		va_list *args)
{
	set_format_type(format, flags);
	if (ISLINUX == 1 && is_invalid_order_case(format, flags->type))
		return (-3);
	if (flags->type == 's' || is_number_type(flags->type) || flags->type == 'p')
		if (is_format_flag_after_dot(format, flags->type))
			flags->precision = -3;
	set_format_flags_loop(format, flags, args);
	return (0);
}

int	print_format(const char **format, t_flags *flags, va_list *args, int fd)
{
	int	count;
	int	is_not_format;
	int	error_no;

	(*format)++;
	is_not_format = (!(is_format_type(**format) || is_format_flag(**format)
				|| is_field_digit(**format) || is_precision_dot(**format)));
	if (is_not_format)
		return (print_invalid_char_start_case(format, fd));
	error_no = set_format_type_and_flags(format, flags, args);
	if (error_no == -3)
		return (print_invalid_order_case(format, flags, args, fd));
	if (flags->blank_size == -1000 || flags->precision == -1000)
		return (print_over_flow_case());
	count = print_by_format_type(fd, flags, args);
	if (count < 0)
		return (-1);
	return (count);
}
