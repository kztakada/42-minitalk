/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:53:40 by katakada          #+#    #+#             */
/*   Updated: 2024/08/01 17:07:52 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *target_list, void (*f)(void *))
{
	if (!target_list || !f)
		return ;
	while (target_list)
	{
		f(target_list->content);
		target_list = target_list->next;
	}
}
