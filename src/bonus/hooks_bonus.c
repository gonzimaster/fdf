/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:22:22 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 13:49:36 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks_bonus.h"
#include "graphics_bonus.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_translate_map(t_vars *vars, int key)
{
	unsigned int	i;

	i = 0;
	while (i < vars->map_data->size.map)
	{
		if (key == MAC_RIGHT_KEY || key == LINUX_RIGHT_KEY)
			(vars->map_data->tr_coord[i].x) -= 3;
		if (key == MAC_LEFT_KEY || key == LINUX_LEFT_KEY)
			(vars->map_data->tr_coord[i].x) += 3;
		if (key == MAC_UP_KEY || key == LINUX_UP_KEY)
			(vars->map_data->tr_coord[i].y) += 3;
		if (key == MAC_DOWN_KEY || key == LINUX_DOWN_KEY)
			(vars->map_data->tr_coord[i].y) -= 3;
		i++;
	}
}

static void	ft_clear_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	vars->img->img = mlx_new_image(vars->mlx, vars->screen.width, vars->screen.height);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel,
		&vars->img->line_length, &vars->img->endian);
}

static int	ft_key_router(int key, t_vars *vars)
{	
	#if __APPLE__
	if (key == MAC_ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map_data->coord);
		free(vars->map_data->tr_coord);
		exit(0);
	}
	if (key == MAC_RIGHT_KEY || key == MAC_LEFT_KEY || key == MAC_DOWN_KEY || key == MAC_UP_KEY)
	{
		ft_clear_image(vars);
		ft_translate_map(vars, key);
		ft_print_image(vars->img, *(vars->map_data), vars->screen);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	}
	#elif __linux__
	if (key == LINUX_ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map_data->coord);
		free(vars->map_data->tr_coord);
		exit(0);
	}
	if (key == LINUX_RIGHT_KEY || key == LINUX_LEFT_KEY || key == LINUX_DOWN_KEY || key == LINUX_UP_KEY)
	{
		ft_clear_image(vars);
		ft_translate_map(vars, key);
		ft_print_image(vars->img, *(vars->map_data), vars->screen);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	}
	#endif	
	return (0);
}

void	ft_loop_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, ft_key_router, vars);
	mlx_loop(vars->mlx);
}
