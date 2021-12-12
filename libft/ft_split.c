/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:21:09 by skillian          #+#    #+#             */
/*   Updated: 2021/08/15 18:52:32 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	int main()
	{
	ft_split("UNDEUXTROIS_", '_');
	return(0);
	}

	size_t	ft_strlen(const char *str)
	{
		int i = 0;

		while (str[i] != '\0')
		{
			i++;
		}
		return(i);
	}

arr[x] = malloc(counter +1);
		if (arr[x] == NULL) //protekten
*/
static int	delicut(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	*free_arr(char **arr, int x)
{
	while (x >= 0)
	{
		free(arr[x]);
		x--;
	}	
	free(arr);
	return (NULL);
}

static int	ms_word(const char **s, int counter, char c)
{
	while (**s && **s == c)
		(*s)++;
	while (**s && **s != c)
	{
		counter++;
		(*s)++;
	}
	return (counter);
}

static char	**scan_words(char const *s, char **arr, char c, int elements)
{
	int	counter;
	int	j;
	int	x;

	counter = 0;
	x = 0;
	while (*s && elements)
	{
		counter = ms_word(&s, counter, c);
		s = s - counter;
		arr[x] = malloc(counter + 1);
		if (arr[x] == NULL)
			return (free_arr(arr, x));
		j = 0;
		while (counter > 0)
		{
			arr[x][j++] = *s++;
			counter--;
		}
		arr[x++][j] = '\0';
		elements--;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		elements;

	if (s == NULL)
		return (NULL);
	arr = NULL;
	elements = delicut(s, c);
	arr = ft_calloc((elements + 1), sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = scan_words(s, arr, c, elements);
	return (arr);
}
