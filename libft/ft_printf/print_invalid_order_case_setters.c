/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_order_case_setters.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:42:32 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 17:42:33 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	force_set_format_flags(const char **format, t_flags *flags)
{
	while (is_format_flag(**format))
	{
		if (**format == '-')
			flags->is_minus = 1;
		if (**format == '0')
			flags->is_zero = 1;
		if (**format == '#')
			flags->is_sharp = 1;
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

void	force_set_field_size(const char **format, t_flags *flags, va_list *args)
{
	if (ft_isdigit(**format))
	{
		flags->blank_size = ascii_to_field_size(&**format);
		while (ft_isdigit(**format))
			(*format)++;
		return ;
	}
	if (**format == '*')
	{
		flags->blank_size = va_arg(*args, int);
		(*format)++;
	}
}

int	force_set_precision(const char **format, t_flags *flags, va_list *args)
{
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			flags->precision = ascii_to_field_size(&**format);
			while (ft_isdigit(**format))
				(*format)++;
			return (1);
		}
		if (**format == '*')
		{
			flags->precision = va_arg(*args, int);
			(*format)++;
		}
		return (1);
	}
	return (0);
}
