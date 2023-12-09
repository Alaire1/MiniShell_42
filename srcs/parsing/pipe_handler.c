/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:59:42 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/09 17:58:12 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ends_with_pipe(char *str)
{
	int	i;

	if (ft_strlen(str) < 1)
		return (0);
	i = ft_strlen(str) - 1;
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

static char	*join_input(char *first_part, char *second_part)
{
	char	*returned_input;

	returned_input = ft_strjoin(first_part, second_part);
	free (second_part);
	free (first_part);
	return (returned_input);
}

static int	begins_with_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '|')
		return (1);
	return (0);
}

static int	just_single_pipe(char *str)
{
	str = ft_strtrim(str, " ");
	if ((ft_strlen(str) == 1) && (str[0] == '|'))
		return (1);
	else
		return (0);
}

char	*handle_ending_pipe(char *input)
{
	char	*extra_input;

	if (begins_with_pipe(input))
	{
		if (just_single_pipe(input))
			syntax_error_token(UNTOKEN, '|', 0);
		return (input);
	}
	while (ends_with_pipe(input))
	{
		signal_handling();
		extra_input = readline (CYAN SIGN RESET);
		if (extra_input == NULL)
		{
			ft_putstr_fd("syntax error: unexpected end of file\n", 2);
			return (input);
		}
		input = join_input (input, extra_input);
	}
	return (input);
}
