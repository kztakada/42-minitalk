/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:44:44 by katakada          #+#    #+#             */
/*   Updated: 2024/10/29 15:39:15 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1048576
# endif

char	*get_next_line(int fd);
int		init_parm(int *num_of_reads, int *is_end, char **oneline,
			char **read_buf);
int		fd_read(int fd, char **remain, char **buf);
char	*get_next_str(char **buf, char **remain, int *flag);
int		put_oneline(char **result, char *str);

#endif
