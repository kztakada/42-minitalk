/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:30:35 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 19:36:50 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1_src, const char *str2_src, size_t cmp_chars)
{
	unsigned char	*s1_char;
	unsigned char	*s2_char;
	size_t			compare_count;

	s1_char = (unsigned char *)str1_src;
	s2_char = (unsigned char *)str2_src;
	compare_count = 0;
	while (cmp_chars > compare_count++)
	{
		if (*s1_char != *s2_char || !*s1_char || !*s2_char)
			return (*s1_char - *s2_char);
		s1_char++;
		s2_char++;
	}
	return (0);
}
