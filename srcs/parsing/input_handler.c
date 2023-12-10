/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:52:12 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/10 18:14:29 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	input_handler(t_minishell *mini, char *input)
{
	mini->heredoc = 0;
	mini->cmd_num = ft_wordcount_mini(input, '|');
	mini->pipe_num = mini->cmd_num - 1;
	mini->args = split_input(input, '|');
	mini->paths = ft_split(get_info_env(&mini->env, "PATH"), ':');
	mini->in_fd = STDIN_FILENO;
	mini->out_fd = STDOUT_FILENO;
	mini->pipe_fd = 0;
	mini->pid = (pid_t *)malloc(sizeof(pid_t) * mini->cmd_num);
	mini->cmd_args = 0;
}

char	*fix_out_pipe(char *input, int i)
{
	char	q;

	if ((input[0] == '>') && (input[1] == '|'))
		input[1] = ' ';
	while (input[i])
	{
		if ((input[i] == '\'') || (input[i] == '\"'))
		{
			q = input[i];
			while ((input[i] != q) && (input[i]))
				i++;
			if (!input[i])
				return (input);
		}
		if ((input[i] == '>') && (input[i + 1] == '|')
			&& (input[i - 1] != '>'))
			input[i + 1] = ' ';
		i++;
	}
	return (input);
}

char	*trim_n_fix_out(char *input)
{
	char	*result;

	result = ft_strtrim(input, " ");
	if (ft_strlen(result) == 0)
	{
		free(input);
		return (result);
	}
	result = fix_out_pipe (result, 1);
	free(input);
	return (result);
}

int	read_input(t_minishell *mini)
{
	char		*input;
	char		*trimmed;
	
	
	input = readline(LIGHT_GREEN PROMPT CYAN SIGN RESET);
	if (!input)
		return (-1);
	if (ends_with_pipe(input))
		input = handle_ending_pipe(input);
	if (!input)
		return (-1);
	if (ft_strlen(input) > 0)
		add_history(input);
	trimmed = trim_n_fix_out(input);
	if (!valid_input(trimmed))
	{
		g_exit_sygnal = 258;
		return (free(trimmed), 0);
	}
	input_handler(mini, trimmed);
	free(trimmed);
	return (1);
}
