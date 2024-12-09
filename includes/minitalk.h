/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:04:28 by katakada          #+#    #+#             */
/*   Updated: 2024/12/09 20:58:00 by katakada         ###   ########.fr       */
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

int	is_int_str(char *str);
#endif