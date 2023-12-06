/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:24:46 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/06 18:52:51 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
void	*ft_calloc(size_t num, size_t size)
{
	void	*finpo;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	finpo = malloc (num * size);
	if (finpo)
		ft_bzero (finpo, num * size);
	return (finpo);
}
