/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:10:05 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:40:55 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *target_src, int init_int, size_t set_bytes)
{
	unsigned char	*set_target;
	size_t			set_index;
	unsigned char	init_char;

	set_target = (unsigned char *)target_src;
	init_char = (unsigned char)init_int;
	set_index = 0;
	while (set_bytes > set_index)
	{
		set_target[set_index] = init_char;
		set_index++;
	}
	return (target_src);
}
