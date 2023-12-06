/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:21:54 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 18:54:57 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*poi;

	poi = str;
	if (str[0] == '\0' && c == 0)
		return ((char *)str);
	if (!*str)
		return (NULL);
	while (*str)
		str++;
	while (str >= poi)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
