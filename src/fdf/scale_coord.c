/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:04:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/15 20:46:08 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale_coord.h"
#include "parse_map.h"
#include "error_message.h"
#include "utils.h"
#include "graphics.h"
#include <stdio.h>
#include <math.h>

static void	ft_initialize_dim(t_dim *dim, t_coord *coord)
{
	dim->x.min = coord[0].x;
	dim->x.max = coord[0].x;
	dim->y.min = coord[0].y;
	dim->y.max = coord[0].y;
	dim->z.min = coord[0].z;
	dim->z.max = coord[0].z;
	dim->width = 0;
	dim->height = 0;
}

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
	dim.width = abs(dim.x.max - dim.x.min);
	dim.height = abs(dim.y.max - dim.y.min);
	return (dim);
}

static float	ft_scale_to_fit(t_dim max_dims, t_screen screen,
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

static void	ft_to_isometric(t_coord *coord, t_dim max_dims, t_screen screen,
			unsigned int size)
{
	unsigned int	i;
	t_coord_2d		iso;
	t_coord_2d		iso_focus;
	t_view			view;

	i = 0;
	view.angle = 30.0;
	view.window_occ = 0.5;
	view.scale = ft_scale_to_fit(max_dims, screen, view.window_occ);
	iso_focus.x = (int)(max_dims.width - max_dims.height)
		*cos(ft_degree_to_rad(view.angle)) * view.scale / 2.0;
	iso_focus.y = (max_dims.width + max_dims.height)
		*sin(ft_degree_to_rad(view.angle)) * view.scale / 2.0;
	while (i < size)
	{
		iso.x = ((coord[i].x - coord[i].y) * cos(ft_degree_to_rad(view.angle))
				* view.scale) - iso_focus.x + screen.width / 2.0;
		iso.y = ((coord[i].x + coord[i].y) * sin(ft_degree_to_rad(view.angle))
				* view.scale - coord[i].z) - iso_focus.y + screen.height / 2.0;
		coord[i].x = (int)round(iso.x);
		coord[i].y = (int)round(iso.y);
		i++;
	}
}

void	ft_scale_and_center(t_coord *coord, t_screen screen, unsigned int size)
{
	t_dim			max_dims;

	max_dims = ft_get_max_dims(coord, size);
	ft_to_isometric(coord, max_dims, screen, size);
}
