/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:23:27 by skillian          #+#    #+#             */
/*   Updated: 2021/08/13 17:27:16 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
//The memcpy() function copies n bytes from memory area src to memory area dst.
char		*d_buff; //char, weil ich nur einen byte aendern will
const char	*s_buff; // const. weil ich die source nich taendern will
d_buff = dst; //brauche ich weil ich konst nicht aendern kann
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d_buff;
	const char	*s_buff;
	int			i;

	i = 0;
	d_buff = dst;
	s_buff = src;
	while (n > 0)
	{
		d_buff[i] = s_buff[i];
		i++;
		n--;
	}
	return (dst);
}
