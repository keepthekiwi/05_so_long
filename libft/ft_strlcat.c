/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:29:27 by skillian          #+#    #+#             */
/*   Updated: 2021/08/15 18:52:56 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	counter;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	counter = 0;
	if (dstlen >= n)
		return (srclen + n);
	while (counter + dstlen < n - 1 && src[counter])
	{
		dst[dstlen + counter] = src[counter];
		counter++;
	}
	dst[dstlen + counter] = '\0';
	return (dstlen + srclen);
}
