/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:52:12 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/08 14:17:18 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#include "../includes/minishell.h"

static void	input_handler(t_minishell *mini, char *input)
{
	mini->heredoc = 0;
	mini->cmd_num = ft_wordcount_meta(input, '|');
	mini->pipe_num = mini->cmd_num - 1;
	mini->args = split_meta(input, '|');
	mini->paths = ft_split(get_info_env(&mini->env, "PATH"), ':');
	mini->in_fd = STDIN_FILENO;
	mini->out_fd = STDOUT_FILENO;
	mini->pipe_fd = 0;
	mini->pid = (pid_t *)malloc(sizeof(pid_t) * mini->cmd_num);
	mini->cmd_args = 0;
}


/// FUNCTIONS BELOW ARE FOR | end handling

int	ends_with_pipe (char *str)
{
	int	i;

	if (!(ft_strlen(str)))
		return (0);
	i = strlen(str) - 1;
	while (str[i] == ' ') 
	{
		i--;
		if (i < 0)
			return (0);
	}
	if (str[i] == '|')
		return (1);
	return (0);
}

char    *join_input (char    *first_part, char    *second_part)
{
	char    *returned_input;

	returned_input = ft_strjoin(first_part, second_part);
	free (second_part);
	free (first_part);
	return (returned_input);
}

char *handle_ending_pipe(char *input)
{
	char    *extra_input;

	while (ends_with_pipe(input))
	{
		signal_handling();
		extra_input = readline (CYAN SIGN RESET);
		if (extra_input == NULL)
		{
			ft_putstr_fd("syntax error: unexpected end of file\n", 2); // and update  exit
			return (input);
		}
		input = join_input (input, extra_input);
	}
	return (input);
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
	trimmed = ft_strtrim(input, " ");
	free(input);
	if (!valid_input(trimmed))
	{
		g_exit_status = 258;
		return (free(trimmed) ,0);
	}
	input_handler(mini, trimmed);
	free(trimmed);
	return (1);
}