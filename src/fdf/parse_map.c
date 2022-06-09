/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:27:58 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 12:10:43 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "error_message.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <stdio.h>

static void	ft_save_coord(char **line_split, int y, t_coord *coord,
			unsigned int *i)
{
	int					x;
	t_coord				tmp;

	tmp = *coord;
	x = 0;
	while (line_split[x])
	{
		tmp[*i].x = x;
		tmp[*i].y = y;
		tmp[*i].z = ft_atoi(line_split[x]);
		x++;
		(*i)++;
	}
	*coord = tmp;
}

static void	ft_get_map_content(int fd, t_coord *coord, unsigned int *map_size)
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
		ft_save_coord(line_split, y, coord, map_size);
		ft_free_two_dims(line_split);
		line = get_next_line(fd);
		y++;
	}
	free(line);
}

void	ft_parse_map(char *map_path, t_coord *coord, unsigned int *map_size)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN);
	ft_get_map_content(fd, coord, map_size);
	close(fd);
}
