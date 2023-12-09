/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_n_fix_out.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npavelic <npavelic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:11:29 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/09 13:48:43 by npavelic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*fix_out_pipe(char *input, int i)
{
	char	q;

	while (input[i])
	{
		if ((input[i] == '\'') || (input[i] == '\"'))
		{
			q = input[i];
			while ((input[i] != q) && (input[i]))
				i++;
		}
		if ((input[i] == '>') && (input[i + 1] == '|'))
			input[i + 1] = ' ';
		i++;
	}
	return (input);
}

char	*trim_n_fix_out(char *input)
{
	char	*result;

	result = ft_strtrim(input, " ");
	result = fix_out_pipe (result, 0);
	return (input);
}
