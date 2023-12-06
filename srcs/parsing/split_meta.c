/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:20:52 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 19:10:16 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_wordcount_meta(char *str, char c)
{
	int		i;
	int		wordcount;
	char	quote;

	i = 0;
	wordcount = 0;
	quote = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			wordcount++;
		while ((str[i] && str[i] != c) || (str[i] && quote))
		{
			quote = quote_value(str[i], quote);
			i++;
		}
	}
	return (wordcount);
}

static int	ft_wordlen(char *str, char c)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while ((str[i] && (str[i] != c)) || (str[i] && quote))
	{
		quote = quote_value(str[i], quote);
		i++;
	}
	return (i);
}

static char	*get_word(char *s, char c, char **words)
{
	char	quote;

	quote = 0;
	*words = ft_substr(s, 0, ft_wordlen(s, c));
	while ((*s && *s != c) || (*s && quote))
	{
		quote = quote_value(*s, quote);
		s++;
	}
	return (s);
}

char	**split_meta(char *s, char c)
{
	char	**words;
	int		wdcount;
	int		j;

	j = 0;
	if (!s)
		return (0);
	wdcount = ft_wordcount_meta(s, c);
	words = (char **)malloc(sizeof(char *) * (wdcount + 1));
	if (!words)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			s = get_word(s, c, &words[j++]);
	}
	words[j] = 0;
	return (words);
}
