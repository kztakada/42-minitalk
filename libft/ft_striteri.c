/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:50:49 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 18:19:23 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *target_str, void (*f)(unsigned int, char *))
{
	unsigned int	str_index;

	if (!target_str || !f)
		return ;
	str_index = 0;
	while (target_str[str_index])
	{
		f(str_index, &target_str[str_index]);
		str_index++;
	}
}
