/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:27:58 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 10:02:40 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"
#include "error_message.h"
#include "libft.h"
#include "get_next_line.h"
#include "utils.h"
#include <stdio.h>

static unsigned int	ft_save_coord(char **line_split, int y, t_coord coord)
{
	static unsigned int	i;
	int					x;

	x = 0;
	while (line_split[x])
	{
		coord[i].x = x;
		coord[i].y = y;
		coord[i].z = ft_atoi(line_split[x]);
		x++;
		i++;
	}
	return (i);
}

static void	ft_get_map_content(int fd, t_list **lst)
{
	char			*line;
	char			**line_split;
	int				y;
	t_coord			coord;
	unsigned int	i;

	y = 0;
	*lst = NULL;
	i = 0;
	coord = malloc(sizeof(t_coord));;
	line = get_next_line(fd);
	if (!line)
		terminate(ERR_READ);
	while (line)
	{
		line_split = ft_split(line, ' ');
		free(line);
		if (!line_split)
			terminate(ERR_READ);
		i = ft_save_coord(line_split, y, coord);
		ft_free_two_dims(line_split);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	unsigned int	j = -1;
	while (++j < i)
		printf("(%d %d %d) ", coord[j].x, coord[j].y, coord[j].z);
	free(coord);
}

void	ft_parse_map(char *map_path)
{
	int	fd;
	t_list	*lst;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN);
	ft_get_map_content(fd, &lst);
	close(fd);
}
