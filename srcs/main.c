/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:21:42 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 17:52:41 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status = 0;

void initialize(char **sys_env, t_minishell *mini)
{
	mini->env = init_env(sys_env);
	mini->export = init_export(sys_env);
}

int	main(int argc, char **argv, char **sys_env)
{
	t_minishell	mini;
	int			input_check;	

	(void)argv;
	ft_terminal_non_print_off();
	if (argc > 1)
		printf("minishell: too many arguments\nUse: ./minishell\n");
	else if (argc == 1)
	{
		initialize(sys_env, &mini);
		while (1)
		{
			input_check = 0;
			signal_handling();
			input_check = read_input(&mini);
			if (!input_check)
				continue ;
			else if (input_check == -1)
				break ;
			executer(&mini);
		}
		return (rl_clear_history(), free_env(mini.env),
			free_export(mini.export), printf("exit\n"), 0);
	}
	return (0);
}
