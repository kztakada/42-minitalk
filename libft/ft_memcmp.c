/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:19:30 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 19:37:12 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *target_src_1, const void *target_src_2,
		size_t cmp_bytes)
{
	unsigned char	*s1_char;
	unsigned char	*s2_char;
	size_t			compare_count;

	s1_char = (unsigned char *)target_src_1;
	s2_char = (unsigned char *)target_src_2;
	compare_count = 0;
	while (cmp_bytes > compare_count++)
	{
		if (*s1_char != *s2_char)
			return (*s1_char - *s2_char);
		s1_char++;
		s2_char++;
	}
	return (0);
}
