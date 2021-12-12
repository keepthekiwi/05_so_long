/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:42:47 by skillian          #+#    #+#             */
/*   Updated: 2021/08/15 17:11:15 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* also will die diffrence haben, sobald ein
bichstabe unterscheidlich ist un den gebe ich dann aus(also die zahl)
//unsigned weil ich ja nur einzelne aski werte anschaue??
und daher keinen negativen bereich brauche
// will den value und nciht die addresse vergelichen und daher *
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*buffer1;
	const unsigned char	*buffer2;

	buffer1 = s1;
	buffer2 = s2;
	while (n > 0)
	{
		if (*buffer1 != *buffer2)
			return (*buffer1 - *buffer2);
		buffer1++;
		buffer2++;
		n--;
	}
	return (0);
}
