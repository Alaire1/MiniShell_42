/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:03:08 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 18:54:03 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s = src;

	d = dest;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else if (s < d)
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dest);
}
