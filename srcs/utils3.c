#include "../includes/minishell.h"

void ft_putstr(char *str) {
	write(1, str, ft_strlen(str));
}

void	ft_putchar(char c) {
	write(1, &c, 1);
}