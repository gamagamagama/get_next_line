/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavorni <mgavorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:33:10 by mgavorni          #+#    #+#             */
/*   Updated: 2024/01/23 15:41:52 by mgavorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *string_buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (string_buffer[i] && string_buffer[i] != '\n')
		i++;
	if (!string_buffer[i])
	{
		free(string_buffer);
		return (NULL);
	}
	next = malloc((ft_strlen(string_buffer) - i + 1) * sizeof(char));
	i++;
	j = 0;
	while (string_buffer[i])
	{
		next[j++] = string_buffer[i++];
	}
	next[j] = '\0';
	free(string_buffer);
	return (next);
}

char	*ft_line(char *string_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (string_buffer[i] == '\0')
		return (NULL);
	while (string_buffer[i] && string_buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (line == 0)
		return (NULL);
	i = 0;
	while (string_buffer[i] && string_buffer[i] != '\n')
	{
		line[i] = string_buffer[i];
		i++;
	}
	if (string_buffer[i] == '\n')
	{
		line[i] = string_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_reader(int fd, char *result)
{
	char	*string_buffer;
	int		byte;

	string_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!string_buffer)
		return (NULL);
	byte = 1;
	while ((!ft_strrchr(result, '\n')) && byte != 0)
	{
		byte = read(fd, string_buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(string_buffer);
			return (NULL);
		}
		string_buffer[byte] = '\0';
		result = ft_strjoin(result, string_buffer);
	}
	free(string_buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*string_buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > FOPEN_MAX)
		return (NULL);
	string_buffer[fd] = ft_reader(fd, string_buffer[fd]);
	if (!string_buffer[fd])
		return (NULL);
	line = ft_line(string_buffer[fd]);
	string_buffer[fd] = ft_next(string_buffer[fd]);
	return (line);
}
