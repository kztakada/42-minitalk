/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:04:28 by katakada          #+#    #+#             */
/*   Updated: 2024/12/12 15:02:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef U_SLEEP_TIME
#  define U_SLEEP_TIME 100
# endif

# include "../libft/includes/libft.h"
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		is_int_str(char *str);
void	error_exit(char *format, char *message);
int		send_kill_signal(int pid, int signum);
#endif