/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:56:06 by katakada          #+#    #+#             */
/*   Updated: 2024/12/09 21:00:31 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_all_digit_char(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_int_range(char *str_pos, int sign)
{
	unsigned long	int_value;
	int				digit_value;
	unsigned long	max_limit;

	int_value = 0;
	max_limit = (unsigned long)INT_MAX;
	while (ft_isdigit(*str_pos))
	{
		digit_value = *str_pos - '0';
		if (sign == 1 && int_value > ((max_limit - digit_value) / 10))
			return (0);
		if (sign == -1 && int_value > ((max_limit + 1 - digit_value) / 10))
			return (0);
		int_value = int_value * 10 + digit_value;
		str_pos++;
	}
	return (1);
}

int	is_int_str(char *str)
{
	size_t	j;
	int		sign;

	sign = 1;
	j = 0;
	while (str[j] == ' ' || (str[j] >= '\t' && str[j] <= '\r'))
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			sign = -1;
		j++;
	}
	if (!is_all_digit_char(&(str[j])))
		return (0);
	if (!is_int_range(&(str[j]), sign))
		return (0);
	return (1);
}
