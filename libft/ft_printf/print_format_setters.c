/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_setters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:16:31 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 19:07:25 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_format_type(const char **format, t_flags *flags)
{
	const char	*format_pos;

	format_pos = *format;
	while (*format_pos)
	{
		if (is_format_type(*format_pos))
		{
			if (*format_pos)
				flags->type = *format_pos;
			break ;
		}
		format_pos++;
	}
}

void	set_format_flags(const char **format, t_flags *flags)
{
	while (is_format_flag(**format))
	{
		if (**format == '-')
			flags->is_minus = 1;
		if (**format == '0' && (*(*format + 1) != '.'))
			flags->is_zero = 1;
		if (**format == '0' && (flags->type == 'c' || flags->type == '%'
				|| flags->type == 's'))
			flags->is_zero = 1;
		if (**format == '#')
			flags->is_sharp = 2;
		if (**format == ' ')
			flags->is_space = 1;
		if (**format == '+')
			flags->is_plus = 1;
		(*format)++;
	}
	if (flags->is_minus)
		flags->is_zero = 0;
	if (flags->is_plus)
		flags->is_space = 0;
}

void	set_format_field_size(const char **format, t_flags *flags,
		va_list *args)
{
	if (**format == '*')
	{
		flags->blank_size = va_arg(*args, int);
		(*format)++;
	}
	else
	{
		flags->blank_size = ascii_to_field_size(&**format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	set_format_precision(const char **format, t_flags *flags, va_list *args)
{
	(*format)++;
	if (is_number_type(flags->type))
		flags->is_zero = 0;
	if (flags->precision == -3)
	{
		while (ft_isdigit(**format) || **format == '*')
			(*format)++;
		return ;
	}
	flags->precision = 0;
	while ((**format) == '.')
		(*format)++;
	if (!(can_use_precision_number(format, flags)))
		return ;
	set_precision_number(format, flags, args);
	if (!(flags->type == 'c' || flags->type == '%' || flags->type == 's'))
		flags->is_zero = 0;
	while (ft_isdigit(**format))
		(*format)++;
	if (flags->precision == 0)
		flags->precision = -2;
	if (is_number_type(**format))
		flags->is_zero = 0;
}

void	set_format_flags_loop(const char **format, t_flags *flags,
		va_list *args)
{
	int	is_search_end;

	is_search_end = 0;
	while (**format && !is_search_end)
	{
		if (is_format_flag(**format))
			set_format_flags(format, flags);
		if (is_field_digit(**format))
			set_format_field_size(format, flags, args);
		if (is_precision_dot(**format))
			set_format_precision(format, flags, args);
		if (is_format_type(**format))
			is_search_end = 1;
		if (**format && !(is_format_flag(**format) || is_field_digit(**format)
				|| is_precision_dot(**format) || is_format_type(**format))
			&& !(flags->precision == -1))
		{
			flags->precision = -1;
			(*format)--;
			break ;
		}
		if (flags->precision == -1)
			is_search_end = 1;
	}
}
