/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:53:26 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:03:20 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lists_top, void (*del)(void *))
{
	t_list	*next_list;

	if (!lists_top || !*lists_top || !del)
		return ;
	while ((*lists_top))
	{
		next_list = (*lists_top)->next;
		ft_lstdelone((*lists_top), del);
		(*lists_top) = next_list;
	}
}
