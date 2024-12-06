/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:05 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 20:58:54 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *main_str_src, unsigned int start_index,
		size_t request_substr_len)
{
	size_t	main_str_len;
	size_t	substr_len;
	char	*substr;

	if (!main_str_src)
		return (NULL);
	main_str_len = ft_strlen(main_str_src);
	substr_len = request_substr_len;
	if (main_str_len <= start_index)
		return (ft_strdup(""));
	if (main_str_len < (start_index + request_substr_len))
		substr_len = main_str_len - start_index;
	substr = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, (main_str_src + start_index), substr_len);
	substr[substr_len] = '\0';
	return (substr);
}
