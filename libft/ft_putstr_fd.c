/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:51:21 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 17:33:42 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *str_src, int fd)
{
	int	count;

	count = 0;
	if (!str_src)
		str_src = "(null)";
	count = write(fd, str_src, ft_strlen(str_src));
	return (count);
}
