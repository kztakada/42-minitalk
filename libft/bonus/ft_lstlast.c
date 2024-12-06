/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:52:51 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:16:12 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *first_list)
{
	t_list	*last_list;

	if (!first_list)
		return (NULL);
	last_list = first_list;
	while (last_list->next)
		last_list = last_list->next;
	return (last_list);
}
