/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:52:16 by katakada          #+#    #+#             */
/*   Updated: 2024/10/06 18:18:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resolve_sign(t_flags *flags, long *output_nbr)
{
	flags->sign = 0;
	if (*output_nbr < 0)
		flags->is_plus = 0;
	if (*output_nbr < 0)
		flags->sign = -1;
	if (flags->sign == 1 || flags->is_plus == 1)
		flags->sign = 1;
	if (*output_nbr < 0)
		*output_nbr = get_abs(*output_nbr);
}

void	set_int_print_conf(t_flags *flags, long *output_nbr)
{
	int	is_not_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2);
	if (*output_nbr == 0 && is_not_precision)
		flags->is_zero = 0;
	resolve_sign(flags, output_nbr);
	if (!(*output_nbr == 0 && is_not_precision))
		set_print_conf_nbr_digits(flags, *output_nbr, DEC);
	set_print_conf_blank_size_int(flags, *output_nbr);
	set_print_conf_precision_int(flags);
}
