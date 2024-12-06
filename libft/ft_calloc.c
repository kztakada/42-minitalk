/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:59:27 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 16:10:52 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t data_count, size_t data_type_size)
{
	void	*init_zero;
	size_t	size_t_max;

	size_t_max = SIZE_MAX;
	if (data_count && data_type_size > (size_t_max / data_count))
		return (NULL);
	init_zero = (void *)malloc(data_type_size * data_count);
	if (!init_zero)
		return (NULL);
	ft_bzero(init_zero, (data_type_size * data_count));
	return (init_zero);
}
