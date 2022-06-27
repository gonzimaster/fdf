/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:23:32 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/27 08:52:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_message_bonus.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils_bonus.h"
#include <fcntl.h>

/*
 * Gets map size and checks that the number of elements in each line is equal.
 * If the map if empty or a line is different, the program is terminated.
 */

static void	ft_get_size(char **line_split, t_size *size, int fd)
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
		close(fd);
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

/*
 * Reads the first line of the file. If there is an error and gnl
 * returns NULL, the fd is closed
 */

static void	ft_read_and_protect_line(char **line, int fd,
			t_map_data *map_data, int read_flag)
{
	*line = get_next_line(fd);
	if (!(*line))
	{
		close(fd);
		if (!read_flag)
			ft_free_all(map_data);
		terminate(ERR_READ);
	}
}

/*
 * Reads the file using gnl, and splits each line using ft_split. If
 * read_flag == 1, it gets the map_size. If read_flag == 0, it sets the
 * coordinates.
 */

static void	ft_read_and_split(int fd, t_map_data *map_data, int read_flag)
{
	char	*line;
	char	**line_split;
	int		y;

	y = 0;
	ft_read_and_protect_line(&line, fd, map_data, read_flag);
	while (line)
	{
		line_split = ft_split(line, ' ');
		free(line);
		if (!line_split)
			ft_protect_line_split(&line_split, fd, read_flag, map_data);
		if (read_flag)
			ft_get_size(line_split, &map_data->size, fd);
		else
			ft_save_coord(line_split, y, map_data->coord);
		ft_free_two_dims(line_split);
		line = get_next_line(fd);
		y++;
	}
}

void	ft_parse_map(char *map_path, t_map_data *map_data, int read_flag)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		if (!read_flag)
			ft_free_all(map_data);
		terminate(ERR_OPEN);
	}
	ft_read_and_split(fd, map_data, read_flag);
	close(fd);
	if (!map_data->size.map)
		terminate(ERR_EMPTY);
}
