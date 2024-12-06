/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:41:28 by katakada          #+#    #+#             */
/*   Updated: 2024/10/12 19:57:21 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	ascii_to_field_size(const char *str_pos)
{
	unsigned long	int_value;
	int				digit_value;
	unsigned long	max_limit;

	int_value = 0;
	max_limit = (unsigned long)INT_MAX;
	while (ft_isdigit(*str_pos))
	{
		digit_value = *str_pos - '0';
		if (int_value > ((max_limit - digit_value) / 10))
			return (-1000);
		int_value = int_value * 10 + digit_value;
		str_pos++;
	}
	return ((int)int_value);
}

void	set_precision_number(const char **format, t_flags *flags, va_list *args)
{
	if (**format == '*')
	{
		flags->precision = va_arg(*args, int);
		(*format)++;
	}
	else
	{
		if (ISLINUX == 1)
			flags->precision = ascii_to_field_size(&**format);
		else
			flags->precision = ft_atoi(&**format);
	}
}

int	can_use_precision_number(const char **format, t_flags *flags)
{
	if (is_not_zero_format_flag(**format))
		return (0);
	if (flags->precision == -1)
		return (0);
	if (!((**format == '*') || ft_isdigit(**format)))
	{
		flags->precision = -1;
		return (0);
	}
	return (1);
}
