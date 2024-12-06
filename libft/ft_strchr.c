/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:38:03 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 18:10:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str_src, int search_int)
{
	unsigned char	search_char;
	unsigned char	*searched_str;

	search_char = (unsigned char)search_int;
	searched_str = (unsigned char *)str_src;
	while (*searched_str)
	{
		if (*searched_str == search_char)
			return ((char *)searched_str);
		searched_str++;
	}
	if (search_char == '\0')
		return ((char *)searched_str);
	return (NULL);
}
