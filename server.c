/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:34 by msukri            #+#    #+#             */
/*   Updated: 2022/05/19 16:20:36 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include <stdio.h>

static void	str_count_to_client(int signal, siginfo_t *source, void *context)
{
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;
	static int				i = 0;

	(void)context;
	if (!client_pid)
		client_pid = source->si_pid;
	c |= (signal == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		printf("%c", c);
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	a_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	a_sigaction.sa_sigaction = str_count_to_client;
	a_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &a_sigaction, 0);
	sigaction(SIGUSR2, &a_sigaction, 0);
	while (1)
		pause();
	return (0);
}
