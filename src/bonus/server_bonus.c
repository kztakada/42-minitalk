/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:38 by katakada          #+#    #+#             */
/*   Updated: 2024/12/05 20:43:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	unsigned char	utf8_char01;
	unsigned char	utf8_char02;
	unsigned char	utf8_char03;

	(void)argv;
	(void)argc;
	ft_printf("[SERVER] PID is %d\n", getpid());
	utf8_char01 = 0xE3;
	utf8_char02 = 0x81;
	utf8_char03 = 0x82;
	write(STDOUT_FILENO, &utf8_char01, 1);
	write(STDOUT_FILENO, &utf8_char02, 1);
	write(STDOUT_FILENO, &utf8_char03, 1);
	while (1)
		pause();
	return (0);
}
