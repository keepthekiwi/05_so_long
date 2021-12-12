/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:57:22 by skillian          #+#    #+#             */
/*   Updated: 2021/12/12 14:21:29 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
/*	check if it is possible
	fill buffer accurs
		read file
		combine it with old rem
	check for the next_line \n */
{
	int			bytes;
	char		*new_buf;
	static char	*buffer;

	bytes = TRUE;
	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	new_buf = malloc((BUFFER_SIZE + 1) * sizeof(*new_buf));
	if (new_buf == NULL)
		return (NULL);
	while (bytes > 0 && ft_strchr(buffer, '\n') == -1)
	{
		bytes = read(fd, new_buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		new_buf[bytes] = '\0';
		buffer = ft_strjoin(buffer, new_buf);
	}
	ft_free((void *)&new_buf);
	return (search_n(&buffer, bytes));
}

char	*search_n(char **buffer, int bytes)
/* look if \n is in there */
{
	int		n_position;
	char	*GNL;
	char	*joint;

	n_position = ft_strchr(*buffer, '\n');
	joint = *buffer;
	if (n_position >= 0)
	{
		GNL = ft_substr(joint, 0, n_position + 1);
		*buffer = ft_substr(joint, n_position + 1, ft_strlen(joint));
		free (joint);
		return (GNL);
	}
	else
	{
		if (bytes == 0)
		{
			GNL = ft_strdup(*buffer);
			ft_free((void *)buffer);
			if (ft_strlen(GNL) == 0)
				ft_free((void *)&GNL);
			return (GNL);
		}
		return (0);
	}
}

void	*ft_free(void **pointer)
{
	free(*pointer);
	*pointer = NULL;
	return (NULL);
}
