/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:50:21 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 16:28:02 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int int_src)
{
	long	target_int;
	int		int_digits;
	int		str_index;
	char	*new_str;

	target_int = int_src;
	int_digits = intlen(int_src);
	new_str = (char *)malloc(sizeof(char) * (int_digits + 1));
	str_index = int_digits;
	if (!new_str)
		return (NULL);
	new_str[str_index] = '\0';
	if (target_int < 0)
	{
		new_str[0] = '-';
		target_int *= -1;
	}
	if (target_int == 0)
		new_str[0] = '0';
	while (target_int)
	{
		new_str[--str_index] = target_int % 10 + '0';
		target_int /= 10;
	}
	return (new_str);
}
