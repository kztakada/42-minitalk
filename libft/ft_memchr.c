/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:02:11 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 18:11:16 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *target_src, int search_int, size_t search_bytes)
{
	unsigned char	search_char;
	unsigned char	*searched_target;
	size_t			target_index;

	search_char = (unsigned char)search_int;
	searched_target = (unsigned char *)target_src;
	target_index = 0;
	while (search_bytes > target_index++)
	{
		if (*searched_target == search_char)
			return ((void *)searched_target);
		searched_target++;
	}
	return (NULL);
}
