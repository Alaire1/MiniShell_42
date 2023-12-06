/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:50:12 by akaraban          #+#    #+#             */
/*   Updated: 2023/12/06 17:46:09 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_noption(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
	{
		i++;
		if (!arg[i])
			return (0);
		while (arg[i] == 'n')
			i++;
		if (!arg[i])
			return (1);
		else
			return (0);
	}
	return (0);
}

static void	echo_multi_args2(char **cmd_args, int i)
{
	int	j;

	j = 1;
	while (cmd_args[j])
	{
		ft_putstr(cmd_args[j++]);
		if (j == i)
		{
			printf("\n");
			break ;
		}
		if (cmd_args[j - 1][0] != 0)
			ft_putstr(" ");
	}
}

static void	echo_multi_args(char **cmd_args, int i)
{
	int	j;

	j = 1;
	if (check_noption(cmd_args[1]))
	{
		j++;
		while (check_noption(cmd_args[j]))
			j++;
		while (cmd_args[j])
		{
			ft_putstr(cmd_args[j++]);
			if (j == i)
				break ;
			ft_putstr(" ");
		}
	}
	else
		echo_multi_args2(cmd_args, i);
}

void	builtin_echo(t_minishell *mini, char **cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i])
		i++;
	if (i == 1)
		printf("\n");
	else if (i == 2)
	{
		if (check_noption(cmd_args[1]))
			ft_putstr("");
		else
			ft_putendl_fd(cmd_args[1], 1);
	}
	else
		echo_multi_args(cmd_args, i);
	free_child(mini, cmd_args, 0);
	g_exit_status = 0;
	exit (0);
}
