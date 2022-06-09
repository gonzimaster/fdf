/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:41:52 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/09 10:39:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_message.h"
#include "parse_map.h"
#include "utils.h"
#include <stdio.h>

static void	ft_allocate_coord(t_coord *coord)
{
	*coord = malloc(sizeof(t_coord));
	if (!(*coord))
		terminate(ERR_MEM);
}

int	main(int argc, char *argv[])
{
	t_coord			coord;
	unsigned int	map_size;

	if (argc != 2)
		terminate(ERR_ARGS);
	map_size = 0;
	ft_allocate_coord(&coord);
	ft_parse_map(argv[1], &coord, &map_size);
	free(coord);
	return (0);
}
