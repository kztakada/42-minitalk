/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:53:54 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:19:11 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *target_list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_new_list;
	t_list	*next_list;
	void	*next_content;

	if (!target_list || !f || !del)
		return (NULL);
	mapped_new_list = NULL;
	while (target_list)
	{
		next_content = f(target_list->content);
		next_list = ft_lstnew(next_content);
		if (!next_list)
		{
			del(next_content);
			ft_lstclear(&mapped_new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_new_list, next_list);
		target_list = target_list->next;
	}
	return (mapped_new_list);
}
