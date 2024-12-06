/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:49:25 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 18:31:46 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str_src_1, char const *str_src_2)
{
	char	*join;
	size_t	len_str1;
	size_t	len_str2;

	if (!str_src_1 || !str_src_2)
		return (NULL);
	len_str1 = ft_strlen(str_src_1);
	len_str2 = ft_strlen(str_src_2);
	join = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, str_src_1, (len_str1 + 1));
	ft_strlcat(join, str_src_2, (len_str1 + len_str2 + 1));
	return (join);
}
