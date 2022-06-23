/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:51:52 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/23 18:56:45 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks_bonus.h"
#include "camera_bonus.h"
#include "mlx.h"
#include "utils_bonus.h"
#include <math.h>

static void	ft_save_trans(t_vars *vars, int key, int trans)
{
	if (key == D_KEY)
		vars->view.x_trans -= trans;
	else if (key == A_KEY)
		vars->view.x_trans += trans;
	else if (key == W_KEY)
		vars->view.y_trans -= trans;
	else if (key == S_KEY)
		vars->view.y_trans += trans;
}

static void	ft_translate_map(t_vars *vars, int key)
{
	unsigned int	i;
	int				trans;

	trans = 3;
	ft_save_trans(vars, key, trans);
	i = 0;
	while (i < vars->map_data->size.map)
	{
		if (key == D_KEY)
			vars->map_data->tr_coord[i].x -= trans;
		else if (key == A_KEY)
			vars->map_data->tr_coord[i].x += trans;
		else if (key == W_KEY)
			vars->map_data->tr_coord[i].y += trans;
		else if (key == S_KEY)
			vars->map_data->tr_coord[i].y -= trans;
		i++;
	}
}

static void ft_rotate_map(t_vars *vars, int key)
{
	unsigned int	i;
	int				rot;
	int				x;
	int				y;

	if (key == RIGHT_KEY)
		rot = 1;
	else
		rot = -1;
	vars->view.rotation += rot;
	i = 0;
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

void	ft_translate_and_put(t_vars *vars, int key)
{
	ft_clear_image(vars);
	ft_translate_map(vars, key);
	ft_print_image(vars->img, *(vars->map_data), vars->screen);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	ft_rotate_and_put(t_vars *vars, int key)
{
	ft_clear_image(vars);
	ft_rotate_map(vars, key);
	ft_print_image(vars->img, *(vars->map_data), vars->screen);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

