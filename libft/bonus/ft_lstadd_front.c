/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:52:24 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 16:54:45 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lists_top, t_list *new_add_list)
{
	if (!lists_top || !new_add_list)
		return ;
	new_add_list->next = *lists_top;
	*lists_top = new_add_list;
}
