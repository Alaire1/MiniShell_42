// static void	update_envir_value(t_env *envir, char *new_value)
// {
//     free(envir->info);
//     envir->info = new_value;
// }
#include "../../includes/minishell.h"

int    get_level(char *info)
{
    int     level;
    char    *level_str;

    level_str = ft_strchr(info, '=') + 1;
    level = atoi(level_str);
    free(info); //not sure it can be freed here
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
// void	incr_shell_lvl(t_list *data)  // function working but is too long
// {
//     t_list	*lst;
//     t_env	*envir;
//     int		level;
//     char    *level_str;
//     char    *new_info;

//     lst = data;
//     while (lst)
//     {
//         envir = (t_env *)lst->content;
//         if (envir && strcmp(envir->name, "SHLVL") == 0)
//         {
//             if (envir->info)
//             {
//                 level = get_level(envir->info) + 1;
//                 if (level <= 999)
//                 { 
//                     level_str = ft_itoa(level);
//                     new_info = get_string("SHLVL=", level_str);
//                     envir->info = new_info;
//                 }
//                 else if (level == 1000)
//                     envir->info = strdup("SHLVL=");
//                 else
//                     envir->info = strdup("SHLVL=1");
//             }
//             return; // Exit the function once the "SHLVL" variable is found and updated
//         }
//         lst = lst->next; // Advance to the next node in the list
//     }
// }

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
            return envir; // Return the "SHLVL" variable
        }
        lst = lst->next; // Advance to the next node in the list
    }
    return NULL; // Return NULL if the "SHLVL" variable is not found
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