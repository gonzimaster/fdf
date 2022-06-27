/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:22:22 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/27 09:37:40 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks_bonus.h"
#include "camera_bonus.h"
#include "scale_coord_bonus.h"
#include "utils_bonus.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_reload_map(t_vars *vars)
{
	ft_to_isometric(*vars->map_data, vars->screen, vars->view);
	ft_rotate_to_angle(vars);
	ft_translate_to_pos(vars);
	ft_clear_image(vars);
	ft_print_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	ft_print_menu(vars);
}

static int	ft_key_router(int key, t_vars *vars)
{
	if (key == ESC_KEY)
		ft_destroy_window(vars);
	else if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		ft_save_trans(vars, key);
	else if (key == UP_KEY)
		vars->view.angle += 1;
	else if (key == DOWN_KEY)
		vars->view.angle -= 1;
	else if (key == RIGHT_KEY || key == LEFT_KEY)
		ft_save_rotation(vars, key);
	else if (key == X_KEY)
		vars->view.z_scale += 0.25;
	else if (key == Z_KEY)
		vars->view.z_scale -= 0.25;
	else if (key == P_KEY)
	{
		vars->view.angle = 0;
		vars->view.rotation = 0;
		vars->view.z_scale = 5;
	}
	else if (key == I_KEY || key == R_KEY)
		ft_initialize_view(vars->map_data->max_dims, vars->screen,
			&vars->view);
	ft_reload_map(vars);
	return (0);
}

static int	ft_mouse_router(int key, int x, int y, t_vars *vars)
{
	if (key == ZOOM_IN_KEY)
		vars->view.scale *= 1.1;
	else if (key == ZOOM_OUT_KEY)
		vars->view.scale *= 0.9;
	ft_reload_map(vars);
	(void)x;
	(void)y;
	return (0);
}

void	ft_loop_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, ft_key_router, vars);
	mlx_mouse_hook(vars->win, ft_mouse_router, vars);
	mlx_hook(vars->win, 17, 0, ft_destroy_window, vars);
	mlx_loop(vars->mlx);
}
