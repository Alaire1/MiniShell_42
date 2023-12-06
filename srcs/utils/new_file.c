// static void	update_envir_value(t_env *envir, char *new_value)
// {
//     free(envir->info);
//     envir->info = new_value;
// }
#include "../../includes/minishell.h"
void	incr_shell_lvl(t_list *data)
{
    t_list	*lst;
    t_env	*envir;
    int		level;

    lst = data;
    while (lst)
    {
        envir = (t_env *)lst->content;
        if (envir && strcmp(envir->name, "SHLVL") == 0)
        {
            free(envir->name); // Free the old name before assigning a new value
            envir->name = strdup("SHLVL"); // Set the name to "SHLVL"
            if (envir->info)
            {
                level = ft_atoi(envir->info) + 1;
                free(envir->info);
                if (level <= 999)
                    envir->info = ft_itoa(level);
                else if (level == 1000)
                    envir->info = strdup("");
                else
                    envir->info = strdup("1");
            }
            return; // Exit the function once the "SHLVL" variable is found and updated
        }
        lst = lst->next; // Advance to the next node in the list
    }
}