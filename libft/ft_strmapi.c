/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:50:35 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 19:27:46 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str_src, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	str_index;

	if (!str_src || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str_src) + 1));
	if (!new_str)
		return (NULL);
	str_index = 0;
	while (str_src[str_index])
	{
		new_str[str_index] = f(str_index, str_src[str_index]);
		str_index++;
	}
	new_str[str_index] = '\0';
	return (new_str);
}
