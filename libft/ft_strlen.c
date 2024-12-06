/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:00:13 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 19:25:35 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str_src)
{
	size_t	str_len;

	if (!str_src)
		return (0);
	str_len = 0;
	while (str_src[str_len])
		str_len++;
	return (str_len);
}
