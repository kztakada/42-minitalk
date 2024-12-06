/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:51:43 by katakada          #+#    #+#             */
/*   Updated: 2024/10/11 01:57:52 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_blank_size_hex(t_flags *flags, unsigned int output_hex)
{
	int	precision;

	if (flags->precision == -3 && output_hex == 0)
	{
		flags->blank_size = flags->blank_size - flags->is_sharp;
		return ;
	}
	if (flags->precision > 0)
		precision = flags->precision;
	else
		precision = 0;
	if (precision <= flags->charactors)
		flags->blank_size = flags->blank_size - flags->charactors
			- flags->is_sharp;
	else
		flags->blank_size = flags->blank_size - precision - flags->is_sharp;
	if (flags->blank_size <= 0)
		flags->blank_size = 0;
}

void	set_hex_print_conf(t_flags *flags, unsigned int output_hex, char *base)
{
	int	is_not_precision;
	int	is_zero_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2
			|| flags->precision == -3);
	is_zero_precision = flags->precision == -2;
	if (output_hex == 0)
		flags->is_sharp = 0;
	set_print_conf_counted_digits(flags, (unsigned long long)output_hex, base);
	if (!(output_hex == 0 && is_zero_precision))
		set_blank_size_hex(flags, output_hex);
	if (!(is_not_precision))
		set_print_conf_precision(flags);
}
