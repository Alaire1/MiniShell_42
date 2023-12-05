/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:29:28 by npavelic          #+#    #+#             */
/*   Updated: 2023/12/05 16:25:11 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char c;

//     printf("Enter a character: ");
//     scanf("%c", &c);

//     if (ft_isprint(c) == 0)
//          printf("%c is not printable.", c);
//     else
//          printf("%c is printable.", c);

//     return 0;
// }