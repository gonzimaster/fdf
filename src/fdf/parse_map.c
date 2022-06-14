/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:27:58 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/14 17:54:07 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "error_message.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <stdio.h>

static void	ft_save_coord(char **line_split, int y, t_coord *coord,
			t_size *size)
{
	int					x;
	unsigned int		last_line_size;

	x = 0;
	last_line_size = size->line;
	size->line = 0;
	while (line_split[x])
	{
		if (line_split[x][0] != '\n')
		{
			coord[size->map].x = x;
			coord[size->map].y = y;
			coord[size->map].z = ft_atoi(line_split[x]);
			(size->map)++;
			(size->line)++;
		}
		x++;
	}
	if (size->line != last_line_size && last_line_size != 0)
		ft_putendl_fd(ERR_LINE, 1);
}

static void	ft_get_map_content(int fd, t_coord *coord, t_size *size)
{
	char			*line;
	char			**line_split;
	int				y;

	y = 0;
	line = get_next_line(fd);
	if (!line)
		terminate(ERR_READ);
	while (line)
	{
		line_split = ft_split(line, ' ');
		free(line);
		if (!line_split)
			terminate(ERR_READ);
		ft_save_coord(line_split, y, coord, size);
		line = get_next_line(fd);
		y++;
	}
	free(line);
}

void	ft_parse_map(char *map_path, t_coord *coord, t_size *size)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN);
	ft_get_map_content(fd, coord, size);
	close(fd);
}
