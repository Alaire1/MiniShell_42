/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:40:07 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/10 17:26:40 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shift_redir(char **cmd_args, int *i, int *count)
{
	int	index;

	index = *i;
	while (index < *count - 2)
	{
		free(cmd_args[index]);
		cmd_args[index] = ft_strdup(cmd_args[index + 2]);
		index++;
	}
	if (*count - 2 <= 0)
	{
		free(cmd_args[0]);
		free(cmd_args[1]);
	}
	else
	{
		free(cmd_args[index]);
		free(cmd_args[index + 1]);
	}
	*count = *count - 2;
	cmd_args[index] = 0;
	*i = -1;
}

static void	handle_app(char **cmd_args, t_minishell *mini, int *i, int *count)
{
    errno = 0;

    if (ft_strrchr(cmd_args[*i + 1], '$'))
    {
        cmd_args[*i + 1] = expander(cmd_args[*i + 1], mini);
        cmd_args[*i + 1] = remove_quotes(cmd_args[*i + 1]);
        mini->out_fd = open(cmd_args[*i + 1], O_RDWR | O_CREAT | O_APPEND,
                S_IRUSR | S_IWUSR);
    }
    else
    {
        cmd_args[*i + 1] = remove_quotes(cmd_args[*i + 1]);
        mini->out_fd = open(cmd_args[*i + 1], O_RDWR | O_CREAT | O_APPEND,
                S_IRUSR | S_IWUSR);
    }
    if (mini->out_fd == -1)
    {
        if (errno == EACCES) 
        {
            ft_putstr_fd("Bash4Cash: ", STDERR_FILENO);
			ft_putstr_fd(cmd_args[*i + 1], STDERR_FILENO);
			ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
            free_child(mini, cmd_args, 1);
		}
    }
    shift_redir(cmd_args, i, count);
}

static void	handle_out(char **cmd_args, t_minishell *mini, int *i, int *count)
{
	if (ft_strrchr(cmd_args[*i + 1], '$'))
	{
		cmd_args[*i + 1] = expander(cmd_args[*i + 1], mini);
		cmd_args[*i + 1] = remove_quotes(cmd_args[*i + 1]);
		mini->out_fd = open(cmd_args[*i + 1], O_RDWR | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR);
	}
	else
	{
		cmd_args[*i + 1] = remove_quotes(cmd_args[*i + 1]);
		mini->out_fd = open(cmd_args[*i + 1], O_RDWR | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR);
	}
	if (mini->out_fd < 0)
	{
		ft_putstr_fd("Error creating file\n", 2);
		free_child(mini, cmd_args, 1);
	}
	shift_redir(cmd_args, i, count);
}

static void	handle_in(char **cmd_args, t_minishell *mini, int *i, int *count)
{
	if (ft_strrchr(cmd_args[*i + 1], '$'))
	{
		cmd_args[*i + 1] = expander(cmd_args[*i + 1], mini);
		mini->in_fd = open(cmd_args[*i + 1], O_RDONLY);
	}
	else
		mini->in_fd = open(cmd_args[*i + 1], O_RDONLY);
	if (mini->in_fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_args[*i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		free_child(mini, cmd_args, 1);
	}
	shift_redir(cmd_args, i, count);
}

char	**handle_redirs(t_minishell *mini, char *input)
{
	char	**cmd_args;
	int		i;
	int		count;

	i = 0;
	mini->in_fd = 0;
	mini->out_fd = 1;
	count = ft_wordcount_mini(input, ' ');
	cmd_args = split_input(input, ' ');
	free(input);
	while (cmd_args[i])
	{
		if (ft_strncmp(cmd_args[i], "<", ft_strlen(cmd_args[i])) == 0)
			handle_in(cmd_args, mini, &i, &count);
		else if (ft_strncmp(cmd_args[i], ">", ft_strlen(cmd_args[i])) == 0)
			handle_out(cmd_args, mini, &i, &count);
		else if (ft_strncmp(cmd_args[i], ">>", ft_strlen(cmd_args[i])) == 0)
			handle_app(cmd_args, mini, &i, &count);
		else if (ft_strncmp(cmd_args[i], "<<", ft_strlen(cmd_args[i])) == 0)
			handle_heredoc(cmd_args, mini, &i, &count);
		i++;
	}
	return (cmd_args);
}
