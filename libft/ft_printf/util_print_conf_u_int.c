/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_u_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:11:18 by katakada          #+#    #+#             */
/*   Updated: 2024/10/07 15:16:58 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_u_int_print_conf(t_flags *flags, unsigned int output_nbr)
{
	int	is_not_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2);
	if (output_nbr == 0 && is_not_precision)
		flags->is_zero = 0;
	else
		set_print_conf_nbr_digits(flags, (long)output_nbr, DEC);
	set_print_conf_blank_size_int(flags, (long)output_nbr);
	if (!(is_not_precision))
		set_print_conf_precision_int(flags);
}
