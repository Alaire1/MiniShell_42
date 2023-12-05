

NAME		= minishell
LIBFT		= libft.a

#----------DIRS----------#
SRCDIR = ./srcs/
LIBFTDIR = ./libft/
INCDIR = ./includes/

#----------SRCS----------#
SRC =	env_utils \
		env \
		error_handling \
		error_handling2 \
		errors \
		executer_builtin \
		executer_utils \
		executer \
		expander \
		export \
		handle_heredoc \
		handle_redirs \
		input_handler \
		main \
		quote_remover \
		signals \
		split_meta \
		utils \
		utils2 \
		utils3 \
		builtins/builtin_cd \
		builtins/builtin_echo \
		builtins/builtin_env \
		builtins/builtin_exit \
		builtins/builtin_export \
		builtins/builtin_export2 \
		builtins/builtin_pwd \
		builtins/builtin_unset \
		non_print_off


SRCS = $(addprefix ${SRCDIR}, $(addsuffix .c, ${SRC}))

#--------COMMANDS--------#
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)  -I /usr/local/Cellar/readline/8.1.1/include/ -g -fsanitize=address
EXTRA = -lreadline 
AR = ar rcs
RM = rm -rf
MAKEFLAGS += --no-print-directory

#----------OBJS----------#
OBJS = ${SRCS:.c=.o}

#---------COLORS---------#
GREEN       =   \033[0;32m



.c.o:
	@mkdir -p bin/$(dir $<)
	@$(CC) $(CFLAGS) -c $< -o bin/$*.o

all: 		$(NAME)
	@echo "$(GREEN)[Compilation complete]"

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
