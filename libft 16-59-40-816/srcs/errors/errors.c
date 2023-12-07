/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:50:12 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 19:09:50 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_error2(t_minishell *mini, char **cmd_args)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(cmd_args[1], 2);
	ft_putstr_fd(": Invalid option\n", 2);
	free_child(mini, cmd_args, 0);
	exit (2);
}

void	command_error(char *command, char **cmd_args, t_minishell *mini)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
	free_child(mini, cmd_args, 0);
	g_exit_status = 127;
	exit(127);
}

void	permission_error(char **cmd_args, t_minishell *mini)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd(": Permission denied\n", 2);
	free_child(mini, cmd_args, 0);
	g_exit_status = 126;
	exit(126);
}

void	file_error(char **cmd_args, t_minishell *mini)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	free_child(mini, cmd_args, 0);
	g_exit_status = 127;
	exit(127);
}

void	is_a_directory(char **cmd_args, t_minishell *mini)
{
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd(": Is a directory\n", 2);
	free_child(mini, cmd_args, 0);
	g_exit_status = 126;
	exit(126);
}
