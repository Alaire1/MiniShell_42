/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:21:45 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 18:53:51 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*neo;

	i = 0;
	neo = lst;
	while (neo != NULL)
	{
		i++;
		neo = neo -> next;
	}
	return (i);
}

// Parameters lst: The beginning of the list.
// Return value The length of the list
// External functs. None
// Description Counts the number of nodes in a list.