/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:54:06 by katakada          #+#    #+#             */
/*   Updated: 2024/07/24 17:45:13 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef __linux__
# define TRUE_PARAM 16384
#else
# define TRUE_PARAM 1
#endif

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (TRUE_PARAM);
	return (0);
}
