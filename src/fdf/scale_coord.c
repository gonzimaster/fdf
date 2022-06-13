/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:04:17 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/13 16:29:20 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale_coord.h"
#include "parse_map.h"
#include "libft.h"
#include "error_message.h"
#include "utils.h"
#include "graphics.h"
#include <stdio.h>
#include <math.h>

static t_dim	ft_get_max_dims(t_coord *coord, unsigned int size)
{
	unsigned int	i;
	t_dim			max_dims;
	t_lim_dim		lim_coord;
	t_coord			*tmp;

	tmp = coord;
	i = 0;
	lim_coord.min_x = 1920;
	lim_coord.max_x = 0;
	lim_coord.min_y = 1080;
	lim_coord.max_y = 0;
	max_dims.width = 0;
	max_dims.height = 0;
	max_dims.min_elevation = 0;
	max_dims.max_elevation = 0;
	while (i < size)
	{
		if (tmp[i].x < lim_coord.min_x)
			lim_coord.min_x = tmp[i].x;
		if (tmp[i].y < lim_coord.min_y)
			lim_coord.min_y = tmp[i].y;
		if (tmp[i].x > lim_coord.max_x)
			lim_coord.max_x = tmp[i].x;
		if (tmp[i].y > lim_coord.max_y)
			lim_coord.max_y = tmp[i].y;
		if (tmp[i].z < max_dims.min_elevation)
			max_dims.min_elevation = tmp[i].z;
		if (tmp[i].z > max_dims.max_elevation)
			max_dims.max_elevation = tmp[i].z;
		i++;
	}
	printf("min_x = %d | max_x = %d\n", lim_coord.min_x, lim_coord.max_x);
	printf("min_y = %d | max_y = %d\n", lim_coord.min_y, lim_coord.max_y);
	max_dims.width = ft_abs_value(lim_coord.max_x - lim_coord.min_x);
	max_dims.height = ft_abs_value(lim_coord.max_y - lim_coord.min_y);
	return (max_dims);
}

static float	ft_scale_to_fit(t_dim max_dims, t_screen screen, float occ_screen)
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
	return (scale_factor);;
}

static void	ft_to_isometric(t_coord *coord, t_dim max_dims, t_screen screen, unsigned int size)
{
	unsigned int	i;
	float			u;
	float			u_o;
	float			v;
	float			v_o;
	float			angle;
	float			occ_screen;
	int				s;

	i = 0;
	angle = 30.0;
	occ_screen = 0.5;
	s = ft_scale_to_fit(max_dims, screen, occ_screen);
	u_o = (max_dims.width - max_dims.height) * cos(ft_degree_to_rad(angle)) * s / 2; 
	v_o = (max_dims.width + max_dims.height) * sin(ft_degree_to_rad(angle)) * s / 2;
	while (i < size)
	{
		u = ((coord[i].x  - coord[i].y) * cos(ft_degree_to_rad(angle)) * s) - u_o + screen.width / 2; 
		v = ((coord[i].x  + coord[i].y ) * sin(ft_degree_to_rad(angle)) * s - coord[i].z) - v_o + screen.height / 2;
		coord[i].x = (int)u;
		coord[i].y = (int)v;
		i++;
	}
}

void	ft_scale_and_center(t_coord *coord, t_screen screen, unsigned int size)
{
	t_dim			max_dims;

	max_dims = ft_get_max_dims(coord, size);
	ft_to_isometric(coord, max_dims, screen, size);
}
