/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:09:36 by skillian          #+#    #+#             */
/*   Updated: 2021/09/29 22:51:15 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

static int	sign(const char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
/* converts a string to an integer */
{
	long long int	n;
	int				minus_sign;

	n = 0;
	minus_sign = 1;
	while (space(*str))
		str++;
	if (sign(*str))
	{
		if (*str == '-')
			minus_sign = -1;
		str++;
	}
	while (digit(*str))
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (minus_sign * n);
}
