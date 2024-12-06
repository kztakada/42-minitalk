/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:19:32 by katakada          #+#    #+#             */
/*   Updated: 2024/07/25 20:27:53 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

static int	apple_tolower(int c)
{
	int	ctolower;

	if (c >= 'A' && c <= 'Z')
	{
		ctolower = c - ('A' - 'a');
		return (ctolower);
	}
	return (c);
}

static int	linux_tolower(int c)
{
	int	ctolower;

	if (c >= -128 && c < 256)
	{
		if (c >= -128 && c < -1)
			c = c + 256;
		if (c >= 'A' && c <= 'Z')
		{
			ctolower = c - ('A' - 'a');
			return (ctolower);
		}
	}
	return (c);
}

int	ft_tolower(int c)
{
	if (ISLINUX == 1)
		return (linux_tolower(c));
	else
		return (apple_tolower(c));
}
