/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_coord_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 08:48:55 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/18 12:19:08 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scale_coord.h"
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
}

void	ft_initialize_view(t_dim max_dims, t_screen screen, t_view *view)
{
	view->angle = 40.0;
	view->window_occ = 0.5;
	view->scale = ft_scale_to_fit(max_dims, screen, view->window_occ);
	view->z_scale = (screen.width * screen.height) / (max_dims.width
			* max_dims.height * pow(view->scale, 2) * log(max_dims.altitude));
}
