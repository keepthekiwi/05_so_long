/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:02:58 by skillian          #+#    #+#             */
/*   Updated: 2021/11/25 20:06:29 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Haystack Needle
Function locates the first occurrence of the null-terminated string needle
in the string haystack, where not more than len characters are searched.
n = n + i; n wieder zuruecksetzen, da wenn abc gesucht und abe 
dann muss ich ja zur naechsten stelle, aber n muss dann wieder hoeher sein
*/
char	*ft_strnstr(const char	*s_long, const char *s_short, size_t n)
{
	size_t	i;

	if (ft_strlen(s_short) == 0)
		return ((char *)s_long);
	i = 0;
	while (n > 0 && i < n && *s_long)
	{
		while (n > 0 && s_long[i] == s_short[i] && s_short[i] && s_long[i])
		{
			i++;
			n--;
		}
		if (s_short[i] == '\0')
			return ((char *)s_long);
		else
		{
			n = n + i;
			i = 0;
			s_long++;
			n--;
		}
	}
	return (NULL);
}
