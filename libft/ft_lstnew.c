/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:12:59 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 18:53:49 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_list == NULL)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}

// Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.

// typedef struct s_list
// {
// void *content;
// struct s_list *next;
// } t_list;
