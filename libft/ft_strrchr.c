/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:13:21 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 21:03:16 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str_src, int search_int)
{
	unsigned char	search_char;
	unsigned char	*target_str;
	size_t			target_index;

	search_char = (unsigned char)search_int;
	target_str = (unsigned char *)str_src;
	target_index = ft_strlen(str_src) + 1;
	while (target_index)
	{
		target_index--;
		if (*(target_str + target_index) == search_char)
			return ((char *)(target_str + target_index));
	}
	return (NULL);
}
