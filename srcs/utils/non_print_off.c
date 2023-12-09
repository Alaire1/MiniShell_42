/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_print_off.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npavelic <npavelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:50:12 by akaraban          #+#    #+#             */
/*   Updated: 2023/12/09 13:43:59 by npavelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <termios.h>

void	ft_modify_attribute(int fd, int flag, int operation)
{
	struct termios	term_flags;

	if (isatty(fd))
	{
		tcgetattr(fd, &term_flags);
		if (operation == 1)
			term_flags.c_lflag |= flag;
		else if (operation == 0)
			term_flags.c_lflag &= ~flag;
		tcsetattr(fd, TCSANOW, &term_flags);
	}
}

void	ft_terminal_non_print_off(void)
{
	int	flag;

	flag = ECHOCTL;
	ft_modify_attribute(STDIN_FILENO, flag, 1);
	ft_modify_attribute(STDOUT_FILENO, flag, 0);
	ft_modify_attribute(STDERR_FILENO, flag, 0);
}
