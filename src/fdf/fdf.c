/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:41:52 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/18 09:41:08 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_message.h"
#include "parse_map.h"
#include "utils.h"
#include "graphics.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_map_data	map_data;
	int			read_flag;

	read_flag = 1;
	if (argc != 2)
		terminate(ERR_ARGS);
	map_data.size.line = 0;
	map_data.size.map = 0;
	map_data.coord = NULL;
	ft_parse_map(argv[1], &map_data.size, map_data.coord, read_flag);
	read_flag = 0;
	ft_allocate_coord(&map_data.coord, map_data.size);
	ft_parse_map(argv[1], &map_data.size, map_data.coord, read_flag);
	ft_handle_graphics(map_data);
	free(map_data.coord);
	return (0);
}
