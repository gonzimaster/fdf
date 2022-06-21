/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:04:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/21 11:53:51 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale_coord.h"
#include "utils.h"
#include "libft.h"
#include <math.h>

static t_dim	ft_get_max_dims(t_coord *coord, unsigned int size)
{
	unsigned int	i;
	t_dim			dim;

	i = 0;
	ft_initialize_dim(&dim, coord);
	while (i < size)
	{
		if (coord[i].x < dim.x.min)
			dim.x.min = coord[i].x;
		if (coord[i].y < dim.y.min)
			dim.y.min = coord[i].y;
		if (coord[i].z < dim.z.min)
			dim.z.min = coord[i].z;
		if (coord[i].x > dim.x.max)
			dim.x.max = coord[i].x;
		if (coord[i].y > dim.y.max)
			dim.y.max = coord[i].y;
		if (coord[i].z > dim.z.max)
			dim.z.max = coord[i].z;
		i++;
	}
	dim.width = ft_abs_value(dim.x.max - dim.x.min);
	dim.height = ft_abs_value(dim.y.max - dim.y.min);
	dim.altitude = ft_abs_value(dim.z.max - dim.z.min);
	return (dim);
}

/*
 * The limiting scale factor is selected.
 */

float	ft_scale_to_fit(t_dim max_dims, t_screen screen,
				float occ_screen)
{
	float			scale_factor;
	float			scale_x_factor;
	float			scale_y_factor;

	scale_x_factor = max_dims.width / (float)screen.width;
	scale_y_factor = max_dims.height / (float)screen.height;
	if (scale_x_factor > scale_y_factor)
		scale_factor = occ_screen / scale_x_factor;
	else
		scale_factor = occ_screen / scale_y_factor;
	return (scale_factor);
}

/*
 * Isometric transform: 
 * 	x_iso = ((x - y) * cos(view_angle) * scale_factor) - x_iso_f + width / 2
 * 	y_iso = ((x + y) * sin(view_angle) * scale_factor - z * z_scale_factor)
 * 			- y_iso_f + height / 2
 * 	Where x_iso_f and y_iso_f are the isometric transform of the center of the
 * 	screen.
 */

static void	ft_to_isometric(t_map_data map_data, t_screen screen)
{
	unsigned int	i;
	t_coord_2d		iso;
	t_coord_2d		iso_focus;
	t_view			view;

	i = 0;
	ft_initialize_view(map_data.max_dims, screen, &view);
	iso_focus.x = (int)(map_data.max_dims.width - map_data.max_dims.height)
		*cos(ft_degree_to_rad(view.angle)) * view.scale / 2.0;
	iso_focus.y = (map_data.max_dims.width + map_data.max_dims.height)
		*sin(ft_degree_to_rad(view.angle)) * view.scale / 2.0;
	while (i < map_data.size.map)
	{
		iso.x = ((map_data.coord[i].x - map_data.coord[i].y)
				* cos(ft_degree_to_rad(view.angle))
				* view.scale) - iso_focus.x + screen.width / 2.0;
		iso.y = ((map_data.coord[i].x + map_data.coord[i].y)
				* sin(ft_degree_to_rad(view.angle)) * view.scale
				- map_data.coord[i].z * view.z_scale) - iso_focus.y
			+ screen.height / 2.0;
		map_data.coord[i].x = (int)round(iso.x);
		map_data.coord[i].y = (int)round(iso.y);
		i++;
	}
}

void	ft_to_projection(t_map_data *map_data, t_screen screen)
{
	map_data->max_dims = ft_get_max_dims(map_data->coord, map_data->size.map);
	ft_to_isometric(*map_data, screen);
}
