/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:10:05 by skillian          #+#    #+#             */
/*   Updated: 2021/08/15 17:48:26 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
const char *buffer = s; // brauche ich
	da VOID und CONST PTR s ist und somit nicht aenderbar
n wird nach gewuenshcter laenge eingegeben 
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*buffer;

	buffer = s;
	while (n > 0)
	{
		if (*buffer == (unsigned char)c)
			return ((void *)buffer);
		buffer++;
		n--;
	}
	return (0);
}
