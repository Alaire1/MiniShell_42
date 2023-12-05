
#include "../includes/minishell.h"

int	g_exit_status = 0;

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
		mini.env = init_env(sys_env);
		mini.export = init_export(sys_env);
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
			free_export(mini.export), ft_putstr("exit\n"), 0);
	}
	return (0);
}
