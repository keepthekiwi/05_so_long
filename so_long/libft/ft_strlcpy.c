/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:13:47 by skillian          #+#    #+#             */
/*   Updated: 2021/08/15 15:13:25 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The strlcpy() function copies up to size - 1 characters
from the NUL-terminated string src to dst
NUL-terminating the result. 
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (src == 0 || dst == 0)
		return (0);
	if (n == 0)
		return (ft_strlen(src));
	i = 0;
	while (n - 1 > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
