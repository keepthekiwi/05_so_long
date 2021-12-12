/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 21:01:28 by skillian          #+#    #+#             */
/*   Updated: 2021/09/29 22:55:49 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
return (1);	// bei 0 brauche ich nur einen Seicherplatz (+1Nullterm)
if (n < 0)		// Sppeicherplatz malloc fuer Minuszeichen */
static int	ft_digitcounter(int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_digitcounter (nbr);
	s = malloc ((len + 1) * sizeof(*s));
	if (s == NULL)
		return (NULL);
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		s[0] = '0';
	s[len] = '\0';
	len--;
	while (nbr > 0)
	{
		s[len] = nbr % 10 + 48;
		len--;
		nbr = nbr / 10;
	}
	return (s);
}
