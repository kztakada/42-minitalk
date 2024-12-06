/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:52:39 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:21:44 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *target_list)
{
	int		size_count;
	t_list	*current_list;

	size_count = 0;
	current_list = target_list;
	while (current_list)
	{
		size_count++;
		current_list = current_list->next;
	}
	return (size_count);
}
