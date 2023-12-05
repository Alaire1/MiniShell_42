/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:15:55 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/05 16:26:45 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *str1)
{
	char	*reza;
	size_t	l;

	l = ft_strlen(str1) + 1;
	reza = malloc (l);
	if (reza == 0)
		return (0);
	return ((char *) ft_memcpy (reza, str1, l));
}
