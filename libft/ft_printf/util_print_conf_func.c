/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_func.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:12:33 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 23:40:18 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_print_conf_precision(t_flags *flags)
{
	if (flags->precision > flags->charactors)
		flags->precision = flags->precision - flags->charactors;
	else
		flags->precision = 0;
}

void	set_print_conf_counted_digits(t_flags *flags, unsigned long long number,
		char *base)
{
	unsigned long long	base_size;

	base_size = ft_strlen(base);
	if (number >= base_size)
	{
		set_print_conf_counted_digits(flags, number / base_size, base);
		set_print_conf_counted_digits(flags, number % base_size, base);
	}
	else
		flags->charactors++;
}
