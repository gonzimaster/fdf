/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:41:52 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/17 08:29:19 by ogonzale         ###   ########.fr       */
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
	t_coord			*coord;
	t_size			size;

	if (argc != 2)
		terminate(ERR_ARGS);
	size.line = 0;
	size.map = 0;
	ft_get_map_size(argv[1], &size);
	coord = NULL;
	ft_allocate_coord(&coord, size);
	ft_parse_map(argv[1], coord);
	ft_handle_graphics(coord, size);
	free(coord);
	return (0);
}
