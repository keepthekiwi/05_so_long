/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:23:58 by skillian          #+#    #+#             */
/*   Updated: 2021/09/24 18:10:34 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
/* function returns a pointer to a new string
which is a duplicate of the string s */
{
	size_t		strl;
	char		*dup;
	const char	*s_buff;
	int			i;

	if (!s1)
		return (NULL);
	strl = ft_strlen(s1) + 1;
	dup = (char *)malloc(strl);
	if (dup == 0)
		return (0);
	else
	{
		i = 0;
		s_buff = s1;
		while (strl > 0)
		{
			dup[i] = s_buff[i];
			i++;
			strl--;
		}
		return (dup);
	}
}

char	*ft_strjoin(char *s1, char *s2)
/* (malloc) and adds s2 to s1) */
{
	char	*join;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	join = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*join));
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2 != NULL && s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	return (join);
}

int	ft_strchr(const char *s, int c)
/* returns a the index (int) to the character */
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (i);
		else
			i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
/* (malloc) returns a substring from the string s, from start to len */
{
	int		i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
