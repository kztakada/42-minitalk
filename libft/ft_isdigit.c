/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:09:01 by katakada          #+#    #+#             */
/*   Updated: 2024/07/24 17:45:01 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef __linux__
# define TRUE_PARAM 2048
#else
# define TRUE_PARAM 1
#endif

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE_PARAM);
	return (0);
}
