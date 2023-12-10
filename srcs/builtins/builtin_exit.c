/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:09:12 by akaraban          #+#    #+#             */
/*   Updated: 2023/12/10 17:07:24 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_exit(t_minishell *mini, char **cmd_args)
{
	int		status;
	int		i;

	i = 0;
	while (cmd_args[i])
		i++;
	wait(&status);
	if (WIFEXITED(status))
		g_exit_sygnal = WEXITSTATUS(status);
	if (g_exit_sygnal != 1 || (g_exit_sygnal == 1 && i == 2))
	{
		ft_free_split(cmd_args);
		free_main(mini, 1);
		exit (g_exit_sygnal);
	}
}

static void	exit_error3(t_minishell *mini, char **cmd_args)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(cmd_args[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	g_exit_sygnal = 255;
	free_child(mini, cmd_args, 0);
	exit (g_exit_sygnal);
}

static void	exit_error1(t_minishell *mini, char **cmd_args, int i)
{
	if (i == 2)
	{
		g_exit_sygnal = (ft_atoi(cmd_args[1]) % 256);
		free_child(mini, cmd_args, 0);
		exit (g_exit_sygnal);
	}
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_exit_sygnal = 1;
		free_child(mini, cmd_args, 0);
		exit (1);
	}
}

void	builtin_exit(t_minishell *mini, char **cmd_args, int x)
{
	int	i;

	i = 0;
	while (cmd_args[i])
		i++;
	if (x == 1)
		ft_putstr_fd("exit\n", 2);
	if (i > 1)
	{
		if (ft_isnumeric(cmd_args[1]))
			exit_error1(mini, cmd_args, i);
		else
			exit_error3(mini, cmd_args);
	}
	else
	{
		free_child(mini, cmd_args, 0);
		g_exit_sygnal = 0;
		exit(g_exit_sygnal);
	}
}
