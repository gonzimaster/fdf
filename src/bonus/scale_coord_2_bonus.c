/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 08:48:55 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/27 09:25:15 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale_coord_bonus.h"
#include <math.h>

void	ft_initialize_dim(t_dim *dim, t_coord *coord)
{
	dim->x.min = coord[0].x;
	dim->x.max = coord[0].x;
	dim->y.min = coord[0].y;
	dim->y.max = coord[0].y;
	dim->z.min = coord[0].z;
	dim->z.max = coord[0].z;
	dim->width = 0;
	dim->height = 0;
	dim->altitude = 0
}

/*
 * z_scale is a function of the inverse screen occupancy ratio 
 * (screen / occ_screen) times the logarithm of the altitude. Therefore, z 
 * is more exagerated for smaller altitudes and less exagerated for larger
 * altitudes. 
 */

void	ft_initialize_view(t_dim max_dims, t_screen screen, t_view *view)
{
	view->angle = 35.0;
	view->window_occ = 0.5;
	view->scale = ft_scale_to_fit(max_dims, screen, view->window_occ);
	view->z_scale = (screen.width * screen.height) / (max_dims.width
			* max_dims.height * pow(view->scale, 2)
			* log(max_dims.altitude + 2));
	view->rotation = 0;
	view->x_trans = 0;
	view->y_trans = 0;
}
