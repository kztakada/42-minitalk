/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_validator_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:18:20 by katakada          #+#    #+#             */
/*   Updated: 2024/10/10 23:18:21 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_field_digit(int c)
{
	return (ft_isdigit(c) || c == '*');
}

int	is_precision_dot(int c)
{
	return (c == '.');
}

int	is_number_type(int c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int	is_format_type(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == '%' || is_number_type(c));
}
