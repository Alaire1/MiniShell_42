/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:07:02 by akaraban          #+#    #+#             */
/*   Updated: 2023/12/07 16:45:11 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_num_from_str(char *str)
{
	int i;
	int j;
	char *num;

	i = 0;
	j = 0;
	num = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		i++;
	while (str[i])
	{
		num[j] = str[i];
		i++;
		j++;
	}
	num[j] = '\0';
	return num;
}

char *get_updated_shlvl(char *str)
{
	int j;
	char *num;
	char *new_str;

	num = get_num_from_str(str);
	printf("num = %s\n", num);
	j = ft_atoi(num) + 1;
	free(num);
	if (j == 1000)
		num = strdup("");
	else if (j > 1000)
		num = strdup("1");
	else
		num = ft_itoa(j);
	new_str = ft_strjoin("SHLVL=", num);
	printf("new_str = %s\n", new_str);
	free(num);
	return (new_str);	
}