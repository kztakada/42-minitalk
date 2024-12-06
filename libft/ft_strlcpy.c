/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:01:47 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 19:23:16 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *copy_str_dest, const char *copy_str_src,
		size_t copy_len)
{
	size_t	str_index;
	size_t	copyable_len;

	if (!copy_str_dest || !copy_str_src)
		return (0);
	if (copy_len > 0)
	{
		str_index = 0;
		copyable_len = copy_len - 1;
		while (copy_str_src[str_index] && (str_index < copyable_len))
		{
			copy_str_dest[str_index] = copy_str_src[str_index];
			str_index++;
		}
		copy_str_dest[str_index] = '\0';
	}
	return (ft_strlen(copy_str_src));
}
