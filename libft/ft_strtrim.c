/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:44 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 20:45:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str_src, char const *delimiters)
{
	char const	*oneside_trim;
	size_t		untrim_len;
	char		*trimmed_str;

	if (!str_src || !delimiters)
		return (NULL);
	oneside_trim = str_src;
	untrim_len = ft_strlen(str_src);
	while (*oneside_trim && ft_strchr(delimiters, *oneside_trim))
	{
		oneside_trim++;
		untrim_len--;
	}
	while (untrim_len && ft_strchr(delimiters, oneside_trim[untrim_len - 1]))
		untrim_len--;
	trimmed_str = (char *)malloc(sizeof(char) * (untrim_len + 1));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, oneside_trim, untrim_len + 1);
	return (trimmed_str);
}
