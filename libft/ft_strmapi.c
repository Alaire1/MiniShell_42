/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:11:41 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 18:54:47 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*reza;
	unsigned int		i;
	unsigned int		new_l;

	i = 0;
	if ((s == 0) || (f == 0))
		return (0);
	new_l = ft_strlen (s) + 1;
	reza = (char *) malloc (sizeof(char) * new_l);
	if (reza == 0)
		return (0);
	reza [new_l - 1] = '\0';
	while (s[i])
	{
		reza[i] = f (i, s[i]);
		i++;
	}
	return (reza);
}
