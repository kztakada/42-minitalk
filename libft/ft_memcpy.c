/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:07:16 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:42:34 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *target_dest, const void *target_src, size_t copy_bytes)
{
	unsigned char	*copy_dest;
	unsigned char	*copy_src;
	size_t			target_index;

	if (!target_dest || !target_src)
		return (target_dest);
	copy_dest = (unsigned char *)target_dest;
	copy_src = (unsigned char *)target_src;
	target_index = 0;
	if (target_dest != target_src)
	{
		while (copy_bytes > target_index++)
			*copy_dest++ = *copy_src++;
	}
	return (target_dest);
}
