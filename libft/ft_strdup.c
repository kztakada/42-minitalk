/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:27:14 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 18:16:47 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str_src)
{
	char	*duplicated_new_str;
	size_t	str_len;

	str_len = ft_strlen(str_src);
	duplicated_new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!duplicated_new_str)
		return (NULL);
	ft_memcpy(duplicated_new_str, str_src, (str_len + 1));
	return (duplicated_new_str);
}
