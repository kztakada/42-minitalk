/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:31:17 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 20:27:56 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *target_str, const char *find_str,
		size_t targeted_len)
{
	size_t	target_idx;
	size_t	find_len;

	if (!target_str)
		return (NULL);
	if (!*find_str)
		return ((char *)target_str);
	if (targeted_len == 0)
		return (NULL);
	target_idx = 0;
	find_len = ft_strlen(find_str);
	while (target_str[target_idx] && (target_idx + find_len) <= targeted_len)
	{
		if (ft_strncmp(&target_str[target_idx], find_str, find_len) == 0)
			return ((char *)&target_str[target_idx]);
		target_idx++;
	}
	return (NULL);
}
