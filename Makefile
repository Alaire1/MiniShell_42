

NAME		= minishell
LIBFT		= libft.a

SRCDIR = ./srcs/
LIBFTDIR = ./libft/
INCDIR = ./includes/

SRC =	env/env_utils \
		env/env \
		errors/error_handling \
		errors/error_handling2 \
		errors/errors \
		execution/executer_builtin \
		execution/executer_utils \
		execution/executer \
		parsing/expander \
		env/export \
		execution/handle_heredoc \
		execution/handle_redirs \
		parsing/input_handler \
		main \
		parsing/quote_remover \
		utils/signals \
		parsing/split_meta \
		utils/utils \
		utils/utils2 \
		utils/utils3 \
		builtins/builtin_cd \
		builtins/builtin_echo \
		builtins/builtin_env \
		builtins/builtin_exit \
		builtins/builtin_export \
		builtins/builtin_export2 \
		builtins/builtin_pwd \
		builtins/builtin_unset \
		utils/non_print_off \
		utils/new_file \


SRCS = $(addprefix ${SRCDIR}, $(addsuffix .c, ${SRC}))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCDIR)  -I /usr/local/Cellar/readline/8.1.1/include/ -g -fsanitize=address
EXTRA = -lreadline 
AR = ar rcs
RM = rm -rf
MAKEFLAGS += --no-print-directory

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
