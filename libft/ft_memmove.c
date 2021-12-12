/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:12:41 by skillian          #+#    #+#             */
/*   Updated: 2021/08/13 17:29:29 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
//brauche buffer wegen void pointer. void pointer kann ich nie veraendern!!
char *d_buf; 			char, weil ich nur einen byte aendern will
const char	*s_buf; 	const. weil ich die source nicht aendern will
if (dst < src)			copy von vorne
i = n - 1;				copy von hinten if (dst > src) = else
// https://stackoverflow.com/questions/3572309/memmove-implementation-in-c
*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d_buf;
	const char	*s_buf;
	int			i;

	d_buf = dst;
	s_buf = src;
	if (dst < src)
		return (ft_memcpy(dst, (void *)src, n));
	else
	{
		i = n - 1;
		while (n > 0)
		{
			d_buf[i] = s_buf[i];
			i--;
			n--;
		}
	}	
	return (dst);
}
