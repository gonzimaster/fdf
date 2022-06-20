/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:41:52 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/20 10:03:27 by ogonzale         ###   ########.fr       */
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

	if (argc != 2)
		terminate(ERR_ARGS);
	ft_init_map_data(&map_data);
	ft_parse_map(argv[1], &map_data.size, map_data.coord, 1);
	ft_allocate_coord(&map_data.coord, map_data.size);
	ft_parse_map(argv[1], &map_data.size, map_data.coord, 0);
	ft_handle_graphics(map_data);
	return (0);
}
