/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:51:52 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/24 11:54:05 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_bonus.h"
#include "camera_bonus.h"
#include "mlx.h"
#include "utils_bonus.h"
#include <math.h>

void	ft_translate_to_pos(t_vars *vars)
{
	unsigned int	i;
	
	i = 0;
	while (i < vars->map_data->size.map)
	{
		vars->map_data->tr_coord[i].x += vars->view.x_trans;
		vars->map_data->tr_coord[i].y += vars->view.y_trans;
		i++;
	}
}

void	ft_rotate_to_angle(t_vars *vars)
{
	unsigned int	i;
	int				rot;
	int				x;
	int				y;

	i = 0;
	rot = vars->view.rotation;
	while (i < vars->map_data->size.map)
	{
		x = vars->map_data->tr_coord[i].x;
		y = vars->map_data->tr_coord[i].y;
		vars->map_data->tr_coord[i].x = (x - vars->screen.width / 2)
			* cos(ft_degree_to_rad(rot)) + (y - vars->screen.height / 2)
			* sin(ft_degree_to_rad(rot)) + vars->screen.width / 2;
		vars->map_data->tr_coord[i].y = -(x - vars->screen.width / 2)
			* sin(ft_degree_to_rad(rot)) + (y - vars->screen.height / 2)
			* cos(ft_degree_to_rad(rot)) + vars->screen.height / 2;
		i++;
	}
}

void	ft_save_trans(t_vars *vars, int key)
{
	if (key == D_KEY)
		vars->view.x_trans -= 1;
	else if (key == A_KEY)
		vars->view.x_trans += 1;
	else if (key == W_KEY)
		vars->view.y_trans -= 1;
	else if (key == S_KEY)
		vars->view.y_trans += 1;
}

void ft_save_rotation(t_vars *vars, int key)
{
	if (key == RIGHT_KEY)
		vars->view.rotation += 1;
	else
		vars->view.rotation -= 1;
}
