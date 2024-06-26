/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:50:12 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 19:09:34 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**convert_env(t_minishell *mini)
{
	char	**env;
	t_list	*temp;
	int		i;

	i = 0;
	temp = mini->env;
	env = (char **)malloc(sizeof(char *) * (ft_lstsize(mini->env) + 1));
	while (temp)
	{
		env[i] = ft_strdup(((t_env *)(temp->content))->info);
		i++;
		temp = temp->next;
	}
	env[i] = 0;
	return (env);
}

void	add_to_env(t_list **env, char *info)
{
	t_list	*new;

	new = ft_lstnew(ft_create_data(info));
	ft_lstadd_back(env, new);
}

void	ft_printlist(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		printf("%s\n", ((t_env *)(tmp->content))->info);
		tmp = tmp->next;
	}
}

char	*get_info_env(t_list **env, char *name)
{
	char	*info;
	t_list	*tmp;

	tmp = *env;
	while (tmp != NULL)
	{
		if ((ft_strlen(name) == ft_strlen(((t_env *)(tmp->content))->name))
			&& !ft_strncmp(name, ((t_env *)(tmp->content))->name,
			ft_strlen(((t_env *)(tmp->content))->name)))
		{
			info = ft_strchr(((t_env *)(tmp->content))->info, '=');
			info++;
			return (info);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
