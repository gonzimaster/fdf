/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:22:22 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/23 11:19:25 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks_bonus.h"
#include "graphics_bonus.h"
#include "camera_bonus.h"
#include "scale_coord_bonus.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_destroy_and_free(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->map_data->coord);
	free(vars->map_data->tr_coord);
	exit(0);
}

static void	ft_reload_map(t_vars *vars)
{
	ft_to_isometric(*vars->map_data, vars->screen, vars->view);
	ft_clear_image(vars);
	ft_print_image(vars->img, *(vars->map_data), vars->screen);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

static int	ft_key_router(int key, t_vars *vars)
{
	if (key == ESC_KEY)
		ft_destroy_and_free(vars);
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		ft_translate_and_put(vars, key);
	else if (key == UP_KEY)
	{
		vars->view.angle *= 1.02;
		ft_reload_map(vars);
	}
	else if (key == DOWN_KEY)
	{
		vars->view.angle *= 0.98;
		ft_reload_map(vars);
	}
	else if (key == RIGHT_KEY || key == LEFT_KEY)
		ft_rotate_and_put(vars, key);
	return (0);
}

static int	ft_mouse_router(int key, int x, int y, t_vars *vars)
{
	if (key == ZOOM_IN_KEY)
	{
		vars->view.scale *= 1.1;
		ft_reload_map(vars);
	}
	else if (key == ZOOM_OUT_KEY)
	{
		vars->view.scale *= 0.9;
		ft_reload_map(vars);
	}
	(void)x;
	(void)y;
	return (0);
}

void	ft_loop_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, ft_key_router, vars);
	mlx_mouse_hook(vars->win, ft_mouse_router, vars);
	mlx_loop(vars->mlx);
}
