/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:44:34 by katakada          #+#    #+#             */
/*   Updated: 2024/08/17 14:46:45 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	init_parm(int *is_readable, int *is_end, char **oneline, char **read_buf)
{
	*is_readable = 1;
	*is_end = 0;
	*oneline = ft_strdup("");
	if (!*oneline)
		return (0);
	*read_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*read_buf)
		return (free(*oneline), 0);
	return (1);
}

int	fd_read(int fd, char **save_buf, char **read_buf)
{
	int	num_of_reads;

	if (!*save_buf)
	{
		num_of_reads = read(fd, *read_buf, BUFFER_SIZE);
		if (num_of_reads == -1)
			return (-1);
		(*read_buf)[num_of_reads] = '\0';
		return (num_of_reads);
	}
	ft_memcpy(*read_buf, *save_buf, ft_strlen(*save_buf) + 1);
	free(*save_buf);
	*save_buf = NULL;
	return (ft_strlen(*read_buf));
}

char	*get_next_str(char **read_buf, char **save_buf, int *is_end)
{
	char	*str_end;
	char	*str_remain;

	str_end = *read_buf;
	while (*str_end != '\0')
	{
		if (*str_end == '\n')
		{
			*is_end = 1;
			str_remain = str_end + 1;
			if (ft_strlen(str_remain))
			{
				*save_buf = ft_strdup(str_remain);
				if (!*save_buf)
					return (NULL);
			}
			break ;
		}
		str_end++;
	}
	return (ft_substr(*read_buf, 0, (str_end - (*read_buf) + 1)));
}

int	put_oneline(char **oneline, char *str)
{
	char	*new_joined_line;

	if (!str)
		return (free(*oneline), 0);
	new_joined_line = ft_strjoin(*oneline, str);
	if (!new_joined_line)
		return (free(*oneline), free(str), 0);
	free(*oneline);
	free(str);
	*oneline = new_joined_line;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*save_buf[OPEN_MAX];
	char		*read_buf;
	char		*oneline;
	int			is_end;
	int			is_readable;

	if (fd < 0)
		return (NULL);
	if (!init_parm(&is_readable, &is_end, &oneline, &read_buf))
		return (NULL);
	while (is_readable && !is_end)
	{
		is_readable = fd_read(fd, &save_buf[fd], &read_buf);
		if (is_readable == -1 || (is_readable == 0 && !ft_strlen(oneline)))
			return (free(read_buf), free(oneline), NULL);
		if (!put_oneline(&oneline, get_next_str(&read_buf, &save_buf[fd],
					&is_end)))
			return (free(read_buf), NULL);
	}
	return (free(read_buf), oneline);
}
