/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:59:42 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/10 17:02:28 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <termios.h>

//Colors header
# include <colors.h>

# define PROMPT "Bash4Cash💸"
# define SIGN "-> "

# define METACHAR "><|"  //no need to replicate or handle \;
# define REDIR "><"
# define GGREATER ">>"
# define LLOWER "<<"
# define NOTHANDLE "&;(){}*\\"

# define UNTOKEN "Bash4Cash💸: syntax error near unexpected token `"
# define NOSUPPORT "Bash4Cash💸: no support for operator `"

extern int	g_exit_sygnal;

typedef struct s_minishell
{
	char	**args;
	char	**paths;
	int		in_fd;
	int		out_fd;
	int		cmd_num;
	int		pipe_num;
	int		*pipe_fd;
	pid_t	*pid;
	t_list	*env;
	t_list	*export;
	int		counter;
	int		heredoc;
	int		heredoc_fd;
	char	**cmd_args;
}	t_minishell;

typedef struct s_exp
{
	char	*name;
	char	*info;
}	t_exp;

typedef struct s_env
{
	char	*name;
	char	*info;
}	t_env;

/*ENV-------------------------------------------------------------------------*/

//env_utils.c
char	**convert_env(t_minishell *mini);
char	*get_info_env(t_list **env, char *name);
void	ft_printlist(t_list *list);
void	add_to_env(t_list **env, char *info);

///env.c
t_list	*init_env(char **env);
t_env	*ft_create_data(char *info);
char	*get_name(char *info);
int		modify_info(t_list *env, char *name, char *changed_info);
void	free_env(t_list *env);

//export.c
t_list	*init_export(char **env);
t_exp	*ft_create_export(char *info);
int		modify_export(t_list *exp, char *name, char *changed_info);
void	free_export(t_list *exp);
char	**convert_export(t_minishell *mini);

/*BUILTINS--------------------------------------------------------------*/

///builtin_cd.c
void	builtin_cd(t_minishell *mini, char **cmd_args);
void	check_cd(t_minishell *mini, char **cmd_args);

///builtin_echo.c
void	builtin_echo(t_minishell *mini, char **cmd_args);

///builtin_env.c
void	builtin_env(t_minishell *mini, char **cmd_args);

///builtin_exit.c
void	builtin_exit(t_minishell *mini, char **cmd_args, int i);
void	check_exit(t_minishell *mini, char **args);

///builtin_export.c
char	*add_declare(char *str);

void	builtin_export(t_minishell *mini, char **cmd_args);

///builtin_export2.c
void	change_env(t_minishell *mini, char *info);
int		check_validity(char *str);
void	check_export(t_minishell *mini, char **cmd_args);

///builtin_pwd.c
void	builtin_pwd(t_minishell *mini, char **cmd_args);

///builtin_unset.c
void	check_unset(t_minishell *mini, char **cmd_args);
void	builtin_unset(t_minishell *mini, char **cmd_args);

/*ERRORS--------------------------------------------------------------*/

///error_handling.c
int		valid_input(char *input);
int		invalid_syntax(char *input);
int		check_quotes(char *input);
int		no_support_operators(char *input);
int		unexpected_tokens(char *input);

///error_handling2.c
int		syntax_error_operator(char *error, char *operator);
int		syntax_error_token(char *error, char metachar, int dup);
int		unexpected_token_redir(char *input, int *i);

//errors.c
void	cd_error2(t_minishell *mini, char **cmd_args);
void	command_error(char *command, char **cmd_args, t_minishell *mini);
void	permission_error(char **cmd_args, t_minishell *mini);
void	file_error(char **cmd_args, t_minishell *mini);
void	is_a_directory(char **cmd_args, t_minishell *mini);

/*EXECUTION--------------------------------------------------------------*/

//executer_builtin.c
void	execute_builtin(t_minishell *mini, char **cmd_args, int i);
void	check_builtin(t_minishell *mini, char **cmd_args);
int		is_builtin(char *name);

//executer_utils.c
int		check_files(char **args, t_minishell *mini);
void	open_pipes(t_minishell *mini);
void	close_pipes(t_minishell *mini);
void	redirections(t_minishell *mini, int i);
void	redirect(int a, int b);

//executer.c
char	*get_command(char *arg, t_minishell *mini);
void	execute_cmd(t_minishell *mini, char *cmd, int i);
void	execute_multi_cmds(t_minishell *mini);
void	execute_single_cmd(t_minishell *mini, char *cmd);
void	executer(t_minishell *mini);

/*PARSING--------------------------------------------------------------*/

//expander.c
char	*expander(char *arg, t_minishell *mini);
///quote_remover.c
char	*remove_quotes(char *arg);

//handle_heredoc.c
void	handle_heredoc(char **cmd_args, t_minishell *mini, int *i, int *count);

//handle_redirs.c
void	shift_redir(char **cmd_args, int *i, int *count);
char	**handle_redirs(t_minishell *mini, char *input);

///input_handler.c
int		read_input(t_minishell *mini);

//split_input.c
int		ft_wordcount_mini(char *str, char c);
char	**split_input(char *s, char c);

//pipe_handler.c
int		ends_with_pipe(char *str);
char	*handle_ending_pipe(char *input);
// + 3 static functions

/*UTILS--------------------------------------------------------------*/

// utils.c
char	quote_value(char c, char quote);
int		isalnumextra(int c);
void	get_exit_sygnal(t_minishell *mini);
void	free_child(t_minishell *mini, char **cmd_args, int i);
void	free_main(t_minishell *mini, int i);

//utils2.c
char	**remove_redirs(char *input);
void	check_heredoc(t_minishell *mini, int i);
char	*add_whitespaces(char *str);
size_t	ft_redir_strlen(char *str);
void	expand_args(char **cmd_args, t_minishell *mini);

//utils3.c
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);

// non_print_off.c
void	ft_terminal_non_print_off(void);
void	ft_modify_attribute(int fd, int flag, int operation);

//shell_lvl_env.c
void	incr_shell_lvl(t_list *data);
void	update_shlvl(t_env *envir);
t_env	*find_shlvl(t_list *data);
char	*get_string(char *name, char *info);
int		get_level(char *info);

//shell_lvl_export.c
char	*get_updated_shlvl(char *str);
char	*get_num_from_str(char *str);

///signals.c
void	signal_default(void);
void	handler_sigint(int sig);
void	handler(int sig);
void	signal_handling(void);
void	term_atributes_echoctl_on(void);

///signals2.c
void ignore_sigquit(void);

// main.c
void	initialize(char **sys_env, t_minishell *mini);
void	clear_all_data(t_minishell mini);

#endif
