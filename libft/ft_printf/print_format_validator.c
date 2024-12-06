/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_validator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:29:07 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 19:08:13 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_format_flag_after_dot(const char **format, char valid_type)
{
	const char	*format_pos;
	int			check_result;

	format_pos = *format;
	check_result = 0;
	while (*format_pos != valid_type)
	{
		if (*format_pos == '.')
			if (is_not_zero_format_flag(*(format_pos + 1)))
				check_result = 1;
		format_pos++;
	}
	return (check_result);
}
