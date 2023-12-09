/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:29:57 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/09 18:41:16 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	syntax_error_operator(char *error, char *operator)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(operator, 2);
	ft_putstr_fd("'\n", 2);
	return (1);
}

int	syntax_error_token(char *error, char metachar, int dup)
{
	ft_putstr_fd(error, 2);
	ft_putchar_fd(metachar, 2);
	if (dup == 1)
		ft_putchar_fd(metachar, 2);
	ft_putstr_fd("'\n", 2);
	return (1);
}

int	unexpected_token_redir(char *input, int *i)
{
	if (input[*i] == input[*i + 1])
		(*i)++;
	(*i)++;
	if (input[*i] == ' ')
		while (input[*i] && input [*i] == ' ')
			(*i)++;
	if (input[*i] == '|')
		return (syntax_error_token(UNTOKEN, '|', 0));
	else if (input[*i - 1] == '>' && input[*i] == '|')
		return (syntax_error_operator(NOSUPPORT, ">|"));
	else if (ft_strrchr(REDIR, input[*i]) && !input[*i])
		return (syntax_error_operator(UNTOKEN, "newline"));
	else if (ft_strrchr(REDIR, input[*i]) && input[*i] != input[*i + 1])
		return (syntax_error_token(UNTOKEN, input[*i], 0));
	else if (ft_strrchr(REDIR, input[*i]) && input[*i] == input[*i + 1])
		return (syntax_error_token(UNTOKEN, input[*i + 1], 1));
	return (0);
}
