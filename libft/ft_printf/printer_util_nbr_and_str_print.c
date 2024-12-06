/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_util_nbr_and_str_print.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:50:41 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 20:51:21 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_suffix_nbr_str(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_minus == 1)
	{
		count = print_space_loop(flags->blank_size, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}
