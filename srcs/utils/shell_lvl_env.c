/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lvl_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:07:12 by akaraban          #+#    #+#             */
/*   Updated: 2023/12/08 13:07:53 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int    get_level(char *info)
{
    int     level;
    char    *level_str;

    level_str = ft_strchr(info, '=') + 1;
    level = atoi(level_str);
    free(info);
    return (level);
}

char    *get_string(char *name, char *info)
{
    char	*new_info;
    int		len;

    len = strlen(name) + strlen(info) + 1;
    new_info = malloc(sizeof(char) * len);
    strcpy(new_info, name);
    strcat(new_info, info);
    free(info);
    return (new_info);
}

t_env *find_shlvl(t_list *data)
{
    t_list	*lst;
    t_env	*envir;

    lst = data;
    while (lst)
    {
        envir = (t_env *)lst->content;
        if (envir && strcmp(envir->name, "SHLVL") == 0)
        {
            return envir;
        }
        lst = lst->next; 
    }
    return NULL;
}

void update_shlvl(t_env *envir)
{
    int		level;
    char    *level_str;
    char    *new_info;

    if (envir->info)
    {
        level = get_level(envir->info) + 1;
        if (level <= 999)
        { 
            level_str = ft_itoa(level);
            new_info = get_string("SHLVL=", level_str);
            envir->info = new_info;
        }
        else if (level == 1000)
            envir->info = strdup("SHLVL=");
        else
            envir->info = strdup("SHLVL=1");
    }
}

void incr_shell_lvl(t_list *data)
{
    t_env *envir = find_shlvl(data);
    if (envir)
    {
        update_shlvl(envir);
    }
}