/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:49:25 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:41:57 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *target_dest, const void *target_src,
		size_t copy_bytes)
{
	unsigned char	*move_dest;
	unsigned char	*move_src;
	size_t			target_index;

	if (!target_dest || !target_src)
		return (target_dest);
	if (target_dest < target_src)
		return (ft_memcpy(target_dest, target_src, copy_bytes));
	move_dest = (unsigned char *)target_dest;
	move_src = (unsigned char *)target_src;
	target_index = 0;
	move_dest += copy_bytes;
	move_src += copy_bytes;
	while (copy_bytes > target_index++)
		*--move_dest = *--move_src;
	return (target_dest);
}
