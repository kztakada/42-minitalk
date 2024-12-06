/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:53:05 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 16:07:11 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **lists_top, t_list *new_add_list)
{
	t_list	*last_list;

	if (!lists_top || !new_add_list)
		return (1);
	if (!*lists_top)
		*lists_top = new_add_list;
	else
	{
		last_list = ft_lstlast(*lists_top);
		if (!last_list)
			return (1);
		last_list->next = new_add_list;
	}
	return (0);
}
