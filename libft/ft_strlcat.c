/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:39:09 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 19:05:31 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *str1_dest, const char *str2_src, size_t total_len)
{
	size_t	str1_len;
	size_t	str2_len;
	size_t	copyable_len;
	size_t	str2_index;

	if (!str2_src)
		return (0);
	str2_len = ft_strlen(str2_src);
	if (!str1_dest && total_len == 0)
		return (str2_len);
	if (!str1_dest)
		return (0);
	str1_len = ft_strlen(str1_dest);
	if (str1_len >= total_len)
		return (total_len + str2_len);
	copyable_len = total_len - str1_len - 1;
	str2_index = 0;
	while (str2_src[str2_index] && (str2_index < copyable_len))
	{
		str1_dest[str1_len + str2_index] = str2_src[str2_index];
		str2_index++;
	}
	str1_dest[str1_len + str2_index] = '\0';
	return (str1_len + str2_len);
}
