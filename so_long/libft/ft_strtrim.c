/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:54:23 by skillian          #+#    #+#             */
/*   Updated: 2021/08/15 15:21:25 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_front(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static int	ft_back(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strchr(set, s1[len - i - 1]) != NULL)
		i++;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = ft_front(s1, set);
	back = ft_back(s1, set);
	if (front >= back)
		return (ft_strdup(""));
	trim = malloc((back - front + 1) * sizeof(*trim));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, (s1 + front), (back - front + 1));
	return (trim);
}
