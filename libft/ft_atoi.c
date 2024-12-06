/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:08:39 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 15:24:34 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ascii_to_int(const char *str_pos, int sign)
{
	unsigned long	int_value;
	int				digit_value;
	unsigned long	max_limit;

	int_value = 0;
	max_limit = (unsigned long)LONG_MAX;
	while (ft_isdigit(*str_pos))
	{
		digit_value = *str_pos - '0';
		if (sign == 1 && int_value > ((max_limit - digit_value) / 10))
			return (LONG_MAX);
		if (sign == -1 && int_value > ((max_limit + 1 - digit_value) / 10))
			return (LONG_MIN);
		int_value = int_value * 10 + digit_value;
		str_pos++;
	}
	return (int_value);
}

int	ft_atoi(const char *str_src)
{
	int			sign;
	long		abs_value;
	const char	*str_pos;

	sign = 1;
	abs_value = 0;
	str_pos = str_src;
	while (*str_pos == ' ' || (*str_pos >= '\t' && *str_pos <= '\r'))
		str_pos++;
	if (*str_pos == '-' || *str_pos == '+')
	{
		if (*str_pos == '-')
			sign = -1;
		str_pos++;
	}
	abs_value = (int)ascii_to_int(str_pos, sign);
	return ((int)(abs_value * sign));
}
