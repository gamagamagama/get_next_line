/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgavorni <mgavorni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:55:20 by mgavorni          #+#    #+#             */
/*   Updated: 2024/01/23 16:12:49 by mgavorni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  2

# endif

size_t	ft_strlen(char *result);
char	*ft_strrchr(char *result, int c);
char	*ft_strjoin(char *result, char *string_buffer);
char	*ft_next(char *string_buffer);
char	*ft_line(char *string_buffer);
char	*ft_reader(int fd, char *result);
char	*get_next_line(int fd);

#endif