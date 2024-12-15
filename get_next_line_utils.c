/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavorni <mgavorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:32:04 by mgavorni          #+#    #+#             */
/*   Updated: 2024/01/23 16:06:53 by mgavorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *result)
{
	size_t	i;

	i = 0;
	if (!result)
		return (0);
	while (result[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(char *result, int c)
{
	int	i;

	i = 0;
	if (!result)
		return (0);
	if (c == '\0')
		return ((char *)&result[ft_strlen(result)]);
	while (result[i])
	{
		if (result[i] == (char)c)
		{
			return ((char *)&result[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *result, char *string_buffer)
{
	size_t	i;
	size_t	j;
	char	*new_s;

	if (!(result))
	{
		result = (char *)malloc(1 * sizeof(char));
		result[0] = '\0';
	}
	if (!result || !string_buffer)
		return (NULL);
	new_s = (char *)malloc(((ft_strlen(result))
				+ (ft_strlen(string_buffer)) + 1) * (sizeof(char)));
	if (!new_s)
		return (NULL);
	i = -1;
	j = 0;
	if (result)
		while (result[++i] != '\0')
			new_s[i] = result[i];
	while (string_buffer[j] != '\0')
		new_s[i++] = string_buffer[j++];
	new_s[ft_strlen(result) + ft_strlen(string_buffer)] = '\0';
	free(result);
	return (new_s);
}
