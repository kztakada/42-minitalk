/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:50 by katakada          #+#    #+#             */
/*   Updated: 2024/12/08 22:26:25 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum)
{
	static unsigned char	utf8_char;
	static int				bit_count;

	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		utf8_char <<= 1;
		bit_count++;
	}
	if (signum == SIGUSR2)
		utf8_char += 1;
	if (bit_count == 8)
	{
		if (utf8_char != '\0')
			write(STDOUT_FILENO, &utf8_char, 1);
		bit_count = 0;
		utf8_char = 0;
	}
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("SERVER PID: %d\n", getpid());
	s_action.sa_handler = sig_handler;
	sigemptyset(&s_action.sa_mask);
	sigaddset(&s_action.sa_mask, SIGUSR1);
	sigaddset(&s_action.sa_mask, SIGUSR2);
	s_action.sa_flags = 0;
	if (sigaction(SIGUSR1, &s_action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &s_action, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
