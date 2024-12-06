/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_int_func.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:17:26 by katakada          #+#    #+#             */
/*   Updated: 2024/10/11 16:47:56 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	get_abs(long n)
{
	if (n < 0)
		return ((n * -1));
	return (n);
}

void	set_print_conf_nbr_digits(t_flags *flags, long output_nbr, char *base)
{
	int	nbr_of_base;

	nbr_of_base = ft_strlen(base);
	if (output_nbr >= nbr_of_base)
	{
		set_print_conf_nbr_digits(flags, output_nbr / nbr_of_base, base);
		set_print_conf_nbr_digits(flags, output_nbr % nbr_of_base, base);
	}
	else
		flags->charactors++;
}

void	set_print_conf_blank_size_int(t_flags *flags, long output_nbr)
{
	int	precision;
	int	is_not_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2
			|| (flags->type == 'u' && flags->precision == -3));
	if (output_nbr == 0 && is_not_precision)
		return ;
	if (flags->precision > 0)
		precision = flags->precision;
	else
		precision = 0;
	if (precision <= flags->charactors)
		flags->blank_size = flags->blank_size - flags->charactors
			- get_abs(flags->sign);
	else
		flags->blank_size = flags->blank_size - precision
			- get_abs(flags->sign);
	if (flags->blank_size <= 0)
		flags->blank_size = 0;
}

void	set_print_conf_precision_int(t_flags *flags)
{
	int	is_not_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2
			|| flags->precision == -3);
	if (is_not_precision)
		return ;
	if (flags->precision > flags->charactors)
		flags->precision = flags->precision - flags->charactors;
	else
		flags->precision = 0;
}
