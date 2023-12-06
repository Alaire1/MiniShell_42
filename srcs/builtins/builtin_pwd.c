/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:50:12 by akaraban          #+#    #+#             */
/*   Updated: 2023/12/06 17:46:54 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_pwd(t_minishell *mini, char **cmd_args)
{
	char	*path;
	int		i;

	i = 0;
	while (cmd_args[i])
		i++;
	if (i > 1)
	{
		if (cmd_args[1][0] == '-')
		{
			ft_putstr_fd("minishell: pwd: no options supported\n", 2);
			g_exit_status = 2;
			free_child(mini, cmd_args, 0);
			exit (g_exit_status);
		}
	}
	path = getcwd(0, 0);
	printf("%s\n", path);
	free(path);
	g_exit_status = 0;
	free_child(mini, cmd_args, 0);
	exit (0);
}
