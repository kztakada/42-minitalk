/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:00:26 by katakada          #+#    #+#             */
/*   Updated: 2024/07/25 20:28:10 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

static int	apple_toupper(int c)
{
	int	ctoupper;

	if (c >= 'a' && c <= 'z')
	{
		ctoupper = c + ('A' - 'a');
		return (ctoupper);
	}
	return (c);
}

static int	linux_toupper(int c)
{
	int	ctoupper;

	if (c >= -128 && c < 256)
	{
		if (c >= -128 && c < -1)
			c = c + 256;
		if (c >= 'a' && c <= 'z')
		{
			ctoupper = c + ('A' - 'a');
			return (ctoupper);
		}
	}
	return (c);
}

int	ft_toupper(int c)
{
	if (ISLINUX == 1)
		return (linux_toupper(c));
	else
		return (apple_toupper(c));
}
