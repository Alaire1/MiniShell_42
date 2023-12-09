/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:50:12 by akaraban          #+#    #+#             */
/*   Updated: 2023/12/09 16:51:01 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_env(t_minishell *mini, char **cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i])
		i++;
	if (i > 1)
	{
		ft_putstr_fd("env: No options or arguments supported\n", 2);
		free_child(mini, cmd_args, 0);
		g_exit_sygnal = 1;
		exit (1);
	}
	ft_printlist(mini->env);
	free_child(mini, cmd_args, 0);
	g_exit_sygnal = 0;
	exit (0);
}
