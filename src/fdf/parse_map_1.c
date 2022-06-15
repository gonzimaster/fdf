/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:23:32 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/15 12:10:42 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "error_message.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <stdio.h>

static void ft_get_size(char **line_split, t_size *size)
{
	int				x;
	unsigned int	last_line_size;

	x = 0;
	last_line_size = size->line;
	size->line = 0;
	while (line_split[x])
	{
		if (line_split[x][0] != '\n')
		{
			(size->map)++;
			(size->line)++;
		}
		x++;
	}
	if (size->line != last_line_size && last_line_size != 0)
		ft_putendl_fd(ERR_LINE, 1);
}

static void	ft_read_and_split(int fd, t_size *size)
{
	char	*line;
	char	**line_split;

	line = get_next_line(fd);
	if (!line)
		terminate(ERR_READ);
	while (line)
	{
		line_split = ft_split(line, ' ');
		free(line);
		if (!line_split)
		{
			ft_free_two_dims(line_split);
			terminate(ERR_READ);
		}
		ft_get_size(line_split, size);
		ft_free_two_dims(line_split);
		line = get_next_line(fd);
	}
	free(line);
}

void	ft_get_map_size(char *map_path, t_size *size)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN);
	ft_read_and_split(fd, size);
	close(fd);
}
