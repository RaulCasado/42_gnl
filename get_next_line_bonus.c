/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:32:44 by racasado          #+#    #+#             */
/*   Updated: 2024/10/05 11:35:32 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*failed_s1(char *s1)
{
	s1 = malloc(1);
	if (!s1)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = failed_s1(s1);
		if (!s1)
			return (NULL);
	}
	joined_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		joined_str[i++] = s2[j++];
	joined_str[i] = '\0';
	free(s1);
	return (joined_str);
}

char	*failed(char *buffer, char *remainder)
{
	if (buffer)
		free(buffer);
	if (remainder)
	{
		free(remainder);
		remainder = NULL;
	}
	return (NULL);
}

char	*read_and_update(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (failed(buffer, remainder));
		if (bytes_read >= 0)
			buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (failed(buffer, remainder));
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_and_update(fd, remainder[fd]);
	if (!remainder[fd] || ft_strlen(remainder[fd]) == 0)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	line = my_get_line(remainder[fd]);
	remainder[fd] = update_remainder(remainder[fd]);
	return (line);
}
