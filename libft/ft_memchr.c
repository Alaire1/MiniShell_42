/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:44:11 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 18:53:56 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t		i;
	const char	*searched_string = ptr;

	i = 0;
	while (i != num)
	{
		if ((unsigned char)searched_string[i] == (unsigned char)value)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
