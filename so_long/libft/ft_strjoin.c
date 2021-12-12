/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:25:05 by skillian          #+#    #+#             */
/*   Updated: 2021/09/29 22:45:35 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	Speicher freimachen
	(*join)); //hier mit * da ich Value moechte nicht adresse
	malloc protection
	str kombinieren
	join auf Stelle 0/Anfang und Ausgeben
*/
char	*ft_strjoin(char const *s1, char const *s2)
/* (malloc) and adds s2 to s1 */
{
	char	*join;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	join = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*join));
	if (join == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = 0;
	return (join);
}
