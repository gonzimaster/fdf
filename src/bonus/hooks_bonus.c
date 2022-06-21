/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:22:22 by ogonzale          #+#    #+#             */
/*   Updated: 2022/06/21 12:05:06 by ogonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks.h"
#include <stdlib.h>

static int	ft_key_router(int key, t_vars *vars)
{
	if (key == LINUX_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map_data->coord);
		exit(0);
	}
	return (0);
}

void	ft_loop_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, ft_key_router, vars);
	mlx_loop(vars->mlx);
}
