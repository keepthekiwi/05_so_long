/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:27:10 by skillian          #+#    #+#             */
/*   Updated: 2021/09/20 14:19:55 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
/* (malloc) returns a substring from the string s, from start to len */
{
	int		i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	sub = malloc(len + 1 * sizeof(*sub));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		sub[i] = s[i + start];
		i++;
		len--;
	}
	sub[i] = 0;
	return (sub);
}
