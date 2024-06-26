/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:50:12 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/09 16:55:54 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	quote_value(char c, char quote)
{
	if (ft_strrchr("\"\'", c) && !quote)
		return (c);
	else if (ft_strrchr("\"\'", c) && quote == c)
		return (0);
	return (quote);
}

int	isalnumextra(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1 || c == '_')
		return (1);
	else
		return (0);
}

void	get_exit_sygnal(t_minishell *mini)
{
	int		i;
	pid_t	j;
	int		status;

	i = 0;
	status = 0;
	while (i < mini->cmd_num)
	{
		signal(SIGINT, &handler_sigint);
		j = waitpid(mini->pid[i++], &status, 0);
		if (j < 0)
			continue ;
		if (WIFEXITED(status))
			g_exit_sygnal = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_exit_sygnal = 1;
	}
}

void	free_child(t_minishell *mini, char **cmd_args, int i)
{
	if (cmd_args)
		ft_free_split(cmd_args);
	if (mini->pipe_fd)
		free(mini->pipe_fd);
	unlink(".heredoc");
	if (mini->paths)
		ft_free_split(mini->paths);
	if (mini->cmd_args)
		ft_free_split(mini->cmd_args);
	if (mini->args)
		ft_free_split(mini->args);
	free_env(mini->env);
	free(mini->pid);
	free_export(mini->export);
	if (i == 1)
	{
		g_exit_sygnal = 1;
		exit(1);
	}
}

void	free_main(t_minishell *mini, int i)
{
	free(mini->pid);
	if (mini->pipe_fd)
		free(mini->pipe_fd);
	unlink(".heredoc");
	if (mini->paths)
		ft_free_split(mini->paths);
	if (mini->args)
		ft_free_split(mini->args);
	if (i == 1)
		free_env(mini->env);
}
