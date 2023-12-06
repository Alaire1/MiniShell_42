/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:52:12 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 20:07:26 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

// static char	*get_prompt(void)
// {
// 	char	*temp;
// 	char	*prompt;

// 	prompt = getenv("USER");
// 	temp = ft_strdup(prompt);
// 	prompt = ft_strjoin(temp, " > ");
// 	free(temp);
// 	return (prompt);
// }

int	read_input(t_minishell *mini)
{
	char		*input;
	char		*trimmed;

	// prompt = get_prompt();
	input = readline(LIGHT_GREEN PROMPT CYAN SIGN RESET);
	if (!input)
		return (-1);
	if (ft_strlen(input) > 0)
		add_history(input);
	trimmed = ft_strtrim(input, " ");
	free(input);
	if (!valid_input(trimmed))
	{
		free(trimmed);
		g_exit_status = 2;
		return (0);
	}
	input_handler(mini, trimmed);
	free(trimmed);
	return (1);
}
