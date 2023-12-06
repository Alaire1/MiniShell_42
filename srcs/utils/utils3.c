/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:50:12 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 19:12:13 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_putstr(char *str) {
	write(1, str, ft_strlen(str));
}

void	ft_putchar(char c) {
	write(1, &c, 1);
}