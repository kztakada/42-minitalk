/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_validator_order.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:26:08 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 19:06:47 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_no_number_after_format_flags(const char **format, char valid_type)
{
	while ((**format) && is_format_flag(**format))
		(*format)++;
	if (is_field_digit(**format) || **format == '.' || **format == '*'
		|| **format == valid_type)
		return (0);
	return (1);
}

int	has_no_dot_after_digit(const char **format, char valid_type)
{
	while ((**format) && is_field_digit(**format))
		(*format)++;
	if (**format == '.' || **format == valid_type)
		return (0);
	return (1);
}

int	has_no_dot_after_star(const char **format, char valid_type)
{
	(*format)++;
	if (**format == '.' || **format == valid_type)
		return (0);
	return (1);
}

int	has_no_number_after_dot(const char **format, char valid_type)
{
	(*format)++;
	if (is_field_digit(**format) || **format == '*' || **format == valid_type)
	{
		if (**format == '*')
		{
			(*format)++;
			return (0);
		}
		while ((**format) && is_field_digit(**format))
			(*format)++;
		return (0);
	}
	return (1);
}

int	is_invalid_order_case(const char **format, char valid_type)
{
	const char	*format_pos;
	int			check_result;

	check_result = 0;
	format_pos = *format;
	if (is_format_flag(*format_pos))
		check_result = has_no_number_after_format_flags(&format_pos,
				valid_type);
	if (ft_isdigit(*format_pos))
		check_result = has_no_dot_after_digit(&format_pos, valid_type);
	else if (*format_pos == '*')
		check_result = has_no_dot_after_star(&format_pos, valid_type);
	if (*format_pos == '.')
		check_result = has_no_number_after_dot(&format_pos, valid_type);
	if (*format_pos == valid_type && check_result == 0)
		return (0);
	return (1);
}
