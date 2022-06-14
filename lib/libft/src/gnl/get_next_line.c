/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:15:21 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/14 09:53:24 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Function: ft_realloc_and_append
 * ----------------------------
 * Calls ft_my_realloc function, adding 1 byte to the current buffer size,
 * then appends the char passed as parameter to the line.
 */

char	*ft_realloc_and_append(char *line, char c, size_t buffer_size)
{
	line = ft_my_realloc(line, buffer_size, buffer_size + 1);
	if (!line)
		return (0);
	ft_append(line, c);
	return (line);
}

/*
 * Function: ft_read_and_save_line
 * ----------------------------
 * Sets the buffer size to 1 byte, and loops 1 byte at a time until
 * either '\n' is found or the end of the file is found. Each iteration
 * calls ft_realloc_and_append function. Then, the char '\n' is appended.
 */

char	*ft_read_and_save_line(char *line, char c[1], int sz, int fd)
{
	size_t	buffer_size;

	buffer_size = 1;
	while (c[0] != '\n' && sz != 0)
	{
		line = ft_realloc_and_append(line, c[0], buffer_size);
		if (!line)
			return (0);
		sz = read(fd, c, 1);
		if (sz < 0)
			return (0);
		buffer_size++;
	}
	if (c[0] == '\n')
		line = ft_realloc_and_append(line, c[0], buffer_size);
	if (!line)
		return (0);
	return (line);
}

/*
 * Function: get_next_line
 * -----------------------
 * Returns a line read from a file descriptor. 
 * line is declared as static so as to be able to free the memory
 * from the previous call to the function. 
 */

char	*get_next_line(int fd)
{
	char		c[1];
	static char	*line;
	int			sz;

	sz = read(fd, c, 1);
	if (sz <= 0)
		return (0);
	if (!line)
		free(line);
	line = malloc(1);
	if (!line)
		return (0);
	line[0] = '\0';
	line = ft_read_and_save_line(line, c, sz, fd);
	if (!line)
		return (0);
	return (line);
}
