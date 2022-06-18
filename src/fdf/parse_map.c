/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:23:32 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/18 09:56:01 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "error_message.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <stdio.h>

static void	ft_get_size(char **line_split, t_size *size)
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
	{
		ft_free_two_dims(line_split);
		terminate(ERR_LINE);
	}
}

static void	ft_save_coord(char **line_split, int y, t_coord *coord)
{
	int			x;
	static int	i;

	x = 0;
	while (line_split[x])
	{
		if (line_split[x][0] != '\n')
		{
			coord[i].x = x;
			coord[i].y = y;
			coord[i].z = ft_atoi(line_split[x]);
			i++;
		}
		x++;
	}
}

static void	ft_read_and_split(int fd, t_size *size, t_coord *coord,
			int read_flag)
{
	char	*line;
	char	**line_split;
	int		y;

	y = 0;
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
			terminate(ERR_SPLIT);
		}
		if (read_flag)
			ft_get_size(line_split, size);
		else
			ft_save_coord(line_split, y, coord);
		ft_free_two_dims(line_split);
		line = get_next_line(fd);
		y++;
	}
}

void	ft_parse_map(char *map_path, t_size *size, t_coord *coord,
			int read_flag)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN);
	if (read_flag)
	{
		ft_read_and_split(fd, size, coord, read_flag);
		if (!size->map)
			terminate(ERR_EMPTY);
	}
	else
		ft_read_and_split(fd, size, coord, read_flag);
	close(fd);
}
