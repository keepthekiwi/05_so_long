/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:02:47 by skillian          #+#    #+#             */
/*   Updated: 2021/09/29 22:54:35 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
/*	erases the data in the n bytes of the memory
	starting at the location pointed to by s, by writing zeros */
{
	char	*buffer;

	buffer = s;
	while (n > 0)
	{
		*buffer = 0;
		buffer++;
		n--;
	}
}
