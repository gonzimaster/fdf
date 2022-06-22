/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:22:22 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/22 12:53:47 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks_bonus.h"
#include "graphics_bonus.h"
#include <stdlib.h>
#include <stdio.h>

static void	ft_translate_map_left(t_vars *vars)
{
	unsigned int	i;

	i = 0;
	while (i < vars->map_data->size.map)
	{
		(vars->map_data->tr_coord[i].x)--;
		i++;
	}
}

static int	ft_key_router(int key, t_vars *vars)
{
	if (key == LINUX_ESC || key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map_data->coord);
		free(vars->map_data->tr_coord);
		exit(0);
	}
	if (key == RIGHT || key == 2)
	{
		mlx_destroy_image(vars->mlx, vars->img->img);
		vars->img->img = mlx_new_image(vars->mlx, vars->screen.width, vars->screen.height);
		vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel,
			&vars->img->line_length, &vars->img->endian);
		ft_translate_map_left(vars);
		ft_print_image(vars->img, *(vars->map_data), vars->screen);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	}
		
	return (0);
}

void	ft_loop_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, ft_key_router, vars);
	mlx_loop(vars->mlx);
}
