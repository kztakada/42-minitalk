/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:03:40 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 18:46:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_invalid_char_start_case(const char **format, int fd)
{
	int	count;

	count = 0;
	if (ISLINUX == 1)
	{
		(*format)--;
		while (**format != '\0')
		{
			if (ft_putchar_fd(**format, fd) < 0)
				return (-1);
			count++;
			(*format)++;
			if (**format != '%')
				break ;
		}
		(*format)--;
		return (count);
	}
	else
	{
		if (ft_putchar_fd(**format, fd) < 0)
			return (-1);
		return (1);
	}
}

int	print_over_flow_case(void)
{
	errno = EOVERFLOW;
	return (-1);
}
