

NAME		= minishell
LIBFT		= libft.a

CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)  -I /usr/local/Cellar/readline/8.1.1/include/ -g 
EXTRA = -lreadline 
AR = ar rcs
RM = rm -rf
MAKEFLAGS += --no-print-directory

SRCDIR = ./srcs/
LIBFTDIR = ./libft/
INCDIR = ./includes/

SRC =	builtins/builtin_cd \
		builtins/builtin_echo \
		builtins/builtin_env \
		builtins/builtin_exit \
		builtins/builtin_export \
		builtins/builtin_export2 \
		builtins/builtin_pwd \
		builtins/builtin_unset \
		env/env_utils \
		env/env \
		env/export \
		errors/error_handling \
		errors/error_handling2 \
		errors/errors \
		execution/executer_builtin \
		execution/executer_utils \
		execution/executer \
		execution/handle_heredoc \
		execution/handle_redirs \
		parsing/input_handler \
		parsing/pipe_handler \
		parsing/expander \
		parsing/quote_remover \
		parsing/split_input \
		utils/signals \
		utils/non_print_off \
		utils/shell_lvl_env \
		utils/shell_lvl_export\
		utils/utils \
		utils/utils2 \
		utils/utils3 \
		main \


SRCS = $(addprefix ${SRCDIR}, $(addsuffix .c, ${SRC}))
OBJS = ${SRCS:.c=.o}

GREEN       =   \033[0;32m
RESET       =   \033[0m	

.c.o:
	@mkdir -p bin/$(dir $<)
	@$(CC) $(CFLAGS) -c $< -o bin/$*.o

all: 		$(NAME)
	@echo "$(GREEN)Program \"$(NAME)\" compiled successfully ✅$(RESET)"

$(LIBFT):
			@cd $(LIBFTDIR) && $(MAKE)

$(NAME): 	$(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS:%=bin/%) $(LIBFTDIR)$(LIBFT) -L /usr/local/Cellar/readline/8.1.1/lib/ $(EXTRA) -o $(NAME)

clean:
			@$(RM) bin
			@cd $(LIBFTDIR) && $(MAKE) clean

fclean: 	clean
			@$(RM) $(NAME) $(BONUS)
			@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all
