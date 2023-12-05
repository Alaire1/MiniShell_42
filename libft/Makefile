
NAME = libft.a

#----------DIRS----------#
DIR = ./srcs/

SRCS =	ft_abs.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_free_split.c \
	ft_getlength.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isnumeric.c \
	ft_isprint.c \
	ft_isquote.c \
	ft_isspace.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_max.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_min.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_utoa.c \
	ft_wordcount.c 

SRC = $(addprefix ${DIR}, ${SRCS})

#--------COMMANDS--------#
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

OBJ = ${SRC:.c=.o}

YELLOW	=	\033[0;33m

#---------RULES---------#
.c.o:
		@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: 		$(NAME)

$(NAME): 	$(OBJ)
		@$(AR) $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)

fclean: 	clean
		@$(RM) $(NAME)

re: 		fclean all
