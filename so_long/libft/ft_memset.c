/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:19:24 by skillian          #+#    #+#             */
/*   Updated: 2021/09/29 22:56:26 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The memset() function fills the first n bytes of the memory
	area pointed to by s with the constant byte c.
VOID Ptr kann ich nicht veraendern
	weil c nichts damit anzufangen weiss */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*buffer;
	int		i;

	buffer = s;
	i = 0;
	while (n > 0)
	{
		buffer[i] = c;
		i++;
		n--;
	}
	return (s);
}
